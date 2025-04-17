# imports
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode
from typing import List


# t = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
# t = TreeNode(1, None, TreeNode(2))

a = 1
b = 2

print(a, b)

a, b = b, a
print(a, b)
