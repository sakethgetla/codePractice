from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i, e in enumerate(nums):
            if target - e in dic:
                return [dic[ target - e ].pop() , i]
            else:
                if e in dic:
                    dic[e].append(i)
                else:
                    dic[e] = [i]
        return []


    # def twoSum(self, nums: List[int], target: int) -> List[int]:
    #     idx = {}
    #     for i, e in enumerate(nums):
    #         if e in idx:
    #             idx[e].append(i)
    #         else:
    #             idx[e] = [i]
    #
    #
    #     nums.sort()
    #     i, j = 0, len(nums)-1
    #
    #     # print (idx)
    #     while i < j:
    #         # print (i,j)
    #         if nums[i] + nums[j] == target:
    #             return [idx[nums[i]].pop(), idx[nums[j]].pop()]
    #         elif nums[i] + nums[j] < target:
    #             i += 1
    #         else:
    #             j -= 1
    #     return []


s = Solution()

n = [2,7,11,15]
target = 9
o = s.twoSum(n, target)
print (n,target, o)
assert o == [0,1]


n = [3,-2,-4]
target = -6
o = s.twoSum(n, target)
print (n,target, o)
assert o == [1,2] or o==[2,1]

n = [3,-2,4]
target = 2
o = s.twoSum(n, target)
print (n,target, o)
assert o == [1,2]


n = [3,2,4]
target = 6
o = s.twoSum(n, target)
print (n,target, o)
assert o == [1,2]


