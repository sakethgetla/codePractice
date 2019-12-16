def longestPalindrome(s):
    # max len of s = 1000
    start = 0
    tot = 0
    out = ""
    offset = 1
    inpalindrome = False
    for i in range(1, len(s)):
        out.append(s[i])
        if(i >= offset and s[i-offset] == s[i]):
            offset -= 2
            inpalindrome = True
        else :
            inpalindrome = False

        if (tot > offset):
            tot = offset
            start = i - offset

            



