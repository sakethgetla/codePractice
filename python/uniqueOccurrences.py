from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        dic = {}
        s = set()
        print(type( s ), type( dic ))
        for n in arr:
            if (n in dic):
                dic[n] += 1
            else :
                dic[n] = 1

        for occ in dic.values():
            if occ in s:
                return False
            else:
                s.add(occ)
        return True

s = Solution()
a = [1,2]
o = s.uniqueOccurrences(a)
print(a,o)
assert o == False

a = [1,2,2,1,1,3]
o = s.uniqueOccurrences(a)
print(a,o)
assert o == True

