#include <cstdint>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

bool checkBSTreeRange(TreeNode* root, TreeNode *minNode, TreeNode *maxNode){
    if (root == nullptr) {
        return true;
    } else if ((minNode && root->val <= minNode->val) || (maxNode && root->val <= maxNode->val)) {
        return false;
    } else {
        return checkBSTreeRange(root->left, minNode, root) && checkBSTreeRange(root->right, root, maxNode);
    }
}

bool isValidBST(TreeNode* root) {
    return checkBSTreeRange(root, nullptr, nullptr);
}
// bool isValidBST(TreeNode* root) {
//     if (root != nullptr) {
//         if (root->right != nullptr ) {
//             if (!isValidBST(root->right) || root->val >= root->right->val) {
//                 return false;
//             }
//         }
//         if (root->left != nullptr ) {
//             if (!isValidBST(root->left) || root->val <= root->left->val) {
//                 return false;
//             }

//         }
//     // } else {

//     }
//     return true;

// }

int main(){
    assert(nullptr);
    vector<int> vec = generateRandomVec(20, -10, 10);
    TreeNode * bstree = makeBSTree(vec);
    // TreeNode * btree = makeBTree(vec);
    printBSTree(bstree);
    cout << endl;
    cout << "tree depth: " << BTreeDepth(bstree)<< endl;
    cout << "is valid: " << isValidBST(bstree)<< endl;
    freeBTree(bstree);

    // vec = {2,2,2};
    // assert(ans == false);

    // vec = {5,4,6,null,null,3,7};
    // assert(ans == false);


    return 0;
}
