from typing import List

class Solution:
    def countBits(self, n: int) -> List[int]:
        o = [0]
        i = 0
        j = 1
        while len(o) < n +1:
            if i >= j:
                i = 0
                j *= 2
            o.append(1+o[i])
            i += 1
        return o



    # def countBits(self, n: int) -> List[int]:
    #     o = [0]
    #     a = 0
    #     for i in range(n):
    #         if o[-1] > a:
    #             a += 1
    #             o.append(1)
    #         else:
    #             o.append(o[-1] + 1)
    #     return o


        

s = Solution()
n = 2
o = s.countBits(n)
print (n, o)
assert o == [0, 1,1]

n = 5
o = s.countBits(n)
print (n, o)
assert o == [0, 1,1,2,1,2]

n = 8
o = s.countBits(n)
print (n, o)
assert o == [0,1,1,2,1,2,2,3,1]

n = 20
o = s.countBits(n)
print (n, o)
assert o == [0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2]

# 0
# 1
# 10
# 11
# 100
# 101
# 110
# 111
# 1000
# 1001
# 1010
# 1011
