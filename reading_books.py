def f(ts):
    sm = sum(ts)
    mx = max(ts)

    return max(sm, 2 * mx)


def main():
    n = int(input())
    ts = [int(y) for y in input().split()]

    print(f(ts))


main()
