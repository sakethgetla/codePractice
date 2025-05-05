class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len( word2 ) != len(word1):
            return False
        def createDic(word:str):
            dic = {}
            for c in word:
                if c in dic:
                    dic[c] += 1
                else:
                    dic[c] = 1
            return dic
        dic1 = createDic(word1)
        dic2 = createDic(word2)

        # s1 = dic1.values().sort()
        # s1 = [ f for f in dic1.values() ].sort()
        # s2 = [  f for f in dic2.values() ].sort()
        # s1 = dic1.values()
        # s2 = dic2.values()
        s1 = [f for f in dic1.values() ]
        s2 = [f for f in dic2.values() ]
        s1.sort()
        s2.sort()
        # s1 = set(dic1.values())
        # s2 = set(dic2.values())

        print(dic1, dic2)
        # print(s1, s2)
        # print(s1.sort(), s2.sort())
        print(s1, s2)
        # print(s1.sort(), s2.sort())
        return s2 == s1 and dic1.keys() == dic2.keys()
        # return s2 == s1 and set( dic1.keys() ) == set( dic2.keys() )
        # return True if (s2 == s1) else False

        # for k in dic1.keys():
        #     if dic1[k] != dic2[k]:
        #         return False
        # return True




    # def closeStrings(self, word1: str, word2: str) -> bool:
    #     if len( word2 ) != len(word1):
    #         return False
    #
    #     if (word1[0] != word2[0]):
    #         # swap
    #         for i in range(1, len(word2)):
    #             if ( )
    #
    #
    #
    #     # if:
    #     return True if len(word1) == 1 and word1[0] == word2[0] else self.closeStrings(word1[1:], word2[1:])


s = Solution()
w1 = "abc"
w2 = "bca"
o = s.closeStrings(w1, w2)
print(w1, w2, o)
assert o == True

        
w1 = "uau"
w2 = "ssx"
o = s.closeStrings(w1, w2)
print(w1, w2, o)
assert o == False

        
        
w1 = "aaabbbbccddeeeeefffff"
w2 = "aaaaabbcccdddeeeeffff"
o = s.closeStrings(w1, w2)
print(w1, w2, o)
assert o == False

        
        
w1 = "cabbba"
w2 = "abbccc"
o = s.closeStrings(w1, w2)
print(w1, w2, o)
assert o == True
