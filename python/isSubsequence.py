class Solution:
    # def isSubsequence(self, s: str, t: str) -> bool:


    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        # if len(s) > len(t):
        #     return False
        j = 0 
        for c in t:
            if(s[j] == c):
                j+=1
            if (j == len(s)):
                return True
        return False
                

s = Solution()
a = 'abc'
b = 'ahbgdc'
o = s.isSubsequence(a,b)
print(a, b, o)
assert o == True

a = 'acb'
b = 'acbgdc'
o = s.isSubsequence(a,b)
print(a, b, o)
assert o == True

a = 'ahbgdc'
b = 'acb'
o = s.isSubsequence(a,b)
print(a, b, o)
assert o == False
