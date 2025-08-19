from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dp(cand: List[int], t: int) -> List[List[int]]:
            sums = []
            for i in range( len( cand ) ):
                if cand[i] == t:
                    sums.append([cand[i]])
                elif cand[i] < t:
                    s = dp(cand[i:], t-cand[i])
                    for a in s:
                        a.append(cand[i])
                    sums += s
            return sums
        return dp(candidates, target)




    # def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    #     # def dp(cand: List[int], t: int, o: List[List[int]]):
    #     def dp(cand: List[int], t: int) -> List[List[int]]:
    #         # print(cand, t)
    #         newSums = []
    #         # for i in range(len(cand)):
    #         for c in cand:
    #             # a = cand.pop(0)
    #             if c < t:
    #                 sums = dp(cand, t - c)
    #                 if len(sums) > 0:
    #                     for s in sums:
    #                         s.append(c)
    #                     newSums += sums
    #             elif c == t:
    #                 newSums.append([c])
    #             # cand.append(a)
    #         return newSums
    #
    #     dups =  dp(candidates, target)
    #     o = []
    #     s = set()
    #     for d in dups:
    #         d.sort()
    #         a = str(d)
    #         if a not in s:
    #             s.add(a)
    #             o.append(d)
    #     return o
    #

    # def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    #     # def dp(combinations: List[List[int]], sum: int) ->List[List[int]]:
    #     def dp(s: int) -> List[List[int]]:
    #         newCombinations = []
    #         for c in candidates:
    #             newCombination = []
    #             if s == c:
    #                 # newCombination = [[c]]
    #                 newCombination.append([c])
    #             # elif s > c + 1:
    #             elif s - c > 1:
    #                 newCombination = dp(s - c)
    #
    #             if len(newCombination) > 0 and newCombination[0] != None:
    #                 # if len(newCombination) > 0:
    #                 # newCombinations.append([com.append(c) for com in newCombination])
    #                 # [com.append(c) for com in newCombination]
    #                 for com in newCombination:
    #                     com.append(c)
    #                 newCombinations.append([newCombination])
    #                 print(newCombinations, newCombination)
    #         return newCombinations
    #
    #     return dp(target)


s = Solution()

n = [2, 3, 6, 7]
t = 7
o = s.combinationSum(n, t)
print(n, t, o)
assert o == [[3, 2, 2], [7]]

n = [2,3,5]
t = 8
o = s.combinationSum(n, t)
print(n, t, o)
assert o == [[2, 2, 2,2],[2, 3, 3], [3,5]]

n = [2]
t = 1
o = s.combinationSum(n, t)
print(n, t, o)
assert o == []
