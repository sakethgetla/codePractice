#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> usable;
    for (char l : magazine) {
        if(usable.find(l) == usable.end())
            usable[l] = 1;
        else
            usable[l]++;
    }

    for (char l : ransomNote) {
        if(usable.find(l) == usable.end() || usable[l] == 0)
            return false;
        else
            usable[l]--;
    }
    return true;
}

int main(){
    int size = 10;
    string magazine = makeRandomWord(size);
    vector<int> indexes = generateRandomVec(5, 0, size-1);
    string ransomeNote;
    for (int i : indexes) {
        ransomeNote += magazine[i];
    }

    cout << magazine << endl;
    cout << ransomeNote << endl;
    cout << canConstruct(ransomeNote, magazine) << endl;

    magazine = "aa";
    ransomeNote = "ab";
    bool ans = canConstruct(ransomeNote, magazine);
    cout << magazine << endl;
    cout << ransomeNote << endl;
    cout << ans << endl;
    assert(ans == false);

    magazine = "aab";
    ransomeNote = "aa";
    ans = canConstruct(ransomeNote, magazine);
    cout << magazine << endl;
    cout << ransomeNote << endl;
    cout << ans << endl;
    assert(ans == true);

    magazine = "b";
    ransomeNote = "a";
    ans = canConstruct(ransomeNote, magazine);
    cout << magazine << endl;
    cout << ransomeNote << endl;
    cout << ans << endl;
    assert(ans == false);


    return 0;
}
