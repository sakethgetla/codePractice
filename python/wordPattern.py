class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        mp = {}
        st = set()
        j = 0
        p = 0
        for i in range(len(s)):
            if i + 1 == len(s) or s[i+1] == ' ':
                wd = s[j:i+1]
                # print(wd)
                if p == len(pattern):
                    return False
                if pattern[p] in mp:
                    if mp[pattern[p]] != wd:
                        # {a: 'pog'}
                        # print(mp)
                        # print(st)
                        return False
                    # else:
                        # contine
                        # {a: 'dog'}
                        # p += 1
                        # j = i + 2
                else:
                    if wd in st:
                        # {b: 'dog'}
                        # print(mp)
                        # print(st)
                        return False
                    else:
                        # {b: 'pog'}
                        mp[pattern[p]] = wd
                        st.add(wd)
                p += 1
                j = i + 2

        # print(mp)
        # print(st)
        return p == len(pattern)





        
s = Solution()
p = 'aaa'
st = 'd d'
o = s.wordPattern(p, st)
print(p, st, o)
assert o == False

p = 'a'
st = 'd d'
o = s.wordPattern(p, st)
print(p, st, o)
assert o == False

p = 'abba'
st = 'dog cat cat dog'
o = s.wordPattern(p, st)
print(p, st, o)
assert o == True

p = 'abbb'
st = 'dog cat cat dogs'
o = s.wordPattern(p, st)
print(p, st, o)
assert o is False

p = 'abba'
st = 'dog cat cat dogs'
o = s.wordPattern(p, st)
print(p, st, o)
assert o is False

