#include <cstdlib>
#include<iostream>
#include <stdexcept>
#include<vector>
#include "helperFunctions.h"

using namespace std;


// void merge(int* array, int low, int mid, int high){
//     return array;
// }

// void mergeSort(int* array, int low, int high){
//     int length = high - low;
//     if (length == 1){
//         // return array;
//         return;
//     } else if (length == 2){
//         if ( array[0] < array[1] ){
//             return;
//             // return array ;
//         } else {
//             //swap
//             int temp = array[0];
//             array[0] = array[1];
//             array[1] = temp;
//             // return array;
//         }
//     } else if (length > 2){
//         int mid = length/2;
//         // int* front = mergeSort(array,low,  mid);
//         // int* back = mergeSort(array, mid, high);
//         mergeSort(array,low,  mid);
//         mergeSort(array, mid, high);
//         merge(array, low, mid, high);
//         // return merge(array, low, mid, high);
//         // return mergeSort(array, mid)
//     } else {
//         cout << "error" << endl;
//         // return NULL;
// }

// void printArray(int* array, int length){
//     for( int a = 0 ; a < length ; a++  ){

//         cout << array[a] << ", ";
//     }
//     cout << endl;
// }



void merge(vector<int> &vec, int l1, int h1, int l2, int h2){
    // merge sorted sections of array;
    int v2[h1-l1+1];
    int v1[h2-l2+1];
    for (int i = 0; i <= (h2-l2); i++) {
        v2[i] = vec[i+l2];
    }

    for (int i = 0; i <= (h1-l1); i++) {
        v1[i] = vec[i+l1];
    }

    for (int i = l1; i <= h2; i++) {
        cout << vec[i] << ", ";
    }
    cout << endl;

    printArray(v1, h1-l1+1);
    printArray(v2, h2-l2+1);


    for (int i = l1; i <= h2; i++) {
        cout << vec[i] << ", ";
    }

}

int main(){
    vector<int> vec1(5, 0);
    vector<int> vec2(5, 0);
    vector<int> vec3(5, 0);
    vector<int> vec4(5, 0);

    generateSortedVec(vec1, -10, 10);
    generateSortedVec(vec2, -10, 10);
    generateSortedVec(vec3, -10, 10);
    generateSortedVec(vec4, -10, 10);

    printVector(vec1);
    printVector(vec2);
    printVector(vec3);
    printVector(vec4);

    vec3.insert(vec3.end(), vec4.begin(), vec4.end());
    vec2.insert(vec2.end(), vec3.begin(), vec3.end());
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    printVector(vec1);

    merge(vec1, 5, 9, 10, 14);

    printVector(vec1);
}
