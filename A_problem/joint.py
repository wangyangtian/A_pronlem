import pandas as pd

# 读取两个Excel文件中的数据
file1_path = 'A_problem\\处理数据.xlsx'
file2_path = 'A_problem\\综合得分与主成分值.xlsx'

df1 = pd.read_excel(file1_path)
df2 = pd.read_excel(file2_path)

# 根据索引ID进行合并
merged_df = pd.merge(df1, df2, on='ID')

# 保存合并后的数据到新的Excel文件
merged_file_path = 'A_problem\\合并数据.xlsx'
merged_df.to_excel(merged_file_path, index=False)

print("数据已成功合并并保存到新的Excel文件中:", merged_file_path)
