from bisect import bisect_left


def f(ks):
    sub = []

    ks = [-x for x in ks]

    for num in ks:
        i = bisect_left(sub, num)

        # If num is greater than any element in sub
        if i == len(sub):
            sub.append(num)

        # Otherwise, replace the first element in sub greater than or equal to num
        else:
            sub[i] = num

    return len(sub)


def main():
    n = int(input())
    ks = [int(x) for x in input().split()]

    print(f(ks))


main()
