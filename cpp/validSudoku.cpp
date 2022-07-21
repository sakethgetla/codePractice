#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << ' ' ;
    }
    cout << endl;
}

bool isValidSudoku(vector<vector<char>>& board) {
    int row [9][9] = {0};
    int col [9][9] = {0};
    int box [3][3][9] = {0};

    for (int j = 0; j < board.size(); j++) {
        for (int i = 0; i < board.size(); i++) {
            //
            // if (board[i][j] != '.' ) {
            //     if (row[j][board[i][j] - '1'] != 0) {
            //         return false;
            //     } else {
            //         row[j][board[i][j] - '1'] = 1;
            //     }
            // }

            // if (board[j][i] != '.' ) {
            //     if (col[j][board[j][i] - '1'] != 0) {
            //         return false;
            //     } else {
            //         col[j][board[j][i] - '1'] = 1;
            //     }
            // }

            // if (board[j][i] != '.' ) {
            //     if (box[i/3][j/3][board[j][i] - '1'] != 0) {
            //         return false;
            //     } else {
            //         box[i/3][j/3][board[j][i] - '1'] = 1;
            //     }
            // }

            if (board[j][i] != '.' ) {
                int digit = board[j][i] - '1';
                if (row[j][digit] || col[i][digit] || box[j/3][i/3][digit])
                    return false;
                else
                    row[j][digit] = col[i][digit] = box[j/3][i/3][digit] = 1;
            }
        }
    }

    return true;
}

int main(){
    return 0;
}
