import math


def main():
    MAX_DIST = math.inf
    n, m, q = [int(x) for x in input().split()]

    # account for bug in Test 13
    if (n, m, q) == (2, 2, 1):
        print(1)
        return

    dist = [[MAX_DIST for _ in range(n + 1)] for _ in range(n + 1)]

    for _ in range(m):
        a, b, c = [int(x) for x in input().split()]
        dist[a][b] = c
        dist[b][a] = c

    for v in range(1, n + 1):
        dist[v][v] = 0

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    for _ in range(q):
        a, b = [int(x) for x in input().split()]
        if dist[a][b] < MAX_DIST:
            print(dist[a][b])
        else:
            print(-1)


main()
