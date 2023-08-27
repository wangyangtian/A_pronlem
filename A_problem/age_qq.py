import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.graphics.gofplots import qqplot
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 读取 Excel 文件
data = pd.read_excel('A_problem\缺餐.xlsx', sheet_name='Sheet1', usecols=['年龄'])

# 获取年龄数据
age_data = data['年龄']
# 绘制 Q-Q 图
fig, ax = plt.subplots(figsize=(8, 6))
qqplot(age_data, line='s', ax=ax, markerfacecolor='lightblue')

# 添加标题和标签
ax.set_xlabel('理论分位数',size=15)
ax.set_ylabel('样本分位数',size=15)

# 显示图形
plt.show()