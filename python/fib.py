class Solution:
    def fib(self, n: int) -> int:
        mp = {0: 0, 1:1}
        def dp(n: int) -> int:
            if (n in mp):
                return mp[n]
            else :
                mp[n] = dp(n-1) + dp(n-2)
                return mp[n]
        return dp(n)
        

s = Solution()
n = 4
o = s.fib(n)
print (n, o)
assert o == 3

n = 5
o = s.fib(n)
print (n, o)
assert o == 5
