function dCdt = pde_rhs(~, C, D_SC, D_D, L_SC, L_D, k_elim, k_abs, S, C_patch, dx, Nx)
    dCdt = zeros(Nx+1,1);
    idx_SC = round(L_SC/(L_SC+L_D)*Nx);
    idx_SC = max(2, min(idx_SC, Nx-1)); % 保证idx_SC在[2, Nx-1]之间

    % 角质层
    if idx_SC > 2
        for i = 2:idx_SC-1
            if i-1 >= 1 && i+1 <= Nx
                dCdt(i) = D_SC*(C(i+1)-2*C(i)+C(i-1))/dx^2;
            end
        end
    end

    % 真皮层
    if idx_SC < Nx-1
        for i = idx_SC:Nx-1
            if i-1 >= 1 && i+1 <= Nx
                dCdt(i) = D_D*(C(i+1)-2*C(i)+C(i-1))/dx^2;
            end
        end
    end

    % 边界条件
    dCdt(1) = D_SC*(C(2)-C(1))/dx^2 + (C_patch - C(1))/dx^2; % 贴片界面

    % 层间连续性和通量
    if idx_SC-1 >= 1 && idx_SC+1 <= Nx
        dCdt(idx_SC) = D_SC*(C(idx_SC-1)-C(idx_SC))/dx^2 + D_D*(C(idx_SC+1)-C(idx_SC))/dx^2;
    end

    % 真皮-血液界面
    dCdt(Nx) = D_D*(C(Nx-1)-C(Nx))/dx^2 - k_abs*C(Nx);

    % 血药浓度
    dCdt(end) = k_abs*S*C(Nx) - k_elim*C(end);
end