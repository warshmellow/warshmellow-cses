from bisect import bisect_right


def f(ks):
    sub = []
    for num in ks:
        i = bisect_right(sub, num)

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
