import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 读取Excel文件，假设数据在名为'Sheet1'的工作表中
data = pd.read_excel('A_problem\data.xlsx', sheet_name='data')

# 统计第EM列数据中1和2出现的次数
counts = data['是否吃新鲜蔬菜'].value_counts()

# 将索引值为1的标签替换为"吃"，索引值为2的标签替换为"不吃"
labels = counts.index.map({1: '吃', 2: '不吃'})

# 绘制饼状图
plt.figure(figsize=(6, 6))
plt.pie(counts, labels=labels, autopct='%.2f%%', startangle=140, colors=['aquamarine', 'dodgerblue'])
plt.title('是否吃蔬菜')
plt.show()