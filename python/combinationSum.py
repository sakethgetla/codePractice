from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # def dp(combinations: List[List[int]], sum: int) ->List[List[int]]:
        def dp(s: int) -> List[List[int]]:
            newCombinations = []
            for c in candidates:
                newCombination = []
                if s == c:
                    # newCombination = [[c]]
                    newCombination.append([c])
                # elif s > c + 1:
                elif s - c > 1:
                    newCombination = dp(s - c)

                if len(newCombination) > 0 and newCombination[0] != None:
                    # if len(newCombination) > 0:
                    # newCombinations.append([com.append(c) for com in newCombination])
                    # [com.append(c) for com in newCombination]
                    for com in newCombination:
                        com.append(c)
                    newCombinations.append([newCombination])
                    print(newCombinations, newCombination)
            return newCombinations

        return dp(target)


s = Solution()
n = [2, 3, 6, 7]
t = 7
o = s.combinationSum(n, t)
print(n, o)
assert o == [[2, 2, 3], [7]]
