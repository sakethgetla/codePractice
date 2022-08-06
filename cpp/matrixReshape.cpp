#include <cstdlib>
#include <initializer_list>
#include <type_traits>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"


using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if (r*c != mat.size()*mat[0].size()) {
        return mat;
    }

    int i = 0, j = 0;
    vector<vector<int>> reshapeMat(r, vector<int>(c));

    for (vector<int> row : mat) {
        for (int val : row) {
            reshapeMat[j][i] = val;
            i++;
            if (i == c) {
                i = 0;
                j++;
            }
        }
    }
    return reshapeMat;
}

int main(){
    int m = 5, n = 4;
    vector<vector<int>> matrix = makeRandomMatrix(m, n, -10, 10);
    print2dVec(matrix);
    vector<vector<int>> rmat = matrixReshape(matrix, 4, 5);
    print2dVec(rmat);

    cout << endl;

    matrix = {{1,2}, {3,4}};
    print2dVec(matrix);
    rmat = matrixReshape(matrix, 1, 4);
    print2dVec(rmat);

    cout << endl;

    matrix = {{1,2}, {3,4}};
    print2dVec(matrix);
    rmat = matrixReshape(matrix, 2, 4);
    print2dVec(rmat);


    return 0;
}
