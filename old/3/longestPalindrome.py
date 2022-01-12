#def longestPalindrome(s):
#    #brute force
#    dic = {}
#    for i in range(len(s)):
#        if(s[i] in dic):
#            #dic[s[i]] = dic[s[i]].append(i) 
#            dic[s[i]].append(i) 
#        else :
#            dic[s[i]] = [i]
#
#    for i in range(len(s)):
#        if
#    if(

def longestPalindrome(s):
    # max len of s = 1000
    start = 0
    tot = 0
    #out = ""
    offset = 1
    inpalindrome = False
    for i in range(1, len(s)-1):
        print(f"i = {i}, s = {s[i]} i-offset = {i-offset}")
        #out.append(s[i])
        if(i >= offset ):
            if(s[i-offset] == s[i] or s[i+1-offset] == s[i+1])):

            offset += 2
            inpalindrome = True
        else :
            inpalindrome = False
            offset = 1

        if (tot < offset):
            tot = offset
            start = i - offset

    print(f"start = {start}")
    return s[start : start+(offset *2)]

print(longestPalindrome("1111bacacab"))

            



