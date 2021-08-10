from bisect import *


def f(hs, ts):
    tickets = sorted(hs)

    result = []

    for t in ts:
        i = bisect_right(tickets, t)
        if i == 0:
            result.append(-1)
        else:
            result.append(tickets[i - 1])
            tickets.remove(tickets[i - 1])

    return result


def main():
    n, m = [int(y) for y in input().split()]
    hs = [int(y) for y in input().split()]
    ts = [int(y) for y in input().split()]

    for x in f(hs, ts):
        print(x)


main()
