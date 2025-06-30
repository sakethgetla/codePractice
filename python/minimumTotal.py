from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
      for rowIndex in range(1, len(triangle)):
        for i in range(len(triangle[rowIndex])):
          mn = triangle[rowIndex-1][i] if i == 0 else triangle[rowIndex-1][i-1] if i == len(triangle[rowIndex]) -1 else min(triangle[rowIndex-1][i], triangle[rowIndex-1][i-1])
          triangle[rowIndex][i] += mn
      return min(triangle[-1])


s = Solution()
n = [[-11]]
o = s.minimumTotal(n)
print (n, o)
assert o == -11

n = [[2],[-3,4],[6,5,7],[4,1,8,3]]
o = s.minimumTotal(n)
print (n, o)
assert o == 5

