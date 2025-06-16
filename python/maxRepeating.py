class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        dp = [0 for i in range( len( sequence ) + len( word) )]
        # dp = [0 for i in sequence ]


        for i in range(len(sequence)):
            if sequence[i:i + len(word)] == word:
                dp[i + len(word)] += dp[i - len(word) + len(word)] + 1

        # print(dp)
        return max(dp)

    # def maxRepeating(self, sequence: str, word: str) -> int:
    #     i , j = 0, 0
    #     mx, curr = 0, 0
    #     # for i in range (len ( sequence ) ):
    #     while i  < len ( sequence  ):
    #         print(i)
    #         if (sequence[i] == word[j]):
    #             j+=1
    #             if (j == len(word)):
    #                 curr +=1
    #                 j = 0
    #                 if(curr > mx):
    #                     mx = curr
    #         else:
    #             # print('herer')
    #             i = i - j- ( len(word) * curr )
    #             curr = 0
    #             j = 0
    #         
    #         i += 1
    #
    #     return mx


        

s = Solution()
sq = 'abababcababad'
w = 'abd'
o = s.maxRepeating(sq, w)
print (sq, w, o)
assert o == 0

sq = 'aaabaaaabaaabaaaabaaaabaaaabaaaaba'
w = 'aaaba'
o = s.maxRepeating(sq, w)
print (sq, w, o)
assert o == 5

