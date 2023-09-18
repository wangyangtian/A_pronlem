import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 输入数据
categories = ['谷薯类', '蔬菜水果', '奶类', '肉蛋类', '豆类']
values = [7719, 4468, 1303, 1136, 896]
fig, ax = plt.subplots(figsize=(8, 6))
# 创建横向条形图
plt.barh(categories, values, color='skyblue')

# 设置图表标题和坐标轴标签
plt.xlabel('人数')
plt.ylabel('膳食类别')

# 为每个条形添加数值标签
for i, value in enumerate(values):
    plt.text(value, i, str(value), ha='left', va='center')

# 显示图表
plt.show()