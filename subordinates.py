from collections import defaultdict
import sys
from functools import lru_cache

sys.setrecursionlimit(10**6)


def f(bosses):
    adj = defaultdict(list)

    n = len(bosses) + 1

    for i, boss in enumerate(bosses):
        sub = i + 2
        adj[boss].append(sub)

    @lru_cache
    def count_subs(boss):
        direct_subs = adj[boss]

        return sum([1 + count_subs(direct_sub) for direct_sub in direct_subs])

    return [count_subs(i) for i in range(1, n + 1)]


def main():
    _ = int(input())

    bosses = [int(x) for x in input().split()]

    print(" ".join([str(num_subs) for num_subs in f(bosses)]))


main()
