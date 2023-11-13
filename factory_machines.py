def total_after_time(t, ks):
    count = 0
    for i in range(len(ks)):
        count += t // ks[i]
    return count


def main():
    n, t = [int(y) for y in input().split()]
    ks = [int(y) for y in input().split()]

    if n == 1:
        print(ks[0] * t)
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
