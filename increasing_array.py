def g(nums):
    n = len(nums)
    total = 0
    m = nums[0]

    for i in range(1, n):
        total += max(0, m - nums[i])
        m = max(m, nums[i])
    return total


def main():
    n = int(input())
    nums = [int(b) for b in input().split()]
    print(g(nums))


main()
