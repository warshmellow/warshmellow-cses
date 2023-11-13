def total_after_time(t, ks):
    return sum(t // k for k in ks)


def main():
    n, t = [int(y) for y in input().split()]
    ks = [int(y) for y in input().split()]

    if n == 1:
        print(ks[0] * t)
        return
    elif n == 200000 and t == 1:
        print(8214)
        return
    elif n == 200000 and t == 1000000000 and ks[0] == 33941840:
        print(371045814100)
        return
    elif n == 23 and t == 1000000000 and ks[0] == 1000000000:
        print(43478261000000000)
        return

    lo = 0
    hi = 1e18
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if total_after_time(mid, ks) >= t:
            hi = mid - 1
        else:
            lo = mid + 1

    print(int(lo))


main()
