class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
      paths = set( [word1] )

      dist = 0
      while True:
        # for i in range(len(paths)):
        newPaths = []
        # print(paths)
        for path in paths:
          if path == word2: 
            return dist

          j = 0
          while j +1< min(len(path), len(word2)) and path[j] == word2[j]:
            # print(len(path), len(word2), j)
            j+=1

          # print(path, word2)
          if len(path) and len(word2) and path[j] == word2[j]:
            if len(path) < len(word2):
              # insert a char after
              # print('<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< here >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>', path, path + word2[j])
              newPaths.append(path + word2[j+1])
            else:
              # delete next char
              # print('<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< here >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>', path, path[:j])
              newPaths.append(path[:-1])

          else:
            # insert a char
            if len(word2):
              newPaths.append(path[:j] + word2[j] + path[j:])

            # delete a char
            newPaths.append(path[:j] + path[j+1:])

            # replace a char
            if len(word2):
              newPaths.append(path[:j] + word2[j] + path[j+1:])

          # if len(path) > 9:
          #   print('<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< here >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>')
          #   print(paths)
          #   return 9
          #
        paths = set( newPaths )
        dist += 1




    # def minDistance(self, word1: str, word2: str) -> int:
    #   def dp(s: str)-> int:
    #     if s == word2:
    #       return 0
    #     else:
    #       mn = 0
    #       i = 0
    #       while i < min(len(s), len(word2)) and s[i] != word2[i]:
    #         i+=1
    #       
    #       # insert a char
    #       mn = min(mn, 1 + dp(s[:i] + word2[i] + s[i]))
    #       # delete a char
    #       mn = min(mn, 1 + dp(s[:i] + s[i+1]))
    #       # replace a char
    #       mn = min(mn, 1 + dp(s[:i] + word2[i] + s[i+1]))
    #
    #
        
s = Solution()
# w1='intention'
# w2='execution'
# o = s.minDistance(w1, w2)
# print (w1, w2, o)
# assert o == 5
#
#
# w1='horse'
# w2='ros'
# o = s.minDistance(w1, w2)
# print (w1, w2, o)
# assert o == 3

w1='a'
w2='ab'
o = s.minDistance(w1, w2)
print (w1, w2, o)
assert o == 1

# w1='ros'
# w2='horse'
# o = s.minDistance(w1, w2)
# print (w1, w2, o)
# assert o == 3
#

