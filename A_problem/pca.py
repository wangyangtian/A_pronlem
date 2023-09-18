import pandas as pd
import numpy as np
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

# 读取Excel文件
data = pd.read_excel('A_problem\\处理数据.xlsx')
 
# 设置'ID'列为索引
data.set_index('ID', inplace=True)

# 选择需要进行主成分分析的列
columns_to_analyze = ['谷薯类日均摄入量', '蔬菜水果日均摄入量', '畜禽鱼蛋日均摄入量', '奶类日均摄入量', '豆类日均摄入量']

# 提取所选列的数据
data_to_analyze = data[columns_to_analyze]

# 数据标准化
scaler = StandardScaler()
data_scaled = scaler.fit_transform(data_to_analyze)

# 计算主成分
pca = PCA()
pca.fit(data_scaled)

# 获取KMO检验值
def pca_kmo(data):
    corr_mtx = np.corrcoef(data, rowvar=False)
    inv_corr_mtx = np.linalg.inv(corr_mtx)
    n_vars = data.shape[1]
    sum_corr_inv = np.sum(inv_corr_mtx)
    sum_corr_inv_diag = np.trace(inv_corr_mtx)
    kmo_value = sum_corr_inv / (sum_corr_inv + sum_corr_inv_diag)
    return kmo_value

# 调用PCA_KMO函数计算KMO检验值
kmo_value = pca_kmo(data_scaled)
print("KMO检验值:", kmo_value)

# 绘制碎石图
plt.figure(figsize=(10, 6))
plt.plot(np.cumsum(pca.explained_variance_ratio_))
plt.xlabel('Number of Components')
plt.ylabel('Cumulative Explained Variance')
plt.title('Scree Plot')
plt.show()

# 计算综合得分
data_pca = pca.transform(data_scaled)[:, :2]  # 取前两个主成分的分数
data['综合得分'] = np.sum(data_pca, axis=1)
data.to_excel('A_problem\\处理数据_with_scores.xlsx')
