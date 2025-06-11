class Solution:
    def numTilings(self, n: int) -> int:
        def dp(n: int) -> int:
            match n:
                case 1:
                    return 1
                case 2:
                    return 2
                case 3:
                    return 5
                case 4:
                    return 11
                case _:
                    return dp(4) + dp(n-4) + dp(3) + dp(n-3)+ dp(2) + dp(n-2)+ dp(1) + dp(n-1)
        return dp(n)

s = Solution()
n = 5
o = s.numTilings(n)
print(n, o)
assert o == 24


