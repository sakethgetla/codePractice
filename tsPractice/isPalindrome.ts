function isPalindrome(x: number): boolean {
    if (x<0) return false;
    const size = Math.floor(Math.log10(x) + 1) / 2;
    // const top = Math.floor(x / (10** Math.ceil(size)));
    // const bottom = x % (10** Math.floor(size));
    let top = 10 ** Math.floor((Math.log10(x) ));
    const bottom = 10;
    // console.log('num', x);
    // console.log('size', size);
    // console.log('top', top);
    // console.log('bottom', bottom);

    for (var i = 0; i < Math.floor(size); ++i) {
        //console.log(top / (10 ** (Math.floor(size) - 1 - i)), bottom % (10 ** (1 + i)));
        //console.log(x, top, Math.floor(x/top), Math.floor(x%10));
        //console.log(x, x/top, x%10);
        //console.log(x/top, x%10);
        if (!(Math.floor(x/top) === Math.floor(x%10))) {
            //return false
            //console.log(top / (10 ** (Math.floor(size) -1- i)), bottom % (10 ** (1 + i)));
            return false;
        }
        //x /= x**Math.floor(Math.log10(x)+1);
        x = x% top;
        top /= 100;
        x /= 10;
    }
    return true;
};

console.log(isPalindrome(54321));
console.log(isPalindrome(-121));
