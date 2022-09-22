
function summaryRanges(nums: number[]): string[] {

    if (!nums.length)
        return [];

    var start: number = nums[0];
    var ranges: string[] = [];

    var p = (n1: number, n2: number) => {
        return (n1 == n2) ? `${n1}` : `${n1}->${n2}`;
    }

    for (var i = 1; i < nums.length; i++) {
        if (nums[i] != nums[i - 1] + 1) {
            ranges.push(p(start, nums[i - 1]));
            start = nums[i];
        }

    }
    // ranges.push(`${start}->${i-1}`);
    // ranges.push(`${start}->${nums[i - 1]}`);
    ranges.push(p(start, nums[i - 1]));

    return ranges;
};


var a = [2, 3, 11, 12];
console.log(a);
console.log(summaryRanges(a));

a = [-1];
console.log(a);
console.log(summaryRanges(a));

a = [];
console.log(a);
console.log(summaryRanges(a));

a = [0, 2, 3, 4, 6, 8, 9];
console.log(a);
console.log(summaryRanges(a));

a = [0, 1, 2, 4, 5, 7];
console.log(a);
console.log(summaryRanges(a));
