#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode *head){
    if (head != nullptr){
        cout << head->val << "->" ;
        printListNode(head->next);
    } else {
        cout << "null" << endl;
    }
}

ListNode * makeList(int *ptr, int length) {
    if (length > 0){
        // ListNode n = ListNode(*ptr, makeList(&ptr[1], length--));
        ListNode *a = (struct ListNode*) malloc(sizeof(struct ListNode));
        a->val = *ptr;
        a->next = makeList(&ptr[1], --length);
        // a = ListNode(*ptr, makeList(&ptr[1], length--));
        return a;
    }
    return nullptr;
}

// ListNode * removeNthFromEnd(ListNode *head, int n){
//     ListNode* plist[30];
//     ListNode* curr = head;
//     int len = 0;



//     while(curr != nullptr){
//         plist[len] = curr;
//         len++;
//         curr = curr->next;
//     }


//     if(n == len){
//         return head->next;
//     } else if (n == 1) {
//         plist[len-2]->next = nullptr;
//     } else {
//         plist[len-n-1]->next = plist[len-n-1]->next->next;
//     }

//     return head;
// }

ListNode * removeNthFromEnd(ListNode *head, int n){
    ListNode * fast = head;
    ListNode * slow = head;

    while(n > 0){
        fast = fast->next;
        n--;
    }

    if(!fast){
        return head->next;
    }

    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
        // cout << "here" << endl;

    slow->next = slow->next->next;

    return head;
}



int main(){
    int a[5] = {1,2,3,4,5};
    ListNode *head = makeList(a, 5);
    printListNode(head);
    head = removeNthFromEnd(head, 5);
    printListNode(head);
    head = removeNthFromEnd(head, 2);
    printListNode(head);
    head = removeNthFromEnd(head, 1);
    printListNode(head);

    // for (int i : a){

    // }
    return 0;
}
