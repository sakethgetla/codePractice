class Solution:
    def divisorGame(self, n: int) -> bool:
        # a = [False for _ in range(max(4,  n+1 ))]
        a = [False for _ in range(n+1)]
        for i in range(1, n+1):
            for j in range(1, i):
                if i % j == 0 and a[i-j] == False:
                    a[i] = True
        return a[n]


    # def divisorGame(self, n: int) -> bool:
    #     a = [None for _ in range(max(4,  n+1 ))]
    #     a[1] = False
    #     a[2] = True
    #     a[3] = False
    #     def dp(np:int) -> bool:
    #         newN = 1
    #         x = np - newN
    #         # print(x, newN, np)
    #         # while newN <= np/2 and np%x == 0:
    #         while newN <= np/2:
    #             x = np - newN
    #             if np%x == 0:
    #                 print(x, newN, np)
    #                 match a[newN]:
    #                     case False:
    #                         # a[np] = True
    #                         return True
    #                     case None:
    #                         a[newN] = dp(newN)
    #                         return a[newN]
    #             newN += 1
    #         return False
    #     o = dp(n)
    #     print(a)
    #     return o
    #
    #



    # def divisorGame(self, n: int) -> bool:
    #     def possible(x: int)-> bool:
    #         return n > x and x > 0 and n % x == 0
    #     turn = 0
    #     newX = n -1
    #     while n > 1 and newX > 0:
    #         if possible(newX):
    #             n = n - newX
    #             newX = n -1
    #             turn +=1
    #         else :
    #             newX -=1
    #         print(newX, n)
    #     return turn % 2 == 1


s = Solution()

n = 2
o = s.divisorGame(n)
print (n, o)
assert o == True

n = 3
o = s.divisorGame(n)
print (n, o)
assert o == False


#

n = 200
o = s.divisorGame(n)
print (n, o)
assert o == True

n = 100
o = s.divisorGame(n)
print (n, o)
assert o == True

n = 4
o = s.divisorGame(n)
print (n, o)
assert o == True




# a[] is array of how wins at each n
# ie a[n] == true then alice wins at n
# newX = n - x
