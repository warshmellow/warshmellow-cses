def g(a, b):
    """
    We're looking for nonnegative integer solutions x, y to
    a = 2x + y
    b = x + 2y
    """
    three_x = 2 * a - b
    three_y = 2 * b - a

    return three_x >= 0 and three_y >= 0 and three_x % 3 == 0 and three_y % 3 == 0


def main():
    t = int(input())
    for k in range(t):
        a, b = [int(x) for x in input().split()]
        if g(a, b):
            print("YES")
        else:
            print("NO")


main()
