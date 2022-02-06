def f(ks):
    n = len(ks)
    ans = 1
    # mp[k] == highest index where ks[j] == k
    mp = {ks[0]: 0}

    i = 0
    # loop invariant: i is 1 + highest index mapping to k
    # In particular, we push out a k to accommodate k == ks[j]
    # in this loop
    # answer candidate is j + 1 - i
    # mp[k] is updated
    for j in range(1, n):
        k = ks[j]

        if k in mp:
            i = max(mp[k] + 1, i)

        ans = max(ans, j + 1 - i)
        mp[k] = j

    return ans


def main():
    n = int(input())
    ks = [int(x) for x in input().split()]

    print(f(ks))


main()
