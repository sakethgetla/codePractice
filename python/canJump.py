from typing import List

class Solution:
    # def canJump(self, nums: List[int]) -> bool:
    #     # a = [None for _ in range(len( nums ) + 1)]
    #     a = [False for _ in nums]
    #     a[0] = True
    #     # a[1] = True
    #     for i in range( len( nums ) ):
    #         if a[i] == True :
    #             a[i+nums[i]   if i+nums[i] < len(nums) else -1] = True
    #     return a[-1]
    def canJump(self, nums: List[int]) -> bool:
        # a = [None for _ in range(len( nums ) + 1)]
        a = [False for _ in nums]
        a[0] = True
        # a[1] = True
        mxJump = 0
        i = 0
        while i < len(nums)-1 and mxJump >-1:
            mxJump = max(nums[i], mxJump)
            i += 1
            mxJump -=1
        return mxJump > -1

s = Solution()

n = [2,3,1,1,4]
o = s.canJump(n)
print (n, o)
assert o == True

n = [2,2,1,0,4]
o = s.canJump(n)
print (n, o)
assert o == False

n = [2,5,0,0]
o = s.canJump(n)
print (n, o)
assert o == True

n = [0]
o = s.canJump(n)
print (n, o)
assert o == True

n = [2,0]
o = s.canJump(n)
print (n, o)
assert o == True

