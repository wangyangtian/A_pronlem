import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# 读取 Excel 文件
file_path = 'A_problem\\缺餐.xlsx'
df = pd.read_excel(file_path)

# 提取第二列数据
column_data = df.iloc[:, 1]

# 分组条件
groups = [
    ('[29.0,52.5)', (29.0, 52.5)),
    ('[52.5,76.0)', (52.5, 76.0)),
    ('[76.0,99.5)', (76.0, 99.5)),
    ('[99.5,123.0]', (99.5, 123.0))
]

# 根据分组条件统计频数
freq_counts = {group[0]: ((column_data >= group[1][0]) & (column_data < group[1][1])).sum() for group in groups}

# 设置颜色调色板，选择较淡的颜色
sns.set_palette("pastel")

# 绘制频数分布立体饼状图
plt.figure(figsize=(8, 6))

labels = [group[0] for group in groups]
sizes = list(freq_counts.values())
explode = (0.1, 0, 0, 0)  # 突出显示第一组

plt.pie(sizes, labels=labels, autopct='%1.2f%%', startangle=140, explode=explode, shadow=True, colors=sns.color_palette())

plt.show()
