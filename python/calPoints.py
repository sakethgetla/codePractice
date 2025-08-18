from typing import List


class Solution:
    def calPoints(self, operations: List[str]) -> int:
        # score = 0
        stk = []
        for i in range(len(operations)):
            if operations[i] == "+":
                stk.append(stk[-1]+stk[-2])

            elif operations[i] == "D":
                stk.append(stk[-1]*2)

            elif operations[i] == "C":
                stk.pop()
            else:
                stk.append(int(operations[i]))
        return sum(stk)


s = Solution()
n = ["5","-2","4","C", "C","D","9","+","+"]
o = s.calPoints(n)
print(n, o)
assert o == 29

n = ["5","-2","4","C","D","9","+","+"]
o = s.calPoints(n)
print(n, o)
assert o == 27

n = ["1", "C"]
o = s.calPoints(n)
print(n, o)
assert o == 0

n = ["5", "2", "C", "D", "+"]
o = s.calPoints(n)
print(n, o)
assert o == 30

