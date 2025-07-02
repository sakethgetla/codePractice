from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = False

        digits[len(digits)-1] += 1

        curr = len(digits) -1
        while digits[curr] == 10 and curr > 0:
            digits[curr] = 0
            digits[curr-1] += 1
            curr -=1

        return digits if digits[0] != 10 else [1, 0] + digits[1:]


s = Solution()
n = [1,2,3]
o = s.plusOne(n)
print (n, o)
assert o == [1,2,4]

n = [8]
o = s.plusOne(n)
print (n, o)
assert o == [9]

n = [9]
o = s.plusOne(n)
print (n, o)
assert o == [1,0]


n = [9,9,9]
o = s.plusOne(n)
print (n, o)
assert o == [1,0,0, 0]




        
