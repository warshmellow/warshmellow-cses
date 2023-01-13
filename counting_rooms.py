import sys
sys.setrecursionlimit(10**6)


def dfs(x, y, vis, n, m):
    vis[x][y] = True

    h = [1, -1, 0, 0]
    v = [0, 0, 1, -1]

    for i in range(4):
        dx = x + h[i]
        dy = y + v[i]
        if 0 <= dx and dx < n and 0 <= dy and dy < m and not vis[dx][dy]:
            dfs(dx, dy, vis, n, m)


def main():
    n, m = [int(x) for x in input().split()]

    vis = [[False for _ in range(m)] for _ in range(n)]

    for i in range(n):
        cs = input()
        for j in range(m):
            vis[i][j] = (cs[j] == '#')

    cnt = 0
    for i in range(n):
        for j in range(m):
            if not vis[i][j]:
                dfs(i, j, vis, n, m)
                cnt += 1

    print(cnt)


main()
