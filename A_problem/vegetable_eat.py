import pandas as pd
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
file_path = 'A_problem\\饮食结构特征.xlsx'
data = pd.read_excel(file_path)

bins = [0, 300, 500, 1000, 1500]
labels = ['0-300', '301-500', '501-1000', '1001-1500']

data['食用量区间'] = pd.cut(data['每日蔬菜食用量'], bins=bins, labels=labels, right=False)
statistics = data['食用量区间'].value_counts().sort_index()

plt.figure(figsize=(10, 6))
bars = plt.barh(statistics.index, statistics.values, color='skyblue')


plt.xlabel('蔬菜食用量区间')
plt.ylabel('人数')
plt.xticks(rotation=45)
plt.tight_layout()

plt.show()