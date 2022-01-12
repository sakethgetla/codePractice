// console.log('here');
// var j: any;
// var n: any = "atireasn b c"

// for (j in n) {
//     console.log(n[j])
// }


function twoSum(nums: number[], target: number): number[] {
    let map = new Map();
    for (var i = 0; i < nums.length; ++i) {
        if (map.has(target - nums[i])){
            return [i, map.get(target - nums[i])]
        } else {
            map.set(nums[i], i)
        }

    }
    return [0];
};


console.log(twoSum([2, 7, 11, 15], 9));
