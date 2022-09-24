// function validPath(n: number, edges: number[][], source: number, destination: number): boolean {
//     var map = new Map<number, number[]>();
//     for ( let edge of edges ){
//         // console.log(edge, typeof edge);
//         if(map.has(edge[0]) && map.get(edge[0]) != undefined){
//             map.get(edge[0]).push(edge[1]);
//         } else {
//             map.set(edge[0], [edge[1]]);
//         }

//         if(map.has(edge[1])){
//             map.get(edge[1]).push(edge[0]);
//         } else {
//             map.set(edge[1], [edge[0]]);
//         }

//     }

//     return false;
// };
function validPath(n: number, edges: number[][], source: number, destination: number): boolean {
    var graph: Set<number>[] = new Array(n);
    var visited: Set<number> = new Set<number>();
    // var visited: Set<number> = new Set<number>([source]);

    function dfs(curr: number): boolean {
        if (graph[curr]) {
            if (graph[curr].has(destination))
                return true;
            else {
                visited.add(curr);
                for (var vertex of graph[curr]) {
                    if (!visited.has(vertex) && dfs(vertex))
                        return true;
                    // visited.delete(vertex);
                }
            }
        }
        return false;
    }

    // console.log(graph);
    for (var edge of edges) {
        // console.log(edge, typeof edge[0])
        if (graph[edge[0]])
            graph[edge[0]].add(edge[1]);
        else
            graph[edge[0]] = new Set<number>([edge[1]]);

        if (graph[edge[1]])
            graph[edge[1]].add(edge[0]);
        else
            graph[edge[1]] = new Set<number>([edge[0]]);

    }

    console.log(graph);

    return dfs(source);
};

var edges = [[0, 1], [1, 2], [2, 0]];
var ans;
console.log(edges);
ans = validPath(3, edges, 0, 2);
console.log(ans);

edges = [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]]
console.log(edges);
ans = validPath(6, edges, 0, 5);
console.log(ans);
