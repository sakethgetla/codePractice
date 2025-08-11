from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = [[1]]
        while len(triangle) < numRows:
            currRow = [1]
            for i in range(len(triangle[-1])-1):
                currRow.append(triangle[-1][i] + triangle[-1][i+1])
            currRow.append(1)
            triangle.append(currRow)
        return triangle


s = Solution()
n = 1
o = s.generate(n)
print (n, o)
assert o == [[1]]

n = 5
o = s.generate(n)
print (n, o)
assert o == [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
