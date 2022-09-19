#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;



ListNode* removeElements(ListNode* head, int val) {
    if (head != nullptr) {
        head->next = removeElements(head->next, val);
        return (head->val == val) ? head->next : head;
    }
    return nullptr;
}


// ListNode* reverseList(ListNode* head) {
//     // recursive
//     if (head == nullptr || head->next == nullptr) {
//         return head;
//     } else {
//         ListNode * reversed = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return reversed;
//     }
// }

// ListNode* reverseList(ListNode* head) {
//     // iterative

//     ListNode * curr = head;
//     ListNode * prev = nullptr;
//     ListNode * temp ;
//     while (curr != nullptr) {
//         temp = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = temp;
//     }
//     return prev;
// }

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode * h = head;
    // unordered_map<int, bool> found;
    // found[head->val] = true;
    ListNode * prev = head;
    head = head->next;
    while (head != nullptr) {
        if(prev->val == head->val){
            prev->next = head->next;
        } else {
            prev = head;
        }
        head = head->next;
    }
    return h;
}


// ListNode* middleNode(ListNode* head) {
//     int cnt = 0;
//     ListNode * curr = head;

//     while (curr != nullptr) {
//         cnt++;
//         curr = curr->next;
//     }

//     cnt = cnt/2;
//     curr = head;
//     while (cnt > 0) {
//         cnt--;
//         curr = curr->next;
//     }
//     return curr;

// }


ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
        fast = fast ? fast->next : fast;
    }
    return slow;
}


ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    } else {
        ListNode * temp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
}


int main(){
    vector<int> vec = {1,2,3,4,5,6};
    // int val = 6;
    ListNode * head = makeList(vec);
    printListNode(head);

    // ListNode * ans = middleNode(head);
    ListNode * ans = reverseList(head);

    printListNode(ans);
    freeList(ans);

    // ListNode * ans = removeElements(head, val);
    // ListNode * ans ;
    // printVector(vec);
    // cout << "val: " << val << endl;

    // ListNode * ans = reverseList(head);
    // ListNode * ans = deleteDuplicates(head);

    // printListNode(ans);
    // freeList(ans);

    return 0;
}
