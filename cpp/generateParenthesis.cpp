#include <cstdlib>
#include <string>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;


vector<string> generateParenthesis(int n){
    vector<string> par;
    // int p[2] ;
    vector<array<int, 2>> stkpar ;

    // p[0] = n;
    // p[1] = 0;
    stkpar.push_back({n-1, 1});
    par.push_back("(");

    for (int i = 0; i < par.size(); i++) {
        while (stkpar[i][0] > 0 || stkpar[i][1] > 0 ){
            if (stkpar[i][0] > 0 && stkpar[i][1] > 0 ){

                string a = par[i];
                a.push_back(')');
                par.push_back(a);
                // int p[2] =  {stkpar[i][0], stkpar[i][1]-1};
                stkpar.push_back({ stkpar[i][0], stkpar[i][1]-1 });

                par[i].push_back('(');
                stkpar[i][0]--;
                stkpar[i][1]++;
            } else if (stkpar[i][0] > 0){
                par[i].push_back('(');
                stkpar[i][0]--;
                stkpar[i][1]++;
            } else if (stkpar[i][1] > 0){
                par[i].push_back(')');
                stkpar[i][1]--;
            }
        }
    }
    // string b = a.copy(a.begin(), a.size());

    return par;
}

int main(){
    // string a = "se";
    // string b = a;
    // cout << a << endl;
    // a[0] = 'r';
    // cout << a << endl;
    // cout << b << endl;

    vector<string> s = generateParenthesis(3);
    printVector(s);

    s = generateParenthesis(1);
    printVector(s);


    return 0;
}
