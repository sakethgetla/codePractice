class ListNode:
    # def __init__(self, val: int, next: ListNode):
    def __init__(self, val, next):
        self.val = val
        self.next = next

    def __str__(self):
    # printList(self):
        s = str( self.val )
        if (self.next != None):
            s += '->' + str( self.next )
        return s

# l = ListNode(1, ListNode(0, ListNode(21, None)))
# print(l)
