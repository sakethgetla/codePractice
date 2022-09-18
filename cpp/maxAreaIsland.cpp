#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.cpp"

using namespace std;


int dfs(vector<vector<int>>& grid, int j, int i){
    if (i < 0 || i >= grid[0].size() || j < 0 || j >= grid.size() || grid[j][i] == 0) {
        return 0;
    } else {
        grid[j][i] = 0;
        return 1 + dfs(grid, j+1, i) + dfs(grid, j-1, i) + dfs(grid, j, i-1) + dfs(grid, j, i+1);
    }

}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    for (int j = 0; j < grid.size(); j++) {
        for (int i = 0; i < grid[0].size(); i++) {
            maxArea = max(maxArea, dfs(grid, j, i));
        }
    }
    return maxArea;
}


int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    print2dVec(grid);
    int ans = maxAreaOfIsland(grid);
    cout << ans << endl;
    cout << endl;

    grid = {{0,0,0,0,0,0,0,0,0,0,0,0,0}};
    print2dVec(grid);
    ans = maxAreaOfIsland(grid);
    cout << ans << endl;
    cout << endl;
    return 0;
}
