
function letterCasePermutation(s: string): string[] {
    var permutations: string[] = [];
    var makePerumations = (s: string, curr: string, index: number) => {
        if (index < s.length) {
            if ((/[a-zA-Z]/).test(s.charAt(index))) {
                curr += s.charAt(index).toLowerCase();
                makePerumations(s, curr, index + 1);
                curr = curr.slice(0, curr.length - 1);

                curr += s.charAt(index).toUpperCase();
                makePerumations(s, curr, index + 1);
                curr = curr.slice(0, curr.length - 1);

            } else {
                curr += s.charAt(index);
                makePerumations(s, curr, index + 1);
                curr = curr.slice(0, curr.length - 1);
            }

            // curr --;

        } else {
            permutations.push(curr);
        }
    }

    makePerumations(s, "", 0);

    // console.log(s[2]);
    return permutations;
};


var a = 'a1b2';
console.log(a);
console.log(letterCasePermutation(a));

a = '3Z4';
console.log(a);
console.log(letterCasePermutation(a));

a = '3z4';
console.log(a);
console.log(letterCasePermutation(a));
