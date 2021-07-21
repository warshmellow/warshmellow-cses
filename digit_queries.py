
def f(n):
    n -= 1
    digits = 1
    while True:
        first = 10 ** (digits - 1)
        if n < 9 * first * digits:
            return int(str(first + n//digits)[n % digits])
        n -= 9 * first * digits
        digits += 1


def main():
    q = int(input())
    for _ in range(q):
        k = int(input())
        print(f(k))


main()
