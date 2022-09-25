function addBinary(a: string, b: string): string {
    // var i: number = 0, j: number = 0;
    // var sumstr: string[] = new Array(max(b.length, a.length)+1).fill('');
    var sumstr: string[] = ['0'];

    for (var i = a.length - 1, j = b.length - 1; i >= 0 || j >= 0; i--, j--) {
        // console.log(i, a[i], j, b[j]);
        if (i >= 0) {
            // sumstr = a.charAt(i) + sumstr[0];
            sumstr.push(String(Number(sumstr.pop()) + Number(a.charAt(i))));
        }

        if (j >= 0) {
            sumstr.push(String(Number(sumstr.pop()) + Number(b.charAt(j))));
        }

        if (sumstr[sumstr.length - 1] == '2') {
            sumstr.pop();
            sumstr.push('0');
            sumstr.push('1');
        } else if (sumstr[sumstr.length - 1] == '3') {
            sumstr.pop();
            sumstr.push('1');
            sumstr.push('1');
        // } else if (sumstr[sumstr.length - 1] == '0') {
            // sumstr.pop();
        } else {
            sumstr.push('0');
        }

    }

    if (sumstr.length > 1 && sumstr.at(-1) === '0')
        sumstr.pop();

    // console.log(sumstr);
    return sumstr.reverse().join('');;
};

var a: string, b: string, ans: string;

a = '1011', b = '1011';
console.log(a, b);
ans = addBinary(a, b);
console.log(ans);

a = '0', b = '0';
console.log(a, b);
ans = addBinary(a, b);
console.log(ans);

a = '0', b = '1';
console.log(a, b);
ans = addBinary(a, b);
console.log(ans);

a = '11', b = '1';
console.log(a, b);
ans = addBinary(a, b);
console.log(ans);

a = '100', b = '110010';
console.log(a, b);
ans = addBinary(a, b);
console.log(ans);
