def get_subsets(nums):
    n = len(nums)
    if n == 1:
        return [tuple([]), tuple(nums)]

    prev = get_subsets(nums[1:])
    result = [tuple([nums[0]]) + subset for subset in prev]
    result.extend(prev)
    return result


def f(nums):
    """
    The recursive approach is to generate all possible sums 
    from all the values of the array and to check which solution is the most optimal one. 
    To generate sums we either include the i’th item in set 1 or don’t include, i.e., include in set 2.  
    """
    n = len(nums)
    total = sum(nums)
    subsets = get_subsets(nums)
    return min([abs(total - 2 * sum(subset)) for subset in subsets])


def main():
    _ = int(input())
    nums = [int(a) for a in input().split()]
    print(f(nums))


main()
