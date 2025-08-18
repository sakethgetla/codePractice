from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [ [nums[0]] ]
        n = nums.pop()
        p = self.permute(nums)

        for 

    # def permute(self, nums: List[int]) -> List[List[int]]:
    #     for i in range(len(nums)):


    # def permute(self, nums: List[int]) -> List[List[int]]:
    #     permsTotal = []
    #     def dp(ns: List[int], perms: List[List[int] ]):
    #         if len(ns) == 1:
    #             for i in range( len( perms ) ):
    #                 perms[i].append(ns[0])
    #                 permsTotal.append(perms[i])
    #         else:
    #             for i in range( len( ns ) ):
    #                 newPerms = []
    #                 dp(ns[0:i, i+1: 4], )
    #
        
s = Solution()
n = 20
o = s.permute(n)
print (n, o)
assert o ==
