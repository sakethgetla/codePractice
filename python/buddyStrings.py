from typing import List

class Solution:
    # dp, very slow
    def buddyStrings(self, st: str, goal: str) -> bool:
        if len(st) != len( goal ):
            return False

        dic = {}
        for i in range(len(st)):
            if not st[i] in dic or (st[i] in dic and dic[st[i]] == st[i]) :
                dic[st[i]] = i
                
            if goal[i] in dic:
                if (st[0:dic[goal[i]]] + st[i] + st[dic[goal[i]]+1:i] + st[dic[goal[i]]] + st[i+1:]) == goal:
                    return True
                    

        return False

    # # brute force
    # def buddyStrings(self, st: str, goal: str) -> bool:
    #     for i in range(len(st)-1):
    #         for j in range(i+1, len(st)):
    #             # print(i,j)
    #             # print(st[0:i] , st[j] , st[i+1:j] , st[i] , st[j+1:])
    #             # print(st[0:i] + st[j] + st[i+1:j] + st[i] + st[j+1:], goal)
    #             if (st[i] == goal[j] and st[j] == goal[i]):
    #                 if (st[0:i] + st[j] + st[i+1:j] + st[i] + st[j+1:]) == goal:
    #                     return True
    #
    #     return False



    # def buddyStrings(self, st: str, goal: str) -> bool:
    #     if len(st) != len( goal ):
    #         return False
    #
    #     i, j = 0, len(st)-1
    #     while i < j:
    #         if (st[i] == goal[j] and st[j] == goal[i]):
    #             print(i, j)
    #             if (st[0:i] + st[j] + st[i+1:j] + st[i] + st[j+1:]) == goal:
    #                 return True
    #             i += 1
    #             j -=1
    #
    #         elif (st[j] != goal[j] and st[i] != goal[i] ):
    #             return False
    #
    #         if (st[i] == goal[i]):
    #             i += 1
    #         if (st[j] == goal[j]):
    #             j -=1
    #
    #     return False
    #     


    # def buddyStrings(self, st: str, goal: str) -> bool:
    #     if len(st) != len(goal):
    #         return False
    #
    #     self.swapped = False
    #     def dp(s: List[str], g: List[ str ])-> bool:
    #         # print(s, g)
    #         if len(s) == len(g) == 1 and s[0] == g[0]:
    #             return True 
    #
    #         # if s[0] != g[0]:
    #         for i in range(1, len(s)):
    #             if s[i] == g[0]:
    #                 # swap
    #                 s[i] = s[0]
    #                 s[0] = g[0]
    #                 self.swapped = True
    #
    #         if s[0] == g[0] :
    #             return dp(s[1:], g[1:])
    #         else: 
    #             return False
    #
    #     # print( dp([ c for c in st ], [ c for c in goal ]) , self.swapped)
    #     return dp([ c for c in st ], [ c for c in goal ]) and self.swapped

# False
a = 'abdc'
b = 'bacd'
s = Solution.buddyStrings(Solution(), a, b)
assert s == False
print(a,b,s)

# True
a = 'abc'
b = 'bac'
s = Solution.buddyStrings(Solution(), a, b)
assert s == True
print(a,b,s)

# True
a = 'ab'
b = 'ba'
s = Solution.buddyStrings(Solution(), a, b)
assert s == True
print(a,b,s)

# True
a = 'aa'
b = 'aa'
s = Solution.buddyStrings(Solution(), a, b)
assert s == True
print(a,b,s)

# False
a = 'ab'
b = 'ab'
s = Solution.buddyStrings(Solution(), a, b)
assert s == False
print(a,b,s)

# False
a = 'aaaaaabc'
b = 'aaaaaacb'
s = Solution.buddyStrings(Solution(), a, b)
assert s == True
print(a,b,s)

a = 'aba'
b = 'abab'
s = Solution.buddyStrings(Solution(), a, b)
assert s == False
print(a,b,s)

a = 'abab'
b = 'abab'
s = Solution.buddyStrings(Solution(), a, b)
assert s == True
print(a,b,s)

# s = Solution.buddyStrings(Solution(), a, b)
# assert s == False
# print(a,b,s)


