class RecentCounter:
    def __init__(self):
        self.reqTimes = []
        

    def ping(self, t: int) -> int:
        self.reqTimes.append(t)
        while (self.reqTimes[0] < t - 3000):
            self.reqTimes.pop(0)
        return len( self.reqTimes )

        


# Your RecentCounter object will be instantiated and called as such:
obj = RecentCounter()
param_1 = obj.ping(10)
param_2 = obj.ping(20)
param_3 = obj.ping(3010)
param_4 = obj.ping(3021)

print(
param_1,
param_2,        
param_3,
param_4,
)
