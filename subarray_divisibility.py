def f(xs):
    n = len(xs)

    cnt = 0
    pre = 0

    freq = {}
    freq[0] = 1

    for x in xs:
        pre = (pre + x) % n

        if pre in freq:
            cnt += freq[pre]
        else:
            freq[pre] = 0

        freq[pre] += 1

    return cnt


def main():
    n = int(input())
    xs = [int(x) for x in input().split()]

    print(f(xs))


main()
