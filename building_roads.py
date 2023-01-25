import sys
sys.setrecursionlimit(10**6)


def f(adj):
    n = len(adj)
    visited = [False for _ in range(n + 1)]

    def dfs(s):
        if visited[s]:
            return
        visited[s] = True
        for u in adj[s]:
            dfs(u)

    components = []
    for i in range(1, n + 1):
        if visited[i]:
            continue
        dfs(i)
        components.append(i)

    return components


def main():
    adj = {}

    n, m = [int(x) for x in input().split()]

    for i in range(1, n + 1):
        adj[i] = []

    for _ in range(m):
        a, b = [int(x) for x in input().split()]
        adj[a].append(b)
        adj[b].append(a)

    components = f(adj)
    k = len(components) - 1
    print(k)
    for i in range(1, len(components)):
        a = components[i - 1]
        b = components[i]
        print(str(a) + " " + str(b))


main()
