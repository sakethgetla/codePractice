class ListNode:
    def __init__(self, val: int, next=None):
        self.val = val
        self.next = next

    @classmethod
    def createListFromNum(cls, num: int):
        # reverse order
        node = cls(num % 10, None)
        node.next = cls.createListFromNum(num//10) if num > 9 else None
        return node

    @classmethod
    def equal(cls, l1=None, l2=None) -> bool:
        if isinstance(l1, ListNode) and isinstance(l2, ListNode):
            return l1.val == l2.val and ((l1.next == None and l2.next == None) or cls.equal(l1.next, l2.next))
        else:
            return False

    def __eq__(self, other):
        return ListNode.equal(self, other)

    def __str__(self):
        s = str( self.val )
        # if (self.next != None):
        if self.next is not None:
            s += '->' + str( self.next )
        return s

