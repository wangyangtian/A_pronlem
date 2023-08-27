import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import LinearSegmentedColormap

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

data = [[11, 46], [2882, 2266], [667, 850], [815, 297]]
x_labels = ['女', '男']
y_labels = ['不参加', '中度', '轻度', '重度']
heatmap_data = np.array(data)

fig, ax = plt.subplots(figsize=(8, 6))

# 定义自定义的颜色映射
colors = [(0.9, 0.9, 0.9), (0.5, 0.5, 0.8), (0.6, 0.6, 0.9), (0.7, 0.7, 1.0), (0.5, 0.4, 0.9), (0.4, 0.3, 0.8)]
cmap = LinearSegmentedColormap.from_list('custom_colormap', colors)

# 绘制热力图
im = ax.imshow(heatmap_data, cmap=cmap)

# 添加颜色条
cbar = ax.figure.colorbar(im, ax=ax)

# 设置标签
ax.set_xticks(np.arange(len(x_labels)))
ax.set_yticks(np.arange(len(y_labels)))
ax.set_xticklabels(x_labels)
ax.set_yticklabels(y_labels)

# 在热力图中显示数值
for i in range(len(y_labels)):
    for j in range(len(x_labels)):
        ax.text(j, i, heatmap_data[i, j], ha='center', va='center', color='k')

# 旋转x轴标签
plt.setp(ax.get_xticklabels(), rotation=45, ha='right', rotation_mode='anchor')

# 显示图形
plt.show()