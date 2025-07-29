class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False

        stk = []
        for c in s:
            if c == "(" or c == "{" or c == "[":
                stk.append(c)
            elif len(stk) > 0 and (
                (c == ")" and stk[-1] == "(")
                or (c == "}" and stk[-1] == "{")
                or (c == "]" and stk[-1] == "[")
            ):
                stk.pop()
            else:
                return False
        return True if len(stk) == 0 else False


s = Solution()
n = "()[]{}"
o = s.isValid(n)
print(n, o)
assert o == True

n = "()"
o = s.isValid(n)
print(n, o)
assert o == True

n = "()]{}"
o = s.isValid(n)
print(n, o)
assert o == False

n = "}}"
o = s.isValid(n)
print(n, o)
assert o == False

n = "(((("
o = s.isValid(n)
print(n, o)
assert o == False
