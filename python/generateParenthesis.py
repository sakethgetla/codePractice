from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        l = ['(']
        cnt = [(n-1, n)]
        i = 0
        while i < len(l):
            while len(l[i]) < n*2:
                if cnt[i][0] > 0 and cnt[i][0] < cnt[i][1]:
                    l.append(l[i] + ')')
                    cnt.append(( cnt[i][0], cnt[i][1]-1 ))
                if cnt[i][0] > 0:
                    l[i] += '('
                    cnt[i] = ( cnt[i][0]-1, cnt[i][1] )
                else:
                    l[i] += ')'
                    cnt[i] = ( cnt[i][0], cnt[i][1]-1 )
                # print(l[i])
            i +=1
        return l


        


        # def dp(n: List[str], cnt: int)-> List[str]:
        #     newN = n * 2
        #     for i in range(len(newN)):
        #         newN[i] += '(' if i >= len(newN) //2 else ')'
        #     return newN if cnt == 1 else dp(n, cnt-1)
        # return dp([], )
        #

s = Solution()

n = 3
o = s.generateParenthesis(n)
print(n, o)
# assert o == ["((()))","(()())","(())()","()(())","()()()"]
assert len(o) == 5
 
n = 6
o = s.generateParenthesis(n)
print(n, o)
# assert o == ["((()))","(()())","(())()","()(())","()()()"]
assert len(o) == 5

