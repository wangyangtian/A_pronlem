import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 创建图像
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_title("3D旋转示例")

# 设置x、y、z轴坐标范围
ax.set_xlim([-1.2, 1.2])
ax.set_ylim([-1.2, 1.2])
ax.set_zlim([-1.2, 1.2])

# 该矩阵每一列表示为3D空间中的一个坐标点
# 这些坐标点用来绘制一个原点以及可旋转的坐标轴
oxyzuvw = np.array([[0, -1, 0, 0, 2, 0, 0],
                    [0, 0, -1, 0, 0, 2, 0],
                    [0, 0, 0, -1, 0, 0, 2]])

# 俯仰角、偏航角、滚动角
phi = 0.8
theta = 0.0
psi = 1.2

# 计算旋转变换后的坐标序列
def calculate_rotation(phi, theta, psi):
    Ryz = np.array([[1, 0, 0],
                    [0, np.cos(psi), -np.sin(psi)],
                    [0, np.sin(psi), np.cos(psi)]])
    
    Rzx = np.array([[np.cos(theta), 0, np.sin(theta)],
                    [0, 1, 0],
                    [-np.sin(theta), 0, np.cos(theta)]])
    
    Rxy = np.array([[np.cos(phi), -np.sin(phi), 0],
                    [np.sin(phi), np.cos(phi), 0],
                    [0, 0, 1]])
    
    M = np.dot(np.dot(Ryz, Rzx), Rxy)
    new_oxyzuvw = np.dot(M, oxyzuvw)
    
    return new_oxyzuvw

# 初始化图形元素
o_x, o_y, o_z = [calculate_rotation(phi, theta, psi)[i, 0] for i in range(3)]
x, y, z = calculate_rotation(phi, theta, psi)[:, 1:4]
u, v, w = calculate_rotation(phi, theta, psi)[:, 4:]

# 绘制坐标原点
ax.scatter(o_x, o_y, o_z, c='red', s=10)

# 绘制x、y、z三个坐标轴
ax.quiver(o_x, o_y, o_z, x, y, z, length=0.2, color=['blue', 'red', 'green'], label=['X', 'Y', 'Z'])

# 添加坐标轴文本标识
ax.text(x[0], y[0], z[0], 'X', color='blue')
ax.text(x[1], y[1], z[1], 'Y', color='red')
ax.text(x[2], y[2], z[2], 'Z', color='green')

# 创建动画
framerate = 30
timestamps = np.concatenate((np.arange(-1/3*np.pi, 1/3*np.pi, 1/framerate), 
                             np.arange(1/3*np.pi, -1/3*np.pi, -1/framerate)))

def update(frame):
    global phi, theta, psi
    phi = frame
    theta = frame
    psi = frame
    
    new_oxyzuvw = calculate_rotation(phi, theta, psi)
    o_x, o_y, o_z = new_oxyzuvw[:, 0]
    x, y, z = new_oxyzuvw[:, 1:4]
    
    ax.clear()
    ax.set_title("3D旋转示例")
    ax.set_xlim([-1.2, 1.2])
    ax.set_ylim([-1.2, 1.2])
    ax.set_zlim([-1.2, 1.2])
    
    ax.scatter(o_x, o_y, o_z, c='red', s=10)
    ax.quiver(o_x, o_y, o_z, x, y, z, length=0.2, color=['blue', 'red', 'green'], label=['X', 'Y', 'Z'])
    ax.text(x[0], y[0], z[0], 'X', color='blue')
    ax.text(x[1], y[1], z[1], 'Y', color='red')
    ax.text(x[2], y[2], z[2], 'Z', color='green')

ani = FuncAnimation(fig, update, frames=timestamps, repeat=False)
plt.show()
