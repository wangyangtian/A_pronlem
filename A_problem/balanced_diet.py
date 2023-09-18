import pandas as pd
import numpy as np

# 加载数据
df = pd.read_excel('A_problem\饮食结构特征.xlsx')

# 初始化'谷薯类'列为0
df['谷薯类'] = 0
df['蔬菜水果'] = 0
df['奶类'] =0
df['肉蛋类'] = 0
df['豆类'] = 0

# 检查'大米'、'小麦粉'、'薯类'列，如果有一个不为空，则将'谷薯类'列对应的值设为1
df.loc[(~df['大米(天)'].isnull()) | (~df['小麦面粉(天)'].isnull()) | (~df['薯类(天)'].isnull()), '谷薯类'] = 1
# 打印'谷薯类'列为1的数量
print('每天吃谷薯类：',df['谷薯类'].sum())

df.loc[~((df['蔬菜(天)'].isnull() & df['海草(天)'].isnull()) | df['水果(天)'].isnull()), '蔬菜水果'] = 1
print('每天吃蔬菜水果：',df['蔬菜水果'].sum())

df.loc[(~df['鲜奶(天)'].isnull()) | (~df['奶粉(天)'].isnull()) | (~df['酸奶(天)'].isnull()), '奶类'] = 1
print('每天吃奶类：',df['奶类'].sum())

df.loc[~(df['猪肉(天)'].isnull() & df['牛羊肉(天)'].isnull() & df['内脏(天)'].isnull() & df['禽肉(天)'].isnull() | df['水产(天)'].isnull()), '肉蛋类'] = 1
print('每天吃肉蛋类：',df['肉蛋类'].sum())


df.loc[~(df['豆腐(天)'].isnull() & df['豆腐丝(天)'].isnull() & df['豆浆(天)'].isnull() & df['干豆(天)'].isnull()), '豆类'] = 1
print('每天吃豆类：',df['豆类'].sum())

df.to_excel('A_problem/饮食结构特征.xlsx', index=False)
