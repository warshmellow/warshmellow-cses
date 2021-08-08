def f(k, a, b):
    a.sort()
    b.sort()

    i = 0
    j = 0
    n = len(a)
    m = len(b)

    count = 0
    while i < n and j < m:
        ai = a[i]
        bj = b[j]
        if bj - k <= ai <= bj + k:
            count += 1
            i += 1
            j += 1
        elif ai < bj - k:
            i += 1
        elif bj + k < ai:
            j += 1
    return count


def main():
    n, m, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]

    print(f(k, a, b))


main()
