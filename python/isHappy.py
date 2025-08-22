        
from typing import List
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode

class Solution:
    def isHappy(self, n: int) -> bool:
        s = set()
        def dp(n: int) -> bool:
            newN = 0
            while n > 0:
                c = n % 10
                n //= 10
                newN += c**2
            if newN == 1:
                return True
            elif newN in s:
                return False
            else:
                s.add(newN)
                return dp(newN)
        return dp(n)


s = Solution()

n = 2
o = s.isHappy(n)
print (n, o)
assert o == False

n = 19
o = s.isHappy(n)
print (n, o)
assert o == True
