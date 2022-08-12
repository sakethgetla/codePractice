#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

// bool hasCycle(ListNode *head) {

//     unordered_map<ListNode*, int> m;
//     ListNode * curr = head;
//     while (curr != nullptr ) {
//         if (m.find(curr) != m.end()) {
//             return true;
//         } else {
//             m[curr] = 0;
//         }
//         curr = curr->next;
//     }
//     return false;
// }

bool hasCycle(ListNode *slow, ListNode *fast) {
    if (nullptr == fast ) {
        return false;
    } else if (slow == fast ) {
        return true;
    }

    fast = fast->next;

    if (nullptr == fast ) {
        return false;
    } else if (slow == fast ) {
        return true;
    }
    // fast = fast->next;
    // slow = slow->next;
    return hasCycle(slow->next, fast->next);
}

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }else {
        return hasCycle(head, head->next);
    }

}

int main(){
    vector<int> vec = {3,2,0,-4};
    ListNode * head = makeList(vec);
    ListNode * curr = head;
    while (curr->next != nullptr ) {
        curr = curr->next;
    }
    curr->next = head->next;

    bool ans = hasCycle(head);
    printVector(vec);
    cout << ans << endl;
    assert(ans);
    // freeList(head);

    return 0;
}
