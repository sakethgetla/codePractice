from typing import List

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        st = []
        for a in asteroids:
            if len(st)>0 and a < 0 and st[-1] > 0: 
                ac = st.pop()
                while len(st) > 0 and ac > 0 and ac + a < 0 :
                    ac = st.pop()

                if ac < 0 :
                    st.append(ac)
                    st.append(a)
                elif ac + a == 0:
                    pass
                elif ac + a > 0:
                    st.append(ac)
                elif len(st)==0:
                    st.append(a)

            else:
                st.append(a)
        return st

            

        

s = Solution()
input = [5, 10,-5]
output = s.asteroidCollision(input)
print (input, output)
assert output == [5,10]

input = [9,-9]
output = s.asteroidCollision(input)
print (input, output)
assert output == []

input = [15, 2,-5]
output = s.asteroidCollision(input)
print (input, output)
assert output == [15]

