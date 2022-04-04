function longestCommonPrefix(strs: string[]): string {
    var com = '';
    var char = '';

    if (strs.length === 0) {
        return com;
    } else if (strs.length === 1) {
        return strs[0];
    } else {

        for (var j = 0; j < strs.length; ++j) {
            if (strs[j].length === 0) {
                return com;
            }

        };
    }
    // while (true) {
    for (var i = 0; i < strs[0].length; ++i) {
        char = strs[0].charAt(com.length);
        //console.log(char);
        for (var j = 0; j < strs.length; ++j) {
            if (char != strs[j].charAt(com.length)) {
                //console.log('here');
                return com;
            }

        };
        com += char;
        //console.log(com);
    }
    return com;
}

console.log('ans: ' + longestCommonPrefix(["flower", "flow", "floight"]));
console.log('ans: ' + longestCommonPrefix(["dog", "racecar", "car"]));
console.log('ans: ' + longestCommonPrefix(["", "", ""]));
console.log('ans: ' + longestCommonPrefix(['a']));
