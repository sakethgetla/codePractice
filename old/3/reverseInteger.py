# leetCode question, ans by saketh
# Mon 16 Dec 20:19:52 AEDT 2019

def reverseInteger(x):
    l = []
    
    print(f"x = {x}, 2**31 = {2**31} x > pow = {x > 2**31}")
    print(x)
    power = 2**31
    print(power)
    if ( x > pow(2, 31) -1 or x <  -1 * pow(2, 31)): return 0
    negative = False
    if (x < 0):
        x *= -1
        negative = True
        
    createlist(x, l) 
    ans = createInt(l)
    if (negative) :
        ans *= -1 
    if ( ans > pow(2, 31) -1 or ans <  -1 * pow(2, 31)): return 0
    return ans


def createlist(x, l):
    if(x != 0):
        createlist(x//10, l)
        l.append(x%10)

def createInt(l):
    if(len(l) != 0):
        num = l[0]
        #l.pop(0)
        #num *= 10
        return num + (10*createInt(l[1:]))
    return 0

print(reverseInteger(1534236469))
