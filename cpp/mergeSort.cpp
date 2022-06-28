#include <cstdlib>
#include<iostream>
#include <stdexcept>
#include<vector>

using namespace std;


void merge(int* array, int low, int mid, int high){
    return array;
}

void mergeSort(int* array, int low, int high){
    int length = high - low;
    if (length == 1){
        // return array;
        return;
    } else if (length == 2){
        if ( array[0] < array[1] ){
            return;
            // return array ;
        } else {
            //swap
            int temp = array[0];
            array[0] = array[1];
            array[1] = temp;
            // return array;
        }
    } else if (length > 2){
        int mid = length/2;
        // int* front = mergeSort(array,low,  mid);
        // int* back = mergeSort(array, mid, high);
        mergeSort(array,low,  mid);
        mergeSort(array, mid, high);
        merge(array, low, mid, high);
        // return merge(array, low, mid, high);
        // return mergeSort(array, mid)
    } else {
        cout << "error" << endl;
        // return NULL;
}

void printArray(int* array, int length){
    for( int a = 0 ; a < length ; a++  ){

        cout << array[a] << ", ";
    }
    cout << endl;
}

int main(){
    int a[3] = {5,2,4} ;
    int* i = a;
    // vector<int> a = {1,3,4};
    mergeSort(a, 3);
    printArray(a, 3);
    return 0;
}
