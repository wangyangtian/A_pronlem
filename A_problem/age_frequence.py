import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm
from matplotlib.patches import Polygon
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 读取数据
data = pd.read_excel('A_problem\缺餐.xlsx', usecols=[1])['年龄'].values

# 设置组距和直方图的边界
bin_width = 10
bins = np.arange(data.min(), data.max() + bin_width, bin_width)

# 创建主轴和右侧y轴
fig, ax1 = plt.subplots(figsize=(10, 6))
ax2 = ax1.twinx()

# 绘制直方图
n, bins, patches = ax1.hist(data, bins=bins, edgecolor='k', alpha=0.7)

# 计算正态分布拟合的参数
mu, sigma = norm.fit(data)

# 绘制正态分布拟合线
xmin, xmax = ax1.get_xlim()
x = np.linspace(xmin, xmax, 100)
p = norm.pdf(x, mu, sigma)
ax2.plot(x, p, 'r', linewidth=2)

ax1.set_xlabel('年龄')
ax1.set_ylabel('频数', color='b')
ax2.set_ylabel('频率', color='r')

# 在图上添加拟合参数信息
ax1.text(0.75, 0.95, f'$\mu={mu:.2f}$\n$\sigma={sigma:.2f}$', transform=ax1.transAxes, fontsize=12,
         verticalalignment='top')

# 添加阴影区域表示拟合的区间
verts = [(mu - 2 * sigma, 0), (mu - 2 * sigma, ax1.get_ylim()[1]), (mu + 2 * sigma, ax1.get_ylim()[1]),
         (mu + 2 * sigma, 0)]
poly = Polygon(verts, facecolor='0.9', edgecolor='0.5', alpha=0.5)
ax1.add_patch(poly)

# 设置右侧y轴的颜色
ax2.yaxis.label.set_color('r')
ax2.tick_params(axis='y', colors='r')

plt.grid()
plt.show()
