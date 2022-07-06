#include <cstdlib>
#include<iostream>
#include <unordered_map>
#include<vector>

using namespace std;


void printVector(vector<int> vec){
    for (int v : vec){
        cout << v << ' ' ;
    }
    cout << endl;
}

void prind2dVec(vector<vector<int>> vec){
    for (vector<int> v : vec){
        printVector(v);
    }
}

bool isDuplicate(vector<vector<int>> sums, vector<int> vec){
    // bool out = false;
    int count ;
    printVector(vec);
        cout << "vec" << endl;
    for(vector<int> sum: sums){
        count = 0;
        printVector(sum);
        for (int v: vec){
            for (int s: sum){
                if(v == s){
                    cout << "here" << endl;
                    count ++;
                }
            }

        }
       if (count >= 3)
           return true;
    }

    return false;
}

// vector<vector<int>> threeSum(vector<int>& nums) {
//     // brute force

//     vector<vector<int>> sum;
//     for(int i = 0 ; i < nums.size() ; i++  ){
//         for(int j = i + 1 ; j < nums.size() ; j++  ){
//             for(int z = j + 1 ; z < nums.size() ; z++  ){
//                 if (nums[i] + nums[j] + nums[z] == 0){
//                     vector<int> a;
//                     a.push_back(nums[i]) ;
//                     a.push_back(nums[j]) ;
//                     a.push_back(nums[z]) ;
//                     // printVector(a);
//                     if (!isDuplicate(sum, a)){
//                         // cout << "here" << endl;
//                         sum.push_back(a);
//                     }
//                         // sum.push_back(a);

//                 }
//             }
//         }
//     }
//     return sum;
// }

vector<vector<int>> threeSum(vector<int>& nums) {
   unordered_map<int, vect>
}




int main(){
    vector<int> a = {-1,0,1,2,-1,-4};
    // cout << threeSum(a) << endl;
    // printVector(a);
    // prind2dVec(threeSum(a));

    // a = {0, 0 , 0, 0};
    a = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    printVector(a);
    prind2dVec(threeSum(a));

    return 0;
}
