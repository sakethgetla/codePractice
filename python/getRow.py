from typing import List
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode


class Solution:
    # def getRow(self, rowIndex: int) -> List[int]:
    #     if rowIndex == 0:
    #         return [1]
    #     else:
    #         prevRow = self.getRow(rowIndex-1)
    #         currRow = [1]
    #         for i in range(1, len(prevRow)):
    #             currRow.append(prevRow[i - 1] + prevRow[i])
    #         currRow.append(1)
    #         return currRow
    #
    #
    def getRow(self, rowIndex: int) -> List[int]:
        currRow = [1]
        for _ in range(rowIndex):
            nxtRow = [1]
            for i in range(1, len(currRow)):
                nxtRow.append(currRow[i - 1] + currRow[i])
            nxtRow.append(1)
            currRow = nxtRow
        return currRow


s = Solution()

n = 3
o = s.getRow(n)
print(n, o)
assert o == [1, 3, 3, 1]

n = 1
o = s.getRow(n)
print(n, o)
assert o == [1, 1]
