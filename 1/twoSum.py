def twoSum(l, target):
    #print(dic)
    #try:
    #    print(dic['a'])
    #except :
    #    print("Adwaw")
    #if 'a' in dic :
    #    print('yes')
    #else :
    #    print('no')
    #dic['a'] = 'adawd'
    #if 'a' in dic :
    #    print('yes')
    #else :
    #    print('no')

    dic = {}
    for i in range(len(l)):
        if(target - l[i] in dic):
            return [i, dic[target - l[i]]]
        dic[l[i]] = i

print(twoSum([1, 2], 3))

