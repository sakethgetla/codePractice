function isValid(s: string): boolean {
    if (s.length == 1) {
        return false;
    }
    var stack = [];
    stack.push(s.charAt(0));

    for (var i = 1; i < s.length; ++i) {
        if (s.charAt(i) === '(' || s.charAt(i) === '[' || s.charAt(i) === '{') {
            stack.push(s.charAt(i))

        } else if (s.charAt(i) == ')' && stack.pop() != '(') {
            return false;
            // if (stack.pop() != '(') {
            //     return false;
            // }

        } else if (s.charAt(i) == '}' && stack.pop() != '{') {
            return false;
        } else if (s.charAt(i) == ']' && stack.pop() != '[') {
            return false;
        }

    }
    if (stack.length == 0) {
        return true;
    }
    return false;
}

console.log(isValid("(){}[]"));
console.log(isValid("()"));
console.log(isValid("(]"));

console.log(isValid("()}[]"));
console.log(isValid("()[]}"));
console.log(isValid("(["));
