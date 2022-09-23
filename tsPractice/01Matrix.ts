function updateMatrix(mat: number[][]): number[][] {
    const m = mat.length, n = mat[0].length;
    var minDist: number[][] = new Array(m).fill(new Array(n).fill(-1));
    console.log(minDist);


    var bfs = (x: number, y: number) => {
        var path: {number: number[]} ;
        var qu: number[][] = [];
        var curr: undefined | number[];

        qu.push([x, y]);

        // console.log(qu);
        while (qu.length != 0) {
            curr = qu.shift();
            if ( mat[curr[0]][ curr[1]] == 0 ){
                qu = [];
            } else {
                // qu.
            }
        }

    }
    bfs(0, 0);
    console.log(minDist[0].length);

    return [];
};

var mat = [[0, 0, 0], [0, 1, 0], [1, 1, 1]];
console.log(mat);
var ans: number[][] = updateMatrix(mat);
