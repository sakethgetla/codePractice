# from typing import Boolean

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        # def isVowel(s: str): 
        #     # return true if len(s) == 1 and s in 'aeiou' else false
        #     return len(s) == 1 and s in 'aeiou' 
        mVowels = 0
        currVowels = 0
        for i in range(len(s)):
            # currVowels += 1 if isVowel(s[i]) else 0
            # currVowels -= 1 if i >= k and isVowel(s[i-k]) else 0
            currVowels += 1 if s[i] in 'aeiou' else 0
            currVowels -= 1 if i >= k and s[i-k] in 'aeiou' else 0
            mVowels = max( mVowels, currVowels )
        return mVowels

s = Solution()
i = 'abciiidef'
k = 3
out = s.maxVowels(i, k)
print(i, out)


