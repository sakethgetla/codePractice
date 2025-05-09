class Solution:
    # # easy, I
    # def distributeCandies(self, n: int, limit: int) -> int:
    #     cnt = 0
    #     for j in range(limit+1):
    #         for i in range(limit+1):
    #             if n-i-j >= 0 and n-i-j <= limit:
    #                 print('>', n-i-j, i, j)
    #                 cnt += 1
    #     return cnt
    #

    # mid, II
    def distributeCandies(self, n: int, limit: int) -> int:
        firstMin = max(0, n-limit-limit)
        firstMax = min(n, limit)

        cnt = 0
        for i in range(firstMin, firstMax+1):
            secondMin = max(n-i-limit, 0)
            secondMax = min(n-i, limit )
            cnt += secondMax- secondMin +1
        return cnt



    # # easy, I, doesnt work
    # def distributeCandies(self, n: int, limit: int) -> int:
    #     s = set()
    #     if limit *3 < n :
    #         return 0
    #     def f(a:int, b:int, c:int) -> int:
    #         # print('>',a,b,c)
    #         s.add(str(a)+ str(b) + str(c))
    #         cnt = 1
    #         # if c == limit or c == n:
    #         #     return cnt
    #
    #         if a > 0 and b < limit:
    #             cnt += f(a-1, b+1, c)
    #
    #         if b > 0 and c < limit:
    #             cnt += f(a, b-1, c+1)
    #
    #         return cnt
    #     f(min(n, limit), min( max( n-limit,0 ), limit ), min( max(0, n-limit-limit ), limit))
    #     return len(s)

    # # mid, II
    # def distributeCandies(self, n: int, limit: int) -> int:
    #     def f(a:int, b:int, c:int) -> int:
    #         print(a,b,c)
    #         cnt = 1
    #         # if c == limit or c == n:
    #         #     return cnt
    #
    #         if a > 0 and b < limit:
    #             cnt += f(a-1, b+1, c)
    #
    #         if b > 0 and c < limit:
    #             cnt += f(a, b-1, c+1)
    #
    #         return cnt
    #     return f(min(n, limit), min( max( n-limit,0 ), limit ), min( max(0, n-limit-limit ), limit))

s = Solution()
n = 5
limit = 2
o = s.distributeCandies(n, limit)
print(n, limit, o)
assert o == 3
#
n = 3
limit = 3
o = s.distributeCandies(n, limit)
print(n, limit, o)
assert o == 10

n = 1
limit = 4
o = s.distributeCandies(n, limit)
print(n, limit, o)
assert o == 3

n = 11
limit = 10
o = s.distributeCandies(n, limit)
print(n, limit, o)
assert o == 75

n = 4
limit = 1
o = s.distributeCandies(n, limit)
print(n, limit, o)
assert o == 0

