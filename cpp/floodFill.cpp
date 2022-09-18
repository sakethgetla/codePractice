#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.cpp"

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // if (sr < 0 || sr > image.size()-1 || sc < 0 || sc > image[0].size()-1 || image[sr][sc] == color) {
    if (image[sr][sc] == color) {
        return image;
    }

    int prev = image[sr][sc];
    image[sr][sc] = color;

    image = sr+1  < image.size() && image[sr+1][sc] == prev ? floodFill(image, sr+1, sc, color) : image;
    image = sr-1 >= 0 && image[sr-1][sc] == prev ? floodFill(image, sr-1, sc, color) : image;
    image = sc+1 < image[0].size() && image[sr][sc+1] == prev ? floodFill(image, sr, sc+1, color) : image;
    image = sc-1 >= 0 && image[sr][sc-1] == prev ? floodFill(image, sr, sc-1, color) : image;

    return image;
}

int main(){
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    print2dVec(image);
    image = floodFill(image, 1, 1, 2);
    cout << endl;
    print2dVec(image);

    cout << endl;
    cout << endl;

    image = {{0,0,0}, {0,0,0}};
    print2dVec(image);
    image = floodFill(image, 0, 0, 0);
    cout << endl;
    print2dVec(image);

    cout << endl;
    cout << endl;

    image = {{1,1,0}, {1,1,1}};
    print2dVec(image);
    image = floodFill(image, 1, 1, 2);
    cout << endl;
    print2dVec(image);

    return 0;
}
