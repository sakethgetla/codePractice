class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        a = [[0 for i in range(n+1)] for j in range(m+1)]
        a[0][0] = 1
        print (a)
        for j in range( m ):
            for i in range( n ):
                a[j][i+1] += a[j][i]
                a[j+1][i] += a[j][i]
        print (a)
        # return a[m-1][n-1-1] + a[m-1-1][n-1]
        return a[m-1][n-1]




s = Solution()

# m = 7
# n = 3

m = 3
n = 2
a = s.uniquePaths(m, n)
print (a)
