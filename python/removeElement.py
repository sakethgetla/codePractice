from typing import List
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        j = len(nums) - 1
        if len(nums) == 0:
            return 0
        while i < j:
            if nums[i] == val:
                nums[i] = nums[j]
                nums[j] = val
                j -= 1
            else:
                i += 1
        return j if nums[j] == val else j+1

s = Solution()

n = [3,2,2,3]
v = 3
o = s.removeElement(n, v)
print (n,v, o)
assert o == 2
assert n == [2,2,3,3]

n = [1,2,3,3,3]
v = 3
o = s.removeElement(n, v)
print (n,v, o)
assert o == 2
assert n[:o] == [1,2]

n = [1]
v = 1
o = s.removeElement(n, v)
print (n,v, o)
assert o == 0
assert n[:o] == []

n = [0,0,0,0]
v = 0
o = s.removeElement(n, v)
print (n,v, o)
assert o == 0
assert n[:o] == []

n = []
v = 0
o = s.removeElement(n, v)
print (n,v, o)
assert o == 0
assert n[:o] == []

n = [0,1,2,2,3,0,4,2]
v = 2
o = s.removeElement(n, v)
print (n,v, o)
assert o == 5
assert n[:o] == [0,1,4,0,3]
