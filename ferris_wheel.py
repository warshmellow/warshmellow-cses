from collections import deque


def f(x, ps):
    ps.sort()
    ps = deque(ps)
    n = len(ps)
    ans = 0
    while len(ps) >= 1:
        ans += 1
        if len(ps) == 1:
            break
        elif ps[0] + ps[-1] > x:
            # include heaviest child only
            ps.pop()
        else:
            # include lightest and heaviest child
            ps.popleft()
            ps.pop()
    return ans


def main():
    n, x = [int(y) for y in input().split()]
    ps = [int(y) for y in input().split()]
    print(f(x, ps))


main()
