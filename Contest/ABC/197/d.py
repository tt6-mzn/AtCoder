import sys
sys.stdin = open('input.txt', 'r', encoding='utf-8')


import numpy as np

def rotation_o(u, t, deg=False):

    # 度数単位の角度をラジアンに変換
    if deg == True:
        t = np.deg2rad(t)

    # 回転行列
    R = np.array([[np.cos(t), -np.sin(t)],
                  [np.sin(t),  np.cos(t)]])

    return  np.dot(R, u)

def main():
    n = int(input())
    x, y = map(int, input().split())
    x_, y_ = map(int, input().split())
    vx = ((x - x_) / 2, (y - y_) / 2)
    rot_vx = rotation_o(vx, (2 * np.pi) / n)
    ans_x, ans_y = rot_vx[0] + ((x + x_) / 2), rot_vx[1] + ((y + y_) / 2)
    print("{:.10f} {:.10f}".format(ans_x, ans_y))

main()