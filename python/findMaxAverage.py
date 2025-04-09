from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        maxAvg = 0
        sum = 0

        for i in range( len(nums) ):
            nums[i] /= k

        for i in range(k):
            sum += nums[i]
        maxAvg = sum

        # avg = maxAvg
        for i in range(len( nums ) - k):
            sum -= nums[i] 
            sum += nums[( i+k )]
            maxAvg = sum if maxAvg < sum else maxAvg
        
        return maxAvg



    # def findMaxAverage(self, nums: List[int], k: int) -> float:
    #     maxAvg = 0
    #     sum = 0
    #     for i in range(k):
    #         sum += nums[i]
    #     maxAvg = sum/ k
    #
    #     # avg = maxAvg
    #     for i in range(len( nums ) - k):
    #         sum -= nums[i] 
    #         sum += nums[( i+k )]
    #         maxAvg = sum / k if maxAvg < sum /k else maxAvg
    #     
    #     return maxAvg
    #
    #

a = [1,12,-5,-6,50,3]
k = 4
# a = [5]
# k = 1

c = Solution()
d = c.findMaxAverage(a, k)
print(a, k, d)
