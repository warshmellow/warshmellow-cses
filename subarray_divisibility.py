def f(xs):
    n = len(xs)

    count = 0
    prefix_sum = 0

    freq = {}  # frequency of seeing prefix sum % n
    freq[0] = 1  # This allows for prefix sums to be counted

    for x in xs:
        # Tracks prefix xs[:i + 1] % n
        prefix_sum = (prefix_sum + x) % n

        if prefix_sum in freq:
            """
            Let 0 < j < i + 1.
            If xs[:j] % n == xs[:i + 1] % n, then 
            (xs[:i + 1] - xs[:j]) % n == xs[j: i + 1] % n == 0.

            Thus every prefix not the same to current one but
            with the same subarray sum % n has a difference a new subarray with sum 0 % n.
            """
            count += freq[prefix_sum]
        else:
            freq[prefix_sum] = 0

        freq[prefix_sum] += 1

    return count


def main():
    n = int(input())
    xs = [int(x) for x in input().split()]

    print(f(xs))


main()
