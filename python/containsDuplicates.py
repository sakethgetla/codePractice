from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        s = set()
        for n in nums:
            if n in s:
                return True
            else:
                s.add(n)
        return False


s = Solution()
n = [1,2,3,4]
o = s.containsDuplicate(n)
print (n, o)
assert o == False    
        
n = [1,2,3,1]
o = s.containsDuplicate(n)
print (n, o)
assert o == True    
        
