#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (list1 == nullptr) {
        return list2;
    } else if (list2 == nullptr) {
        return list1;
    }

    if (list1->val <= list2->val){

        // ListNode * min =  list1;
        // ListNode * max =  list2;
        // ListNode * temp = min->next;
        // min->next = mergeTwoLists(temp, list2);
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }else {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}

int main(){
    vector<int> vec1 = {1,2,4};
    vector<int> vec2 = {1,3,4};
    ListNode * head = makeList(vec1);
    ListNode * curr2 = makeList(vec2);

    ListNode * ans = mergeTwoLists(head, curr2);
    printVector(vec1);
    printVector(vec2);
    printListNode(ans);
    // cout << ans << endl;

    // assert(ans == );
    // freeList(head);

    return 0;
}
