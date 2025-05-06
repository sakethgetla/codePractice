from typing import List

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        dic = {}
        for r in grid:
            a = ','.join([ str(c) for c in r ])
            if a in dic:
                dic[a] += 1
            else:
                dic[a] =1

        pairs = 0
        for j in range(len( grid ) ):
            a = ','.join( [str(grid[i][j]) for i in range( len( grid ) )] )
            if a in dic:
                pairs += dic[a]
        # print(dic)
        return pairs

            # for i in range(len( grid ) ):
            #     grid
            


s = Solution()
g = [[3,2,1],[1,7,6],[2,7,7]]
o = s.equalPairs(g)
print(g, o)
assert o== 1

g = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
o = s.equalPairs(g)
print(g, o)
assert o== 3


