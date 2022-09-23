
var a: number = 5;
// var hmap: {number: boolean} = {`${a}`: true};
var hmap = new Map<number, boolean>();
hmap.set(4, true);
hmap.set(9, true);
hmap.set(2, true);

console.log(hmap);
console.log(hmap.get(4));
console.log(hmap.get(5));
