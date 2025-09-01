from typing import List
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        i = 0
        while min(len(strs[0]), len(strs[-1])) > i and strs[0][i] == strs[-1][i]:
            i += 1
        return strs[0][:i]

    # def longestCommonPrefix(self, strs: List[str]) -> str:
    #
    #     commonPre = strs[0]
    #     for s in strs[1:]:
    #         i = 0
    #         while i < len(s) and i < len(commonPre) and s[i] == commonPre[i]:
    #             print(s, i)
    #             i += 1
    #         commonPre = commonPre[:i]
    #     return commonPre
    #


s = Solution()

n = ["flower", "flow", "flight"]
o = s.longestCommonPrefix(n)
print(n, o)
assert o == "fl"

n = ["flower", "dog", "flow", "flight"]
o = s.longestCommonPrefix(n)
print(n, o)
assert o == ""
