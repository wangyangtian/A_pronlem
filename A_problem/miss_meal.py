import pandas as pd
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 读取Excel文件
file_path = 'A_problem\\缺餐.xlsx'
data = pd.read_excel(file_path)

# 获取'缺餐'列中非空值
non_empty_values = data['缺餐(处理)'].dropna()

# 统计每个值的出现次数
value_counts = non_empty_values.value_counts()

# 绘制条形图
plt.figure(figsize=(10, 6))
bars = plt.bar(value_counts.index, value_counts.values, color='skyblue')

# 在柱子顶部显示具体频数
for bar in bars:
    plt.text(bar.get_x() + bar.get_width() / 2, bar.get_height(), str(bar.get_height()), 
             va='bottom', ha='center', fontsize=10)

plt.xlabel('周缺餐次数',size=17)
plt.ylabel('人数',size=17)
plt.xticks(rotation=45, ha='right', ticks=value_counts.index)  # 设置x轴刻度
plt.tight_layout()

# 显示图像
plt.show()
