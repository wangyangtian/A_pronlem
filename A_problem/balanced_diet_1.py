import pandas as pd

# 导入Excel文件
df = pd.read_excel('A_problem/饮食结构特征.xlsx')

# 创建'平衡膳食'列并初始化为0
df['平衡膳食'] = 0

# 检查'谷薯类'、'蔬菜水果'、'奶类'、'肉蛋类'、'豆类'这五列，如果全不为0，将'平衡膳食'列对应的值设为1
df.loc[(df['谷薯类'] != 0) & (df['蔬菜水果'] != 0) & (df['奶类'] != 0) & (df['肉蛋类'] != 0) & (df['豆类'] != 0), '平衡膳食'] = 1

# 统计'平衡膳食'列为1的数量
count = df['平衡膳食'].sum()

# 输出结果
print("平衡膳食的人数:", count)