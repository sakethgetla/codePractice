from typing import List

class Solution:
    def hasSameDigits(self, s: str) -> bool:
        
        def calc(st: List[int])-> List[int]:
            newS =[]
            for i in range(0, len(st)-1):
                newS.append(( st[i] + st[i+1] )%10)


            return calc(newS) if len( newS ) > 2 else newS

        o = calc([int( c ) for c in s])
        ss = set(o)
        return len(ss) == 1


s = Solution()
st = '3902'
o = s.hasSameDigits(st)
print(st, o)
assert o == True

st = '34789'
o = s.hasSameDigits(st)
print(st, o)
assert o == False

