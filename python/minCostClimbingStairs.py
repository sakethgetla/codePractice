from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        prevprev = cost[0]
        prev = cost[1]
        curr = 0
        for i in range(2, len( cost )):
            # print(i)
            curr = min(prev, prevprev) + cost[i]
            prevprev = prev
            prev = curr
        return min(prevprev, prev)



s = Solution()
# cost = [10, 15, 20]
cost = [1,100,1,1,1,100,1,1,100,1]
# cost = [1,2,3,1,1]
minCost = s.minCostClimbingStairs(cost)
print(minCost)
