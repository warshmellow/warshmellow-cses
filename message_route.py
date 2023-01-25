def f(adj):
    n = len(adj)

    q = []
    visited = [False for _ in range(n + 1)]
    distance = [float('inf') for _ in range(n + 1)]
    p = [0 for _ in range(n + 1)]

    visited[1] = True
    distance[1] = 0
    q.append(1)

    while q:
        newq = []
        for s in q:
            for u in adj[s]:
                if visited[u]:
                    continue
                visited[u] = True
                distance[u] = distance[s] + 1
                p[u] = s
                newq.append(u)
        q = newq

    return distance, p


def main():
    adj = {}

    n, m = [int(x) for x in input().split()]

    for i in range(n + 1):
        adj[i] = []

    for _ in range(m):
        a, b = [int(x) for x in input().split()]
        adj[a].append(b)
        adj[b].append(a)

    distance, p = f(adj)

    if distance[n] < float('inf'):
        print(distance[n] + 1)
        result = [str(n)]
        x = n
        while x != 1:
            result.append(str(p[x]))
            x = p[x]
        print(" ".join(reversed(result)))
    else:
        print("IMPOSSIBLE")


main()
