from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        for j in range(len(nums)):
            if (nums[j] != 0):
                tmp = nums[i]
                nums[i] = nums[j]
                nums[j] = tmp
                i+=1


# a = [0,1,0,3,12]
a = [0]

print(a)
c = Solution()
c.moveZeroes(a)
print(a)

