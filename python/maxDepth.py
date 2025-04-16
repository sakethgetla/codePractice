from typing import Optional
from treeNode import TreeNode

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        if root == None:
            return 0

        leftDepth = rightDepth = 0
        if root.right == None:
            rightDepth = 0
        else:
            rightDepth = self.maxDepth(root.right)

        if root.left == None:
            leftDepth = 0
        else:
            leftDepth = self.maxDepth(root.left)

        
        return max(leftDepth, rightDepth) +1



s = Solution()
# t = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
# t = TreeNode(1, None, TreeNode(2))
t = TreeNode(1, None, None)
# t = None

maxdp = s.maxDepth(t)
print(t)
print(maxdp)
