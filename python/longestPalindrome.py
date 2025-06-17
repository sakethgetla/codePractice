class Solution:
    def longestPalindrome(self, s: str) -> str:
        # ar = [s[0]]
        mxP = s[0]
        # for c in s[1:]:
        for j in range(len(s) -1):
            i = j+1
            z = 0
            while z < i and z+i+1 < len(s) and s[i-z-1] == s[i+z+1]:
                z += 1
            mxP = mxP if len(mxP) > len(s[i-z: i+z+1]) else s[i-z: i+z+1]
            z = 0
            while z < i and z+i < len(s) and s[i-z-1] == s[i+z]:
                z += 1
            mxP = mxP if len(mxP) > len(s [i-z: i+z] ) else s[i-z: i+z]
        return mxP


s = Solution()
a = 'babad'
o = s.longestPalindrome(a)
print(a, o)

a = 'cbbd'
o = s.longestPalindrome(a)
print(a, o)

a = 'bbbb'
o = s.longestPalindrome(a)
print(a, o)
