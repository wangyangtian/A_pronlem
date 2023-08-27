import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 读取数据
data = pd.read_excel('A_problem\data.xlsx', usecols=[1])
data_column = data.iloc[:, 0]

# 计算样本均值和标准差
mu = np.mean(data_column)
sigma = np.std(data_column)

# 生成标准正态分布的随机样本
standard_normal_samples = np.random.normal(0, 1, len(data_column))

# 对数据和标准正态分布样本进行排序
sorted_data = np.sort(data_column)
sorted_standard_normal_samples = np.sort(standard_normal_samples)

# 绘制p-p图
plt.figure(figsize=(8, 6))
plt.scatter(stats.norm.cdf(sorted_data, loc=mu, scale=sigma),
            stats.norm.cdf(sorted_standard_normal_samples), color='blue')
plt.plot([0, 1], [0, 1], color='red', linestyle='--')
plt.title('P-P Plot')
plt.xlabel('实际分位数')
plt.ylabel('理论分位数')
plt.grid()

# 显示图形
plt.show()

# 绘制q-q图
plt.figure(figsize=(8, 6))
plt.scatter(sorted_data,
            stats.norm.ppf(np.arange(1, len(data_column) + 1) / (len(data_column) + 1), loc=mu, scale=sigma),
            color='blue')
plt.plot([min(data_column), max(data_column)], [min(data_column), max(data_column)], color='red', linestyle='--')
plt.title('Q-Q Plot')
plt.xlabel('数据')
plt.ylabel('理论分位数')
plt.grid()

# 显示图形
plt.show()
