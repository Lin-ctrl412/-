function [Cmax, t_profile] = simulate_transdermal(D_SC, D_D, L_SC, L_D, k_elim, k_abs, S, C_patch)
    % 空间离散
    Nx = 40;
    x = linspace(0, L_SC+L_D, Nx);
    dx = x(2)-x(1);
    % 时间离散
    tspan = 0:60:48*3600; % 48小时, 单位秒
    % 初始条件
    C0 = zeros(Nx+1,1); % +1 for blood
    % ODE求解
    [T, C] = ode15s(@(t,C) pde_rhs(t, C, D_SC, D_D, L_SC, L_D, k_elim, k_abs, S, C_patch, dx, Nx), tspan, C0);
    Cmax = max(C(:,end)); % 血药峰值
    t_profile = [T, C(:,end)]; % 血药浓度-时间曲线
end