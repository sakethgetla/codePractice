#class Solution:
    #def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def createList(l):
    ans = None
    #if (l != None and len(ans) >= 1):
    if (len(l) >= 1):
        ans = ListNode(l[0])
    if (len(l) >= 2):
        ans.next = createList(l[1:])
    return ans


#def mergeTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
def mergeTwoLists(l1, l2):
    if(l1 == None and l2 == None): return None
    if(l1 == None or ( l2 != None and l1.val > l2.val)):
        ans = l2
    else:
        ans = l1
    ans.next = mergeTwoLists(l1.next, l2.next)
    return ans

    
def printList(l):
    if(l != None):
        print(l.val, end="")
        printList(l.next)
    else :
        print("")

#printList(createList([1, 2, 3]))
#printList(createList([1, 2, 3, 7, 90]))
#printList(createList([]))
#printList(createList([1]))

l1 = createList([1, 2, 3, 7, 90])
l2 = createList([1, 2, 3, 7, 90])

printList(l1)
printList(l2)
printList(mergeTwoLists(l1, l2))


        #answer = ListNode(-1)
        #ans = answer
        ##while(l1.val != None and l2.val != None):
        #while(l1 != None or l2 != None):
        #    if(l1 == None or ( l2 != None and l1.val > l2.val)):
        #        ans.next = l2
        #        l2 = l2.next
        #    else:
        #        ans.next = l1
        #        l1 = l1.next
        #    ans = ans.next
        #return answer.next
        
