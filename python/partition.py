from typing import List
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        o = []
        found = {}

        def isPalindrome(sa: str) -> bool:
            l = len(sa)
            if l == 1:
                return True
            elif l % 2 == 1 and sa[: l // 2] == sa[-1:(l // 2) :-1]:
                return True
            elif l % 2 == 0 and sa[: l // 2] == sa[-1: l // 2 -1:-1]:
                return True
            else:
                return False

        def dp(st: str) -> List[List[str]]:
            u = []
            if st in found:
                return found[st]
            if isPalindrome(st):
                u.append([ st ])

            for i in range(1, len(st)):
                # left = dp(st[:i])
                left = st[:i]
                if isPalindrome(left):
                    right = dp(st[i:])
                    for rig in right:
                        # print([[left] + rig], left, rig)
                        u.append([left] + rig)
            found[st] = u
            return u

        return dp(s)


s = Solution()

n = "abbab"
o = s.partition(n)
print(n, o)
assert o == []
