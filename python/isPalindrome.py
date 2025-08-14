import math


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0 or x%10 == 0) and x != 0:
            return False
        elif x < 10:
            return True


        reverse = 0
        while x > reverse:
            reverse *= 10
            reverse += x%10
            x //= 10
            # reverse += 10 - (reverse % 10) + (x % 10)
        return reverse == x or reverse // 10 == x

    # def isPalindrome(self, x: int) -> bool:
    #     if x < 0:
    #         return False
    #     while x > 9:
    #         mag = int(math.log10(x))
    #         firstDigit = x // pow(10, mag)
    #         lastDigit = x % 10
    #         # print(">", x, mag, firstDigit, lastDigit, firstDigit * pow(10, mag))
    #         if lastDigit != firstDigit:
    #             return False
    #         x -= firstDigit * pow(10, mag)
    #         x //= 10
    #         # print('<',x)
    #
    #         if x > 0 and mag != 2 + int(math.log10(x)):
    #             # print("<", x, mag, int(math.log10(x)))
    #             for _ in range(mag - 2 - int(math.log10(x))):
    #                 # print('here', x,x%10)
    #                 if x % 10 != 0:
    #                     return False
    #                 x //= 10
    #     return True

    # def isPalindrome(self, x: int) -> bool:
    #     if x < 0 :
    #         return False
    #     stk = []
    #     while x > 0:
    #         stk.append(x%10)
    #         x = x //10
    #     even = len(stk) % 2 == 0
    #
    #     i = 0
    #     j = len(stk) -1
    #     while i < j:
    #         if stk[i] != stk[j]:
    #             return False
    #         i +=1
    #         j -= 1
    #     return True


s = Solution()

n = 121
o = s.isPalindrome(n)
print(n, o)
assert o == True

n = -202
o = s.isPalindrome(n)
print(n, o)
assert o == False

n = 2112
o = s.isPalindrome(n)
print(n, o)
assert o == True

n = 2012
o = s.isPalindrome(n)
print(n, o)
assert o == False

n = 20
o = s.isPalindrome(n)
print(n, o)
assert o == False


n = 20011002
o = s.isPalindrome(n)
print(n, o)
assert o == True

n = 0
o = s.isPalindrome(n)
print(n, o)
assert o == True

n = 200000000012
o = s.isPalindrome(n)
print(n, o)
assert o == False
