from typing import List

class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        s1 = set()
        s2 = set()
        out = [[],[]]
        for i in nums1:
            s1.add(i)

        for i in nums2:
            if (s1.intersection({i})):
                out[0].append(K)
            s2.add(i)
            
            


        # s1 = set([i for i in nums1])
        # s2 = set([i for i in nums2])
        # return [ list( s1.difference(s2) ) , list(s2.difference(s1)) ]



nums1 = [1,2,3]
nums2 = [2,4,6]
c = Solution()
d = c.findDifference(nums1, nums2)
print(nums1, nums2, d)
        
