from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        j = k = 0
        out = []
        outSet = set()
        for i in range(len(nums)):
            j = i + 1
            k = len(nums)-1
            while j < k:
                if nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                elif nums[i] + nums[j] + nums[k] < 0:
                    j += 1
                else:
                    # if len(out) == 0 or str([nums[ i ],nums[ j ],nums[ k ]]) not in outSet:
                    if (nums[ i ],nums[ j ],nums[ k ]) not in outSet:
                        out.append([nums[ i ],nums[ j ],nums[ k ]])
                        # outSet.add(str([nums[ i ],nums[ j ],nums[ k ]]))
                        outSet.add((nums[ i ],nums[ j ],nums[ k ]))
                    j += 1
                    k -= 1
        # print(out)
        # return [ [nums[x], nums[y], nums[z] ] for x,y,z in out]
        return out



                 




    # def threeSum(self, nums: List[int]) -> List[List[int]]:
    #     s = set()
    #     mp = {}
    #     for i in range(len(nums)):
    #         mp[nums[i]] = i
    #
    #     out = []
    #     for i in range( len( nums ) ):
    #         for j in range(i+1, len( nums ) ):
    #             if (-1)*(nums[i] + nums[j]) in mp and mp[(-1)*(nums[i] + nums[j])] != i and mp[(-1)*(nums[i] + nums[j])] != j:
    #                 curr = [nums[i] , nums[j], (-1)*(nums[i] + nums[j])]
    #                 curr.sort()
    #                 currStr = str(curr)
    #                 if currStr not in s:
    #                     out.append(curr)
    #                     s.add(currStr)
    #     return out 




    # def threeSum(self, nums: List[int]) -> List[List[int]]:
    #     mp = {}
    #     for i in range( len( nums ) ):
    #         for j in range(i+1, len( nums ) ):
    #             if nums[ i ] + nums [ j ] in mp:
    #                 mp[nums[ i ] + nums [ j ]].append([i, j])
    #             else:
    #                 mp[nums[ i ] + nums [ j ]] = [ [i, j] ]
    #
    #     # print(mp)
    #     s = set()
    #     out = []
    #     for i in range(len(nums)):
    #         if (-1)*nums[i] in mp:
    #             for match in mp[(-1)*nums[i]]:
    #                 if i != match[0] and i != match[1]:
    #                     curr = [nums[ i ], nums[match[0]], nums[match[1]]]
    #                     curr.sort()
    #                     currStr = str(curr)
    #                     # print(currStr, [nums[ i ], nums[match[0]], nums[match[1]]], match)
    #                     if currStr not in s:
    #                         out.append([nums[ i ], nums[match[0]], nums[match[1]]  ])
    #                         s.add(currStr)
    #     # print(out)
    #     return out
    #
    #     

s = Solution()
n = [0,0,0]
o = s.threeSum(n)
print (n, o)
assert o == [ [0,0,0] ]

n = [0,1,1]
o = s.threeSum(n)
print (n, o)
assert o == []

n = [-1,0,1,2,-1,-4]
o = s.threeSum(n)
print (n, o)
assert o == [[-1,-1,2],[-1,0,1]]


n = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
o = s.threeSum(n)
print (n, o)
assert o == [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]

