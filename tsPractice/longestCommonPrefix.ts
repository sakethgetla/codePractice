function longestCommonPrefix(strs: string[]): string {
    var com = '';
    var counter = 0;
    var char = '';
    while (true) {
        strs.forEach(str => {
            if (com.length > str.length) {
                com = com.slice(0, str.length);
            }
            while (com.length > 0 && com != str.substring(0, com.length)) {
                com = com.slice(0, com.length - 1);
            }
        });
    }
    return com;
}

console.log(longestCommonPrefix(["flower", "flow", "floight"]));
console.log(longestCommonPrefix(["dog", "racecar", "car"]));
