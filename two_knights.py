def g(k):
    return k * k * (k * k - 1) // 2 - 4 * (k - 1) * (k - 2)


def main():
    n = int(input())
    for k in range(1, n + 1):
        print(g(k))


main()
