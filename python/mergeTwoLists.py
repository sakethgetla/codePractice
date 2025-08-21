from typing import List
from typing import Optional
from treeNode import TreeNode
from listNode import ListNode


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if list1 == None:
            return list2
        elif list2 == None:
            return list1
        elif list1.val > list2.val:
            nxt = self.mergeTwoLists(list1, list2.next)
            list2.next = nxt
            return list2
        else:
            nxt = self.mergeTwoLists(list1.next, list2)
            list1.next = nxt
            return list1


s = Solution()

# n = ListNode.createListFromList([])
# m = ListNode.createListFromList([])
# print(n, m)
o = s.mergeTwoLists(None, None)
# t = ListNode.createListFromList([])
# print(o, t)
assert o == None

# o = s.mergeTwoLists(None, None)
# t = ListNode.createListFromList([])
# print(o, t)
assert s.mergeTwoLists(
    None, ListNode.createListFromList([0])
) == ListNode.createListFromList([0])

n = ListNode.createListFromNum(431)
m = ListNode.createListFromList([1, 2, 4])
print(n, m)
o = s.mergeTwoLists(n, m)
t = ListNode.createListFromList([1, 1, 2, 3, 4, 4])
print(o, t)
# assert ListNode.equal(o, t)
assert o == t
