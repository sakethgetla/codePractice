from addTwoNumbers import *

def test_addTwoNums():
    l1 = createListNum(123)
    l2 = createListNum(456)
    ans = createListNum(579)
    assert comparelists(addTwoNumbers(l1, l2), ans)

def comparelists(l1, l2):
    if (l1 == None and l2 == None):
        return True 
    if (l1.val == l2.val):
        return comparelists(l1.next, l2.next) 

def createListNum(num):
    if( num > 0 ):
        new = ListNode(num%10)
        new.next = createListNum(num//10)
        return new
    else:
        return None

def displayList(l):
    if(l != None):
        print(l.val, end = "->")
        displayList(l.next)
    else :
        print("NULL")

#displayList(createListNum(1234432))
l1 = createListNum(724)
l2 = createListNum(456)
ans = createListNum(579)
displayList(addTwoNumbers(l1, l2))
#print('\n')
displayList(ans)
