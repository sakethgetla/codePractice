# leetCode question, ans by saketh
# Tue 17 Dec 11:59:57 AEDT 2019

def romanToInt(s):
    last = ""
    out = 0
    s = s[::-1]
    for c in s:
        #if ( last != "" and c != "I"):
            # c is not the first char and is not I
        if(c == "I"):
            if(last == 'V' or last == 'X'):
                out -= 1
            else :
                out += 1
        elif (c == "X"):
            if(last == 'L' or last == 'C'):
                out -= 10
            else :
                out += 10
        elif (c == "C"):
            if(last == 'D' or last == 'M'):
                out -= 100
            else :
                out += 100
        elif (c == "V"):
            out += 5
        elif (c == "L"):
            out += 50
        elif (c == "D"):
            out += 500
        elif (c == "M"):
            out += 1000
        last = c
    return out 

print(romanToInt("III"))
print(romanToInt("IV"))
print(romanToInt("IX"))
print(romanToInt("LVIII"))
print(romanToInt("LIV"))
