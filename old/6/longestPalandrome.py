#def check(s, p):
from pdb import set_trace as bp
    
def palandrome(s):
    pal = []
    #for c in s:
    longestPal = []
    for i in range(1, len( s )):
        #if ( i == len(s)-1):
        #    bp()
        if (s[i] == s[i-1]):
            j = i 
            p = i -1
            pal = []
            while ( p >= 0 and j < len(s) ):
                if (s[p] == s[j]): 
                    pal.append(s[j])
                else :
                    p = 0
                j += 1
                p -= 1
        elif (len(s) > i +1 and s[i-1] == s[i+1]):
            j = i +1 
            p = i -1
            pal = [s[i]]
            while ( p >= 0 and j < len(s) ):
                if (s[p] == s[j]): 
                    pal.append(s[j])
                else :
                    p = 0
                j += 1
                p -= 1
        if (len(longestPal) < len(pal)):
            #longestPal = 'awdw'
            print("newpal longestPal= ", longestPal, len(longestPal), 'pal=',  pal, len(pal))
            longestPal = pal
    return longestPal
    #return longestPal[-1:0] + longestPal

w1 = "abiba"
print(w1)
print(palandrome(w1))
w2 = "hjkl;aabiibaakwjd"
print(w2)
print(palandrome(w2))
