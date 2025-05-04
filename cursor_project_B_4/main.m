% main.m
% 读取Excel数据
data = readmatrix('clinical_trial_data.xlsx');

% 用列索引方式提取数据
age         = data(:,2);    % 第2列：年龄
BMI         = data(:,3);    % 第3列：BMI
skin_thick  = data(:,4)/10; % 第4列：皮肤厚度，mm转cm

n = size(data,1);
dose = zeros(n,1);
Cmax_pred = zeros(n,1);

areas = [5, 10, 15, 20];
for a = 1:length(areas)
    patch_area = areas(a) * ones(n,1);
    for i = 1:n
        [dose(i), Cmax_pred(i), ~] = recommend_dose(age(i), BMI(i), skin_thick(i), patch_area(i));
    end
    % 保存或分析结果
end

% 将结果添加到原数据
result = [data, dose, Cmax_pred];

% 保存结果
writematrix(result, 'clinical_trial_results.xlsx');

% 可视化所有受试者的Cmax分布
figure;
histogram(Cmax_pred, 20);
xlabel('预测Cmax (ng/mL)');
ylabel('受试者数');
title('所有受试者的血药峰值分布');