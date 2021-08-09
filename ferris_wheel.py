def f(x, ps):
    ps.sort()
    n = len(ps)
    ans = 0
    i = 0
    j = n - 1
    while i <= j:
        ans += 1
        if i == j:
            break
        if ps[i] + ps[j] > x:
            j -= 1
        else:
            i += 1
            j -= 1
    return ans


def main():
    n, x = [int(y) for y in input().split()]
    ps = [int(y) for y in input().split()]
    print(f(x, ps))


main()
