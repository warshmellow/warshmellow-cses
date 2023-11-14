import functools

MOD = 1000000000 + 7


def binomialCoef(n, k):
    C = [[0 for x in range(k + 1)] for x in range(n + 1)]

    # Calculate value of Binomial
    # Coefficient in bottom up manner
    for i in range(n + 1):
        for j in range(min(i, k) + 1):
            # Base Cases
            if j == 0 or j == i:
                C[i][j] = 1

            # Calculate value using
            # previously stored values
            else:
                C[i][j] = (C[i - 1][j - 1] % MOD + C[i - 1][j] % MOD) % MOD

    return C[n][k] % MOD


def main():
    n = int(input())

    for _ in range(n):
        a, b = [int(x) for x in input().split()]
        print(binomialCoef(a, b))


main()
