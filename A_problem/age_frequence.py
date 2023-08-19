import pandas as pd
import matplotlib.pyplot as plt


plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 读取Excel文件
data = pd.read_excel('A_problem\data.xlsx')

# 计算年龄
current_year = 2023
data['年龄'] = current_year - data['出生年']

# 进行正态检验
from scipy.stats import normaltest
statistic, p_value = normaltest(data['年龄'])
if p_value < 0.05:
    print('数据不服从正态分布')
else:
    print('数据服从正态分布')

    
# 绘制频率分布图
plt.hist(data['年龄'], bins=range(0, 100, 2), edgecolor='white', rwidth=2, density=True)
plt.xlabel('年龄')
plt.ylabel('频率')
plt.title('各年龄段的频率分布图')

# 画出拟合线
import numpy as np
from scipy.stats import norm
x = np.linspace(data['年龄'].min(), data['年龄'].max(), 100)
y = norm.pdf(x, data['年龄'].mean(), data['年龄'].std())
plt.plot(x, y, 'r-', label='拟合线')
plt.legend()
plt.show()
