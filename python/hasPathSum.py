from treeNode import TreeNode
from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False
        elif root is not None and root.left is None and root.right is None and root.val == targetSum:
            # root node
            return True
        else:
            return self.hasPathSum(root.left, targetSum-root.val) or self.hasPathSum(root.right, targetSum-root.val)


s = Solution()
r = TreeNode(5, TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))), TreeNode(8, TreeNode(13), TreeNode(4, None, TreeNode(1))))
t = 26
o = s.hasPathSum(r, t)
print(r, o)
assert o == True

r = TreeNode(1, TreeNode(2), TreeNode(3))
t = 5
o = s.hasPathSum(r, t)
print(r, o)
assert o == False

r = None
t = 5
o = s.hasPathSum(r, t)
print(r, o)
assert o == False

