import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 导入Excel文件
file_path = 'A_problem\data.xlsx'
sheet_name = 'data'  # 假设数据在名为Sheet1的工作表中
column_name = '食用新鲜蔬菜的频率'

# 读取Excel文件
data = pd.read_excel(file_path, sheet_name=sheet_name)

# 提取特定列的数据
column_data = data[column_name]

# 统计各数字出现的次数
value_counts = column_data.value_counts()

# 绘制柱状图
plt.bar(value_counts.index, value_counts.values)
plt.xlabel('每日频次')
plt.ylabel('人数')
plt.title('食用新鲜蔬菜的频率分布')
plt.xticks(rotation=45)
plt.show()


# plt.subplot(1, 2, 2)
# plt.pie(value_counts, labels=value_counts.index, autopct='%1.1f%%', startangle=140)
# plt.axis('equal')
# plt.title('食用新鲜蔬菜的频率比例')

plt.tight_layout()

# 显示图形
plt.show()
