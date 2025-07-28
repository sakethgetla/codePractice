# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional

from listNode import ListNode


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if not isinstance(l1, ListNode) and not isinstance(l2, ListNode):
            return None

        currSum = 0
        nxt1 = None
        nxt2 = None

        if isinstance(l1, ListNode):
            currSum += l1.val
            nxt1 = l1.next

        if isinstance(l2, ListNode):
            currSum += l2.val
            nxt2 = l2.next

        if currSum >= 10:
            if isinstance(nxt2, ListNode):
                nxt2.val += 1
            else:
                nxt2 = ListNode(1)
            currSum -= 10

        currNode = ListNode(currSum, self.addTwoNumbers(nxt1, nxt2))
        return currNode


s = Solution()

l1 = ListNode.createListFromNum(342)
l2 = ListNode.createListFromNum(465)
o = s.addTwoNumbers(l1, l2)
print(l1, l2, o)
assert o == ListNode.createListFromNum(807)

l1 = ListNode.createListFromNum(999)
l2 = ListNode.createListFromNum(99)
o = s.addTwoNumbers(l1, l2)
print(l1, l2, o)
assert o == ListNode.createListFromNum(1098)

l1 = ListNode.createListFromNum(0)
l2 = ListNode.createListFromNum(0)
o = s.addTwoNumbers(l1, l2)
print(l1, l2, o)
assert o == ListNode.createListFromNum(0)
