from collections import defaultdict


def g(adj, n, m):
    MAX_WEIGHT = 1000000
    X = set([1])
    A = {}
    A[1] = 0

    while len(X) < n:
        min_crit = MAX_WEIGHT
        min_w = None
        for v in X:
            for w, weight in adj[v]:
                if w not in X:
                    candidate = A[v] + weight
                    if candidate <= min_crit:
                        min_w = w
                        min_crit = candidate
        X.add(min_w)
        A[min_w] = min_crit

    return A


def main():
    adj = defaultdict(list)

    n, m = [int(x) for x in input().split()]

    for _ in range(m):
        a, b, c = [int(x) for x in input().split()]
        adj[a].append((b, c))

    result = g(adj, n, m)

    print(" ".join(
        str(result[i])
        for i in range(1, n + 1)
    ))


main()
