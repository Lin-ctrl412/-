function [dose, Cmax_pred, t_profile] = recommend_dose(age, BMI, skin_thick, patch_area)
    % 角质层和真皮层厚度估算
    L_SC = 0.002; % 20 μm = 0.002 cm
    L_D = skin_thick - L_SC; % cm
    if L_D < 0.06 % 真皮层最小0.6mm
        L_D = 0.06;
    end
    % 其他参数（可根据文献或拟合数据调整）
    D_SC = 1e-8; % cm^2/s
    D_D = 1e-7; % cm^2/s
    k_elim = 0.1/3600; % 1/s
    k_abs = 0.05/3600; % 1/s
    S = patch_area; % cm^2
    C_patch = 100; % μg/cm^2
    % 模拟
    [Cmax_pred, t_profile] = simulate_transdermal(D_SC, D_D, L_SC, L_D, k_elim, k_abs, S, C_patch);
    % 剂量推荐
    if Cmax_pred > 15
        dose = 15 / Cmax_pred * C_patch;
    else
        dose = C_patch;
    end
end