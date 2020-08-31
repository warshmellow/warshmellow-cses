import bisect


def g(a, x):
    awi = [(y, i) for (i, y) in enumerate(a)]
    awi.sort()

    seen = set(a)

    n = len(awi)

    for i in range(n):
        for j in range(i + 1, n):
            w, wi = awi[i]
            y, yi = awi[j]
            diff = x - w - y

            if diff not in seen:
                continue

            k = bisect.bisect_left(awi, (diff, -1), j + 1, n)
            if k < n:
                z, zi = awi[k]
                if z == diff and k != j and k != i:
                    return wi + 1, yi + 1, zi + 1

    return -1, -1, -1


def main():
    parsed_line = [int(b) for b in input().split()]
    n = parsed_line[0]
    x = parsed_line[1]

    a = [int(b) for b in input().split()]

    i, j, k = g(a, x)

    if i == -1:
        print("IMPOSSIBLE")
    else:
        print(f"{i} {j} {k}")


main()
