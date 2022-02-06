import sys


def max_sum_subarray(arr, L, R):

    n = len(arr)
    pre = n * [0]

    # Calculating prefix sum
    pre[0] = arr[0]
    for i in range(1, n):
        pre[i] = pre[i - 1] + arr[i]

    s1 = []

    # Maintain 0 for initial
    # values of i upto R
    # Once i = R, then
    # we need to erase that 0 from
    # our multiset as our first
    # index of subarray
    # cannot be 0 anymore.
    s1.append(0)
    ans = -sys.maxsize - 1

    ans = max(ans, pre[L - 1])

    # We maintain flag to
    # counter if that initial
    # 0 was erased from set or not.
    flag = 0

    for i in range(L, n):

        # Erase 0 from multiset once i=b
        if (i - R >= 0):
            if (flag == 0):
                s1.remove(0)
                flag = 1

        # Insert pre[i-L]
        if (i - L >= 0):
            s1.append(pre[i - L])

        # Find minimum value in multiset.
        ans = max(ans, pre[i] - s1[0])

        # Erase pre[i-R]
        if (i - R >= 0):
            s1.remove(pre[i - R])

    return ans


def main():
    n, a, b = [int(x) for x in input().split()]
    xs = [int(x) for x in input().split()]

    print(max_sum_subarray(xs, a, b))


main()
