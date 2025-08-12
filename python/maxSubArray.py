from typing import List


class Solution:
    # def maxSubArray(self, nums: List[int]) -> int:
    #     sumArray = [0]
    #     for n in nums:
    #         sumArray.append(sumArray[-1] + n)
    #
    #     def dp(i: int, j: int) -> int:
    #         if 0 <= i and i < j and j <= len(nums):
    #             curr = max(sumArray[j] - sumArray[i], dp(i + 1, j), dp(i, j - 1))
    #             return curr
    #         return -( 10 ** 4 )
    #     return dp(0, len(nums))


    def maxSubArray(self, nums: List[int]) -> int:
        mx = -(10**4)
        currMx = 0

        for n in nums:
            currMx = max(n, currMx + n)
            mx = max(currMx, mx)
        
        return mx

    # def maxSubArray(self, nums: List[int]) -> int:
    #     sumArray = [0]
    #     for n in nums:
    #         sumArray.append(sumArray[-1] + n)
    #
    #     mx = -(10**4)
    #     for i in range(len(sumArray)-1):
    #         for j in range(i+1, len(sumArray)):
    #             mx = max(mx, sumArray[j] - sumArray[i])
    #     return mx




s = Solution()

n = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
o = s.maxSubArray(n)
print(n, o)
assert o == 6

n = [-1,1, -2]
o = s.maxSubArray(n)
print(n, o)
assert o == 1

n = [1]
o = s.maxSubArray(n)
print(n, o)
assert o == 1

n = [5,4,-1,7,8]
o = s.maxSubArray(n)
print(n, o)
assert o == 23
