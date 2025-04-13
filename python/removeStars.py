class Solution:
    def removeStars(self, s: str) -> str:
        out = []
        for c in s:
            if c == '*':
                out.pop()
            else:
                out.append(c)
        return ''.join(out)


c = Solution()
a = "leet**cod*e"
b = c.removeStars(a)
print(a, b)
