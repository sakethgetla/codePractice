#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

bool isValidBST(TreeNode* root) {
    if (root != nullptr) {
        if (root->right != nullptr ) {
            if (!isValidBST(root->right) || root->val > root->right->val) {
                return false;
            }
        }
        if (root->left != nullptr ) {
            if (!isValidBST(root->left) || root->val < root->left->val) {
                return false;
            }

        }
    // } else {

    }
    return true;

}

int main(){
    vector<int> vec = generateRandomVec(20, -10, 10);
    TreeNode * bstree = makeBSTree(vec);
    // TreeNode * btree = makeBTree(vec);
    printBSTree(bstree);
    cout << endl;
    cout << "tree depth: " << BTreeDepth(bstree)<< endl;
    cout << "is valid: " << isValidBST(bstree)<< endl;
    freeBTree(bstree);



    return 0;
}
