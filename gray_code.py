def g(n):
    if n == 1:
        return ["0", "1"]
    prev = g(n - 1)
    result = ["0" + x for x in prev]
    extended = ["1" + x for x in reversed(prev)]
    result.extend(extended)

    return result


def main():
    n = int(input())
    result = g(n)
    for s in result:
        print(s)


main()
