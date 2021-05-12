def g(nums):
    total = 0
    curr_max = nums[0]

    for curr in nums[1:]:
        if curr_max > curr:
            diff = curr_max - curr
            total += diff
        curr_max = max(curr_max, curr)
    return total


def main():
    n = int(input())
    nums = [int(b) for b in input().split()]
    print(g(nums))


main()
