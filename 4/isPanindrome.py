# leetCode question, ans by saketh
# Tue 17 Dec 11:23:45 AEDT 2019

def isPanindrome(x):
    reverse = 0
    if (-100 < x < 100): return x%11 == 0
    while (x > reverse):
        reverse *= 10
        reverse += x%10
        x = x //10
    return x == reverse or reverse // 10 == x

print(isPanindrome(32123))
print(isPanindrome(3223))
print(isPanindrome(32213))
print(isPanindrome(100))
