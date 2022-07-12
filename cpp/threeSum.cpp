#include <cstdlib>
#include <iostream>
// #include <type_traits>
#include <unordered_map>
// #include <unordered_set>
#include <vector>
// #include <set>
#include <algorithm>

using namespace std;


void printVector(vector<int> vec){
    for (int v : vec){
        cout << v << ' ' ;
    }
    cout << endl;
}

void print2dVec(vector<vector<int>> vec){
    for (vector<int> v : vec){
        printVector(v);
    }
}

bool isDuplicate(vector<vector<int>> sums, vector<int> vec){
    // bool out = false;
    int count ;
    // printVector(vec);
        // cout << "vec" << endl;
    for(vector<int> sum: sums){
        if (sum == vec)
            return true;
    }
    return false;
}

// vector<vector<int>> insertSum(vector<vector<int>> inputSums, vector<vector<int>> sums){

//     for(vector<int> vec : inputSums){
//         if(!isDuplicate(sums, vec))
//             sums.push_back(vec) ;
//        // printVector(vec);
//     }

//     // int low = 0;
//     // int high = sums.size()-1;
//     // int mid;
//     // while(low < high){
//     //     mid = (high - low)/2;
//     //     if(sums[low] == sum || sums[mid] == sum || sums[high] == sum){
//     //         return;
//     //     } else if ( sum > sums[mid] ){
//     //         low = mid+1;
//     //     } else if ( sum < sums[mid] ){
//     //         high = mid-1;
//     //     }
//     // }
//     return sums;
// }

// void twoSum(int curr, vector<int> nums, unordered_map<vector<int>, int> &sums) {
// vector<vector<int>> twoSum(int curr, vector<int> nums, unordered_map<vector<int>, int> sums) {
// vector<vector<int>> twoSum(int curr, vector<int> nums, vector<vector<int>> sums) {
//     unordered_map<int, int> m;
//     // vector<vector<int>> sums ;
//     // vector<int> vec ;
//     int f;
//     for (int i = curr +1 ; i < nums.size() ; i++) {
//         f = -1*(nums[curr] + nums[i]) ;
//         // cout << f << ", " << nums[curr] << ", " << nums[i] << endl;
//         if (m.find(f) != m.end()){
//             // if nums[i] is in the map
//             vector<int> vec ;
//             vec = {nums[curr], nums[m[f]], nums[i]};
//             if (sums.size() == 0 || sums[sums.size()-1] != vec)
//                 sums.push_back(vec);
//         }
//         m[nums[i]] = i;
//     }
//     return sums;
// }

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> sums;
    // printVector(nums);
    sort(nums.begin(), nums.end());
    // printVector(nums);
    // sums = twoSum(0, nums, sums);
    unordered_map<int, int> m;

    for(int i = 0; i < nums.size(); i++ ){
        m[nums[i]] = i;
    }

    int prev = 0;
    // int req = NULL;
    int req ;
    for (int i = 0 ; i < nums.size() -2 ; i++) {
        if(i == 0 || prev != nums[i]){
            // cout << "here" << endl;

            for (int j = i+1; j < nums.size() -1 ; j++) {
                req = -1*(nums[i] + nums[j]);
                // cout << nums[i] << ", " << nums[j] << ", " << req << endl;
                if ((j == i+1 || nums[j] != prev) &&  m.find(req) != m.end() && m[req] > j ){
                    // cout << "here" << endl;
                    vector<int> vec;
                    // vec = {nums[i], nums[m[req]], nums[j]};
                    vec = {nums[i], nums[j], nums[m[req]]};
                    sums.push_back(vec);
                }
                prev = nums[j];

            }

        }
        prev = nums[i];
    }

    return sums;
}



int main(){
    vector<int> v;
    // v = {-1,0,1,2,-1,-4};
    v = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    // v = {1, 0, 0 };
    // v = {0, 0, 0 };
    // v = {0, 0, 0, 0 };
    // v = {};

    printVector(v);
    vector<vector<int>> a = threeSum(v);
    print2dVec(a);
    return 0;
}

// template <class ForwardIterator, class T>
// // int getLowerBound(ForwardIterator first, ForwardIterator last, const T& val){
// int getLowerBound(ForwardIterator list, int size, const T& val){
//     int low = 0;
//     int high = size-1;
//     int mid = high - low;

//     while(low < high){
//         if (list[mid] == val){
//             return mid;
//         } else if ( list[mid] > val ){
//             high = mid -1;
//         } else if ( list[mid] < val ){
//             low = mid +1;
//         } else {
//             return NULL;
//         }
//     }

//     return low;
// }

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


// bool is_same<typename, typename>

// int find

// vector<vector<int>> threeSum(vector<int>& nums) {
//     unordered_map<int, vector<vector<int>>> m;
//             // vector<vector<int>> a;
//     for (int j = 0 ; j < nums.size() ; j++){
//         for (int i = j+1 ; i < nums.size() ; i++){
//             m[-1*(nums[i] + nums[j])].push_back( {nums[i], nums[j], -1*(nums[i] + nums[j])} );
//         }
//     }
//     vector<vector<int>> out;
//     for (int num : nums){
//         if (m.find(num) != m.end()){
//             out.insert(out.end(), m[num].begin(), m[num].end());
//             // for(vector<int> vec : m[num] ){
//             //     // vec.push_back(num);
//             //     out.push_back(vec);
//             // }

//         }
//     }
//     return out;

// }
