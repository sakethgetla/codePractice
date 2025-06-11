from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        totalSum = 0
        # for i in range(len(nums)):
        for n in nums:
            totalSum += n

        leftSum = 0
        for i in range(len(nums)):
            if (leftSum == totalSum - leftSum - nums[i]):
                return i
            leftSum += nums[i]
        return -1


s = Solution()
nums = [1,7,3,6,5,6]
o = s.pivotIndex(nums)
print(nums, o)
assert o == 3

nums =[1,2,3] 
o = s.pivotIndex(nums)
print(nums, o)
assert o == -1

nums =[2,1,-1] 
o = s.pivotIndex(nums)
print(nums, o)
assert o ==0

