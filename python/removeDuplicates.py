from typing import List
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[j]:
                j += 1
            nums[j] = nums[i]
        return j+1


s = Solution()
n = [1,1,2,2,3,4,5]
o = s.removeDuplicates(n)
print (n, o)
assert o ==[1,2,3]
        
