#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
// #include <utility>

using namespace std;


void printArraychar(char* array, int length){
    for( int a = 0 ; a < length ; a++  ){
        cout << array[a] << ", ";
    }
    cout << endl;
}

void printArray(int* array, int length){
    for( int a = 0 ; a < length ; a++  ){
        cout << array[a] << ", ";
    }
    cout << endl;
}

int minDeletions(string s){
    // make a 2d frquency array

    int len = 26;
    int histogram[26]= {0};
    // unordered_map<char, int> m = {{a: 1}};
    // printArray(histogram, len);
    for(char c : s){
        histogram[c-'a'] += 1;
    }

    // printArray(histogram, len);

    // sort(histogram, histogram+25);
    sort(histogram, &histogram[len]);

    // printArray(histogram, len);

    int duplicates = 0;
    int changes = 0;
    int curr = len-1;
    int prev = 100000;


    while (curr >= 0 && histogram[curr] > 0){
        // while(prev <= histogram[curr] && histogram[curr] > 0){
        if(prev <= histogram[curr] && histogram[curr] > 0){
            // found duplicate

            if(prev == 0){
                changes += histogram[curr];
                histogram[curr] = 0;
            } else{

                changes += (histogram[curr] - prev) + 1;
                histogram[curr] = prev -1;
            }
        }

        // cout << histogram[curr] << ' ' << duplicates << " " << curr << " " << changes << endl;

        prev = histogram[curr];
        curr --;
    }
    // changes += duplicates;
    // printArray(histogram, len);


    return changes;
}



int main(){
    string s;
    s = "bbcebab";
    cout  << minDeletions(s) << " <-output "<< " expected-> " << 2 << endl;

    s = "abcabc";
    cout  << minDeletions(s) << " <-output "<< " expected-> " << 3 << endl;

    s = "aaabbbcc";
    cout  << minDeletions(s) << " <-output "<< " expected-> " << 2 << endl;

    s = "ceabaacb";
    cout  << minDeletions(s) << " <-output "<< " expected-> " << 2 << endl;

    s = "accdcdadddbaadbc";
    cout  << minDeletions(s) << " <-output "<< " expected-> " << 1 << endl;

    s = "abcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwz";
    cout  << minDeletions(s) << " <-output "<< " expected-> " << 276 << endl;
    // int a[7] = {5,2,4, 8, 9 ,1, 3} ;
    // minDeletions(s);
    // cout << minDeletions(s) << endl;
    // printArray(a, 7);

    // sort(a, a+7 );

    // printArray(a, 7);
    return 0;
}
