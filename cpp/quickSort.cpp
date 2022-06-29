#include <cstdlib>
#include<iostream>
#include <stdexcept>
#include<vector>

using namespace std;


// void merge(int* array, int low, int mid, int high){
//     return array;
// }

int partition(int* array, int low, int high){
    int i = low-1;
    int pivot = array[high];
    for(int j = low; j < high ; j++){
        if(array[j] < pivot){
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    //swap

    i++;
    int temp = array[high];
    array[high] = array[i];
    array[i] = temp;

    return i;
}

void quickSort(int* array, int low, int high){
    if ( low < high -1 ){
        int p = partition(array, low, high-1);
        quickSort(array, low, p);
        quickSort(array, p+1, high);

    }
}

void printArray(int* array, int length){
    for( int a = 0 ; a < length ; a++  ){

        cout << array[a] << ", ";
    }
    cout << endl;
}

int main(){
    int a[7] = {5,2,4, 8, 9 ,1, 3} ;
    int* i = a;
    // vector<int> a = {1,3,4};
    printArray(a, 7);
    quickSort(i, 0, 7);
    printArray(a, 7);
    return 0;
}
