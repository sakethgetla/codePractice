
#include<iostream>
#include<vector>
// #include<map>
#include<unordered_map>

using namespace std;

vector < int > twoSum(vector<int>& nums, int target) {
    vector<int> g;
    unordered_map<int, int>m;

    for (int i = 0 ; i < nums.size() ; i++){
        if(m.find(target-nums[i]) != m.end() ){
            g.push_back(i);
            g.push_back(m[target-nums[i]]);
            return g;
        } else{
            m[nums[i]] = i;
        }
    }



    return g;
}



int main(){

    vector<int> g;

    for (int i = 0; i< 10 ; i++ ){
        g.push_back((i));
        cout << i << ',' ;
    }

    cout << endl ;

    vector<int> a = twoSum((g), 8);

    for (int i = 0 ; i < a.size() ; i++)
        cout << a[i] << endl ;
}
