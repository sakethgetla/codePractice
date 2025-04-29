# class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) < len( str2 ):
            return self.gcdOfStrings(str2, str1)
        elif str1 == str2:
            return str2
        elif len(str1) % len(str2) == 0:
            # print(str1[len(str2):], str2)
            return str2 if str1[:len(str2)] == str2 and self.gcdOfStrings(str1[len(str2):], str2) == str2 else ''
        else:
            for i in range(2,  len(str2) ):
                divisorLen = len(str2)//i
                # print('>', divisorLen, i)
                if(len(str2)%divisorLen == 0 and len(str1)%divisorLen == 0):
                    newDivisor = str2[:divisorLen]
                    # print('>', str1, str2, newDivisor)
                    return newDivisor if newDivisor == self.gcdOfStrings(str1, newDivisor) and newDivisor == self.gcdOfStrings(str2, newDivisor) else ''
        return ''







        # def f(s1: str, s2: str, m: str) -> bool:
        #     if len(s1) < len(m) or len(s2) < len(m):
        #         return False
        #     else:
        #         return (s1 != '' and s1[:len(m)] == m) and ( s2!='' and s2[:len(m)] == m) and f(s1[len(m):], s2[len(m):], m)
        
            


s = Solution()
s1 = 'abcabc'
s2 = 'abc'
o = s.gcdOfStrings(s1, s2)
print(s1, s2, o)
assert o == 'abc'

s1 = 'ab'
s2 = 'abc'
o = s.gcdOfStrings(s1, s2)
print(s1, s2, o)
assert o == ''

s1 = 'abababab'
s2 = 'abab'
o = s.gcdOfStrings(s1, s2)
print(s1, s2, o)
assert o == 'abab'

s1 = 'abcabc'
s2 = 'abca'
o = s.gcdOfStrings(s1, s2)
print(s1, s2, o)
assert o == ''



# "NLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGM"
# "NLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGM"
s1 = "NLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGM"
s2 = "NLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGM"
o = s.gcdOfStrings(s1, s2)
print(s1, s2, o)
assert o == "NLZGM"

