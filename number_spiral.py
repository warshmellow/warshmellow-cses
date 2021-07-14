def get_y_edge(y):
    if y % 2 == 0:
        return y ** 2
    else:
        return (y - 1) ** 2 + 1


def get_x_edge(x):
    if x % 2 == 0:
        return (x - 1) ** 2 + 1
    else:
        return x ** 2


def g(y, x):
    if x == 1:
        return get_y_edge(y)
    elif y == 1:
        return get_x_edge(x)
    elif x == y:
        valy = get_y_edge(y)
        valx = get_x_edge(x)
        mn = min(valy, valx)
        mx = max(valy, valx)
        return mn + (mx - mn) // 2
    elif y > x:
        start = get_y_edge(y)
        if y % 2 == 0:
            return start - x + 1
        else:
            return start + x - 1
    else:
        start = get_x_edge(x)
        if x % 2 == 0:
            return start + y - 1
        else:
            return start - y + 1


def main():
    t = int(input())
    for _ in range(t):
        y, x = [int(a) for a in input().split()]
        print(g(y, x))


main()
