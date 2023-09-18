import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
labels = ['聚类类别_1', '聚类类别_2', '聚类类别_3', '聚类类别_4', '聚类类别_5', '聚类类别_6']
sizes = [1143, 2898, 420, 14902, 686, 43]

# 设置配色方案
colors = ['#FF9999', '#FFCC99', '#FFFF99', '#CCFF99', '#99FFCC', '#99FFFF']

# 绘制饼状图
plt.pie(sizes, labels=labels, colors=colors, autopct='%1.1f%%', startangle=90)

# 添加连接线
plt.gca().set_aspect('equal')
plt.gca().legend(loc='center left', bbox_to_anchor=(1, 0.5))

# 显示图形
plt.show()