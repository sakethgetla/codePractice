class Solution:
    def climbStairs(self, n: int) -> int:
        
        mp = {0:0, 1:1, 2:2}
        def dp(n: int)-> int:
            if n in mp:
                return mp[n]
            else :
                calc = dp(n-2) + dp(n-1)
                mp[n] = calc
                return calc
            # match n:
            #     case 0:
            #         return 0
            #     case 1:
            #         return 1
            #     case 2:
            #         return 2
            #     case _:
            #         return dp(n-2) + dp(n-1)
        return dp(n)

s = Solution()
n = 5
o = s.climbStairs(n)
print(n, o)
# assert o == 5

n = 19
o = s.climbStairs(n)
print(n, o)
# assert o == 5

