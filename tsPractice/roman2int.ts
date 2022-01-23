function romanTOInt(s: string): number {
    var tot = 0;
    var last = 'I';
    let dic: Record<string, number> = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000};
    for (var i = s.length -1; i >=0  ; --i) {
        console.log(s[i]);
        if (dic[last] > dic[s[i]]){
           tot -= dic[s[i]] ;
        } else {
           tot += dic[s[i]] ;
        }
        last = s[i];
    }
    return tot;
}

console.log(romanTOInt("LVIII"));
