# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def addTwoNumbers(l1, l2):
    return add(l1, l2, 0)

def add(l1, l2, carry):
    if( l2 != None and l1 != None):
        sum = carry
        ll1 = l1
        ll2 = l2
        if( l1 != None):
            sum += l1.val
            ll1 = l1.next
        if( l2 != None):
            ll2 = l2.next 
            sum += l2.val
            #sum = sum%10
        new = ListNode(sum%10)
        new.next = add(ll1, ll2, sum//10)
        return new
    elif(carry > 0) :
        return ListNode(carry)
    else :
        return None



        
