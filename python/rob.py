
from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:

        if len(nums) == 1:
            return nums[0]

        prevprev = nums[0]
        prev = nums[1]
        # curr = 0
        for i in range(2, len( nums )):
            nums[i] += prevprev
            prevprev = max(prev, prevprev)
            prev = nums[i]

        return max(prevprev, prev)

s = Solution()
# nums = [1,2,3,1]
# nums = [2,7,9,3,1]
nums = [2,1,1,2]
out = s.rob(nums)
print (nums, out)




