import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 导入Excel文件
file_path = 'A_problem\data.xlsx'
df = pd.read_excel(file_path)

# 统计“不吃早餐”列的空值与有值的数量
missing_values = df['不吃早餐'].isnull().sum()
non_missing_values = df['不吃早餐'].notnull().sum()

# 绘制空值与有值的数量的饼状图
labels = ['吃早饭', '不吃早饭']
values = [missing_values, non_missing_values]
plt.figure(figsize=(6, 6))
plt.title('是否吃早饭的人群占比')
plt.pie(values, labels=labels, autopct='%1.2f%%', startangle=140, shadow=True,)

plt.legend()
plt.show()

# 统计有值的数据中各值出现的频率
value_counts = df['不吃早餐'].value_counts()

# 绘制各值出现频率的饼状图
plt.figure(figsize=(8, 8))
plt.pie(value_counts, labels=value_counts.index, autopct='%1.2f%%', startangle=140)
plt.title('不吃早饭天数占比')
plt.show()
