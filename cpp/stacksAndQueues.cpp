#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

bool isValid(string s) {
    vector<char> stack;

    for (char c : s) {
        switch (c) {
            case '(':
                stack.push_back(')');
                break;
            case '[':
                stack.push_back(']');
                break;
            case '{':
                stack.push_back('}');
                break;
            default:
                if(!stack.empty() && stack.back() == c ){
                   stack.pop_back();
                } else {
                    return false;
                }
                break;
        }
    }

    // cout << stack.back() << endl;

    return stack.empty() ? true : false;
}

class MyQueue {
public:

        stack<int> st1;
        stack<int> st2;
    MyQueue() {

    }

    void push(int x) {
        st1.push(x);

    }

    int peek() {

        if(st2.empty()){
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            return peek();
        } else {
            return st2.top();
        }
    }

    int pop() {
        int a = peek();
        st2.pop();
        return a;
    }

    bool empty() {
        return st1.empty() || st2.empty();
    }
};



int main(){
    string s = "()[{}]";
    bool ans = isValid(s);
    cout << s << ", " << ans << endl;

    s = ")";
    ans = isValid(s);
    cout << s << ", " << ans << endl;
    return 0;
}
