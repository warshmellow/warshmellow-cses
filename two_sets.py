def g(n):
    nums = list(range(1, n + 1))

    a = []
    b = []
    sa = 0
    sb = 0

    for i in reversed(nums):
        if sa < sb:
            a.append(i)
            sa += i
        else:
            b.append(i)
            sb += i

    if sa == sb:
        return a, b
    else:
        return [], []


def main():
    n = int(input())

    s1, s2 = g(n)

    if s1 and s2:
        print("YES")
        print(len(s1))
        print(" ".join([str(x) for x in s1]))
        print(len(s2))
        print(" ".join([str(x) for x in s2]))
    else:
        print("NO")


main()
