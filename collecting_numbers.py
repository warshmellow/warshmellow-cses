def f(xs):
    pos = {x: i for i, x in enumerate(xs)}

    cnt = 1
    for i in range(2, len(xs) + 1):
        if pos[i - 1] > pos[i]:
            cnt += 1
    return cnt


def main():
    n = int(input())
    xs = [int(x) for x in input().split()]

    print(f(xs))


main()
