#include <cstdlib>
#include <iostream>
#include <vector>
// #include <unordered_map>

using namespace std;


template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << ' ' ;
    }
    cout << endl;
}


template <class T>
void print2DVector(vector<vector<T>> vec){
    cout << '[' << endl;
    for (vector<T> v : vec){
        printVector(v);
    }
    cout <<']' << endl;
    // cout << endl;
}

vector<vector<int>> pascalsTriangle(int numRows){
    vector<vector<int>> vec = {{1}};

    while (vec.size() < numRows){
        vector<int> row = {1};
        // cout << vec.back().size() -1 << endl;
        for (int i = 1; i < vec.back().size() ; i++) {
            // cout << "here" << endl;
            row.push_back(vec.back()[i] + vec.back()[i-1]);
        }
        row.push_back(1);
        vec.push_back(row);
    }

    return vec;
}

int main(){
    int numRows = 5;
    print2DVector(pascalsTriangle(numRows));
    numRows = 1;
    print2DVector(pascalsTriangle(numRows));

    return 0;
}
