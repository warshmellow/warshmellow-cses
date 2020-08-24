import bisect


def g(a, x):
    n = len(a)

    a_with_idx = [(y, i) for (i, y) in enumerate(a)]
    a_with_idx.sort()

    for y, i in a_with_idx:
        diff = x - y
        j = bisect.bisect_left(a_with_idx, (diff, n + 1))
        if j > 0:
            cand, cand_idx = a_with_idx[j - 1]
            if cand == diff and cand_idx > i:
                return (i + 1, cand_idx + 1)

    return -1, -1


def main():
    parsed_line = [int(b) for b in input().split()]
    x = parsed_line[1]

    a = [int(b) for b in input().split()]

    i, j = g(a, x)

    if i == -1:
        print("IMPOSSIBLE")
    else:
        print(f"{i} {j}")


main()
