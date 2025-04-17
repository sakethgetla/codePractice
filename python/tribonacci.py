class Solution:
    cal = {0: 0, 1: 1, 2: 1}
    def tribonacci(self, n: int) -> int:
        if n in Solution.cal:
            return Solution.cal[n]
        else:
            Solution.cal[n] = self.tribonacci(n-3) + self.tribonacci(n-2) + self.tribonacci(n-1)
            return Solution.cal[n]

        # match n:
        #     case 0:
        #         return 0
        #     case 1 | 2:
        #         return 1
        #     case _ :
        #         return self.tribonacci(n-3) + self.tribonacci(n-2) + self.tribonacci(n-1)

        

s = Solution()
for i in range(40):
    print(i, s.tribonacci(i))
