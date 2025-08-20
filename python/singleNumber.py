from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0

        for n in nums:
            res ^= n
            print(res, n)

        return res

        # s = set()
        # for n in nums:
        #     if n in s:
        #         s.remove(n)
        #     else:
        #         s.add(n)
        #
        # for n in nums:
        #     if n in s:
        #         return n
        #
        # return 0


s = Solution()

n = [2, 2, 1]
o = s.singleNumber(n)
print(n, o)
assert o == 1

n = [1, 3, 2, 2, 1]
o = s.singleNumber(n)
print(n, o)
assert o == 3

n = [4, 1,11, 2, 2, 11, 1]
o = s.singleNumber(n)
print(n, o)
assert o == 4
