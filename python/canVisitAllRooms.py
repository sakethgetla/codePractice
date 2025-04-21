from typing import List, Set

class Solution:

    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        v = set()

        def dfs(curr: int):
            v.add(curr)
            for key in rooms[curr]:
                if (key not in v ):
                    dfs(key) 
                # if (key not in v and dfs(key) == True):
                #     return 
            return


        dfs(0)
        return len(v) == len(rooms)

    # visited = set()

    # def travel (self, rooms: List[List[int]], curr: int, visited: Set[int]) -> bool:
    #     visited.add(curr)
    #     if ( len(visited) == len( rooms )):
    #         return True
    #
    #     for key in rooms[curr]:
    #         if (key not in visited and self.travel(rooms, key, visited)):
    #             return True
    #     return False
    #
    #
    # def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
    #     if len(rooms )== 0:
    #         return True
    #     s = set()
    #     return self.travel(rooms, 0, s)
    #
    #
    #     
       

s = Solution()
# rooms = [[1],[2],[3],[]]
# rooms = [[1,3],[3,0,1, 2],[2],[0]]
rooms = [[1,3],[3,0,1],[2],[0]]

out = s.canVisitAllRooms(rooms)
print(rooms, out)
