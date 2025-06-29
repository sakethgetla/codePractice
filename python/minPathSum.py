from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
      prevRowCost = [float('inf') for n in grid[0]]
      prevRowCost[0] = 0
      # prevRowCost = [n for n in grid[0]]
      # prevRowCost = grid[0]
      # prevTileCost = 0
      # currRowCost = [0 for _ in len(grid[0])]

      for row in grid:
        for i in range( len( row ) ):
          mn = min(prevRowCost[i], prevRowCost[i-1] if i > 0 else float('inf'))
          prevRowCost[i] = mn + row[i]
        # print(prevRowCost)
      return prevRowCost[-1]



        

s = Solution()
n = [[1,3,1],[1,5,1],[4,2,1]]
o = s.minPathSum(n)
print (n, o)
assert o == 7

n = [[1],[ 2 ],[3]]
o = s.minPathSum(n)
print (n, o)
assert o == 6

n = [[1,2,3]]
o = s.minPathSum(n)
print (n, o)
assert o == 6

n = [[1,2,3],[4,5,6]]
o = s.minPathSum(n)
print (n, o)
assert o == 12

