# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

def guess(g: int) -> int:
    pick = 20
    return 0 if g == pick else 1 if g < pick else -1

class Solution:
    def guessNumber(self, n: int) -> int:
        high = n
        low = 0
        def find(low: int, high: int)-> int:
            mid = (low + high)//2
            match guess(mid):
                case 0:
                    return mid
                case -1:
                    return find(low, mid-1)
                case 1:
                    return find(mid+1, high)
        return find(low, high)

s = Solution()
o = s.guessNumber(20)
print (o)
