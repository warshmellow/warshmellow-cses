

def josh(person, k, index, result):
    while len(person) > 1:
        index = ((index + k) % len(person))
        result.append(person[index])
        del person[index]

    result.append(person[0])


def main():
    n = int(input())

    k = 2
    k -= 1
    index = 0

    person = list(range(1, n + 1))

    result = []
    josh(person, k, index, result)

    print(" ".join([str(x) for x in result]))


main()
