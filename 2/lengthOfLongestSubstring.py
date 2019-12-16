def lengthOfLongestSubstring(s):
    dic = {}
    counter = 0
    tot = 0
    start = 0
    for c in s:
        if( c in dic and dic[c] >= start):
            start = dic[c] + 1
        dic[c] = counter
        if ( tot < counter - start + 1 ): tot = counter - start + 1
        counter += 1
    return tot 

print(lengthOfLongestSubstring("pwwekew"))
print(lengthOfLongestSubstring("abcabcbb"))
print(lengthOfLongestSubstring("dvdf"))
print(lengthOfLongestSubstring(" "))
