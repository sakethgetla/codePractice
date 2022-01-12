# leetCode question, ans by saketh
# Tue 17 Dec 12:38:14 AEDT 2019

def longestCommonPrefix(strs):
    out = strs[0] 
    counter = 0

    for i in range(1, len(strs)):
        newout = []
        #print(f'out = {out}, strs[i] = {strs[i]}')
        for j in range(min(len(strs[i]), len(out))):
            #print(f'j = {j}, strs[i][j] = {strs[i][j]}, out[j] = {out[j]}')
            if(out[j] != strs[i][j]):
                if ( j == 0 ):
                    return ""
                #else :
                #    newout = out[:j]
            else :
                newout.append(out[j])
        out = newout
    return ''.join(out)

                    

print(longestCommonPrefix(["flower","flow","flight", "fly"]))
print(longestCommonPrefix(["flower","flow","flight"]))
print(longestCommonPrefix(["dog","racecar","car"]))
