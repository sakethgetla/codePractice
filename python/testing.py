# imports
from typing import List
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode


# t = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
# t = TreeNode(1, None, TreeNode(2))

a = 1
b = 2

print(a, b)

a, b = b, a
print(a, b)


s = set()
s.add(1)
s.add(2)
s.add(4)
print(s, 4 not in s, 4 in s)
