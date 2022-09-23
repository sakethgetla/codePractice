function islandPerimeter(grid: number[][]): number {
    const m = grid.length, n = grid[0].length;
    const bfs = (y: number, x: number) => {
        var perimeter: number = 0;
        var visited = new Set<number>();
        const neighbours = [[0, -1], [-1, 0], [1, 0], [0, 1]];
        var q: number[] = [];

        q.push((y * n) + x);
        // console.log(x, y, q[0]);
        visited.add(q[0]);
        while (q.length > 0) {
            y = Math.floor(q[0] / n), x = q[0] % n;
            // console.log(q[0], y, x);
            q.shift();

            // console.log(x, y);
            neighbours.forEach(([j, i]) => {
                j += y, i += x;
                // console.log(y, x, j, i, ((j) * n) + i);
                if (!visited.has((j * n) + i) || !(i >= 0 && i < n && j >= 0 && j < m)) {
                    if (i >= 0 && i < n && j >= 0 && j < m && grid[j][i]) {
                        q.push(((j) * n) + i);
                        visited.add(((j) * n) + i);
                        // console.log(j+y , i + x);
                        // console.log(visited);
                    } else {
                        perimeter++;
                    }
                }
            })

        }

        return perimeter;
    }

    for (var j = 0; j < m; j++) {
        for (var i = 0; i < n; i++) {
            if (grid[j][i])
                return bfs(j, i);
        }

    }

    return 0;
};


var grid = [[0, 1, 0, 0], [1, 1, 1, 0], [0, 1, 0, 0], [1, 1, 0, 0]];
var ans;
ans = islandPerimeter(grid);
console.log(grid);
console.log(ans);

grid = [[1, 1]];
ans = islandPerimeter(grid);
console.log(grid);
console.log(ans);

grid = [[1], [1]];
ans = islandPerimeter(grid);
console.log(grid);
console.log(ans);

grid = [[0], [1]];
ans = islandPerimeter(grid);
console.log(grid);
console.log(ans);

grid = [[0, 1]];
ans = islandPerimeter(grid);
console.log(grid);
console.log(ans);

grid = [[1, 0]];
ans = islandPerimeter(grid);
console.log(grid);
console.log(ans);

grid = [[1]];
ans = islandPerimeter(grid);
console.log(grid);
console.log(ans);
