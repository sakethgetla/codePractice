from typing import Optional

from listNode import ListNode

class Solution:

    def getLen(self, head: Optional[ListNode]) -> int:
        return 1 + self.getLen(head.next) if head != None else 0

    def removeNode(self, head: Optional[ListNode], n: int):
        if n == 1 :
            if head.next != None:
                head.next = head.next.next
            # else: 
            # return head
        else:
            self.removeNode(head.next, n-1)
        # return 

    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == None:
            return None
        length = self.getLen(head)
        self.removeNode(head, int(length//2))
        return head

    # def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
    #     if head == None:
    #         return None
    #     if head.next == None:
    #         return None
    #     if head.next.next == None:
    #         head.next = None
    #         return head
    #
    #
    #     mid = head
    #     curr = head.next.next
    #     while (curr.next != None):
    #         mid = mid.next
    #         curr = curr.next
    #         if (curr.next != None):
    #             curr = curr.next
    #
    #     mid.next = mid.next.next
    #     return head
    #


        

s = Solution()
# l = ListNode(1, None)
l = ListNode(1, ListNode(2, None))
# l = ListNode(1, ListNode(2, ListNode(3, ListNode(4, None))))
# l = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(2, ListNode(3, ListNode(4, None)))) )))
print(l)
o = s.deleteMiddle(l)
print(o)
