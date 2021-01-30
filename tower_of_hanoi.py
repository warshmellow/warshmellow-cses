def h(n, src, dst, tmp):
    if n > 0:
        move1 = h(n - 1, src, tmp, dst)
        move_largest = [(src, dst)]
        move2 = h(n - 1, tmp, dst, src)
        result = move1
        result.extend(move_largest)
        result.extend(move2)
        return result
    return []


def main():
    n = int(input())

    result = h(n, 1, 3, 2)

    print(len(result))
    for a, b in result:
        print(f"{a} {b}")


main()
