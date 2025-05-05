from typing import List

class Solution:
    # def buddyStrings(self, st: str, goal: str) -> bool:
    #     swap = None
    #     if len(st) != len( goal ):
    #         return False
    #     dic = {}
    #     for i in range(len(goal)):
    #
    #
    #     for i in range(len(st)):
    #         if st[i] != goal[i]:
    #
    #



    # # dp, very slow
    # def buddyStrings(self, st: str, goal: str) -> bool:
    #     if len(st) != len( goal ):
    #         return False
    #
    #     dic = {}
    #     for i in range(len(st)):
    #         if not st[i] in dic or (st[i] in dic and dic[st[i]] == st[i]) :
    #             dic[st[i]] = i
    #             
    #         if goal[i] in dic:
    #             if (st[0:dic[goal[i]]] + st[i] + st[dic[goal[i]]+1:i] + st[dic[goal[i]]] + st[i+1:]) == goal:
    #                 return True
    #                 
    #
    #     return False
    #
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



    def buddyStrings(self, st: str, goal: str) -> bool:
        if len(st) != len( goal ):
            return False

        i, j = 0, len(st)-1
        swap = None
        while i < j:
            print(i, j, st[i], st[j], goal[i], goal[j], swap)
            if (st[j] != goal[j] and st[i] != goal[i]) :
                if (st[i] == goal[j] and st[j] == goal[i]):
                    if swap == 'must-swap':
                        return False
                    else:
                        swap = 'must-swap'
                        i += 1
                        j -=1
                else:
                    return False
            if (st[j] == st[i] and goal[i] == goal[j] and swap != 'must-swap') :
                swap = 'swapable'
            

            if (st[i] == goal[i]):
                i += 1
            if (st[j] == goal[j]):
                j -=1

        print(swap)
        return False if swap == None or (i == j and st[i] != goal[j]) else True



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
print(a,b,s)
assert s == False

# True
a = 'abc'
b = 'bac'
s = Solution.buddyStrings(Solution(), a, b)
print(a,b,s)
assert s == True

# True
a = 'ab'
b = 'ba'
s = Solution.buddyStrings(Solution(), a, b)
print(a,b,s)
assert s == True

# True
a = 'aa'
b = 'aa'
s = Solution.buddyStrings(Solution(), a, b)
print(a,b,s)
assert s == True

# False
a = 'ab'
b = 'ab'
s = Solution.buddyStrings(Solution(), a, b)
print(a,b,s)
assert s == False

# False
a = 'aaaaaabc'
b = 'aaaaaacb'
s = Solution.buddyStrings(Solution(), a, b)
print(a,b,s)
assert s == True

a = 'abcbe'
b = 'ababe'
s = Solution.buddyStrings(Solution(), a, b)
print(a,b,s)
assert s == False

a = 'aba'
b = 'abab'
s = Solution.buddyStrings(Solution(), a, b)
print(a,b,s)
assert s == False

a = 'abab'
b = 'abab'
s = Solution.buddyStrings(Solution(), a, b)
print(a,b,s)
assert s == True

# s = Solution.buddyStrings(Solution(), a, b)
# assert s == False
# print(a,b,s)


