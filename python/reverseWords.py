class Solution:
    def reverseWords(self, s: str) -> str:
        stack = []
        word = ''
        for c in s:
            if c == ' ' and len(word) > 0:
                stack.append(word)
                word = ''
            elif c != ' ':
                word += c
        if len( word ) > 0:
            stack.append(word)

        out = []
        while len(stack):
            out.append(stack.pop())


        # return out.join(" ")
        return " ".join(out)




s = Solution()
a = "the sky is blue   "
o = s.reverseWords(a)
print(o)
