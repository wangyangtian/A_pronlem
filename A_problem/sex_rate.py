import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 数据
labels = ['男性', '女性']
sizes = [3445, 4360]
colors = ['lightblue', 'lightcoral']
explode = (0.1, 0)  # 突出显示第一个部分

# 创建饼状图
fig, ax = plt.subplots()
ax.pie(sizes, explode=explode, labels=labels, colors=colors, autopct='%1.1f%%', shadow=True, startangle=140)
ax.axis('equal')  # 使饼图保持圆形

# 添加标题
plt.title('性别分布')

# 显示图形
plt.show()
