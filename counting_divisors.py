from collections import Counter


def factors(n):
    fs = []
    x = 2
    while x * x <= n:
        while n % x == 0:
            fs.append(x)
            n = n // x
        x += 1
    if n > 1:
        fs.append(n)
    return fs


def f(x):
    ctr = Counter(factors(x))

    total = 1
    for _, a in ctr.most_common():
        total *= (a + 1)
    return total


def main():
    n = int(input())
    for _ in range(n):
        x = int(input())
        print(f(x))


main()
