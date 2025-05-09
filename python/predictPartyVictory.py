class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        q = [c for c in senate]
        
        ban = 0
        # banD = 0
        # while len(q) > 0 and len(q) != ban:
        while len(q) > 0 and len(q) >= abs( ban ):
            # print(q, ban)
            curr = q.pop(0)
            if(ban > 0):
                match curr:
                    case 'R':
                        ban += 1
                        q.append(curr)
                    case 'D':
                        ban -= 1
            elif(ban < 0):
                match curr:
                    case 'R':
                        ban += 1
                    case 'D':
                        ban -= 1
                        q.append(curr)
            else:
                match curr:
                    case 'R':
                        ban += 1
                        q.append(curr)
                    case 'D':
                        ban -= 1
                        q.append(curr)
        return 'Radiant' if q[0] == 'R' else 'Dire'

s = Solution()
ss = 'RD'
o = s.predictPartyVictory(ss)
print (ss, o)
assert o == "Radiant"

ss = 'RDD'
o = s.predictPartyVictory(ss)
print (ss, o)
assert o == "Dire"



