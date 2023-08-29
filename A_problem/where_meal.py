import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

data = [
    [6121, 214, 897, 2669],
    [7101, 289, 1561, 1388],
    [7439, 78, 681, 1351]
]
labels = ['在家吃', '带餐到单位', '单位食堂', '餐馆或街头']
categories = ['早餐', '中餐', '晚餐']
bar_width = 0.2  # 定义每组柱子的宽度
bar_gap = 0.05  # 定义柱体之间的间隙
x = range(len(labels))  # x轴的刻度位置

fig, ax = plt.subplots()

# 自定义一组浅色调配色方案
custom_colors = ['#66c2a5', '#fc8d62', '#8da0cb']
ax.set_prop_cycle('color', custom_colors)

for i, category in enumerate(categories):
    offset = (i - 1) * (bar_width + bar_gap)+bar_width+bar_gap  # 每组数据在x轴上的偏移量
    ax.bar([pos + offset for pos in x], data[i], bar_width, label=category)

ax.set_xticks([pos + bar_width + (len(categories) - 1) * bar_gap / 2 for pos in x])
ax.set_xticklabels(labels)
ax.set_ylabel('每周人次')
ax.legend()

plt.tight_layout()
plt.show()
