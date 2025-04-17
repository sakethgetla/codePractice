from treeNode import TreeNode
from typing import List
from typing import Optional

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        currLvl = out = []
        nextLvl = [root]
        while len( nextLvl ) > 0 :
            currLvl = nextLvl
            nextLvl = []
            found = False
            while len( currLvl ) > 0:
                curr = currLvl.pop(0)
                if curr.right :
                    nextLvl.append(curr.right)
                if curr.left :
                    nextLvl.append(curr.left)
                if not found:
                    found = True
                    out.append(curr.val)
        return out




s = Solution()
# t = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3, None, TreeNode(4)))
t = TreeNode(1, TreeNode(2, TreeNode(4, TreeNode(5)) ), TreeNode(3))
print(t)
o = s.rightSideView(t)
print(o)

