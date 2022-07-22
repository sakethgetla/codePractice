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

template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << "->" ;
    }
    cout << endl;
}

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


ListNode* swapPairs(ListNode* head) {

    if(head == nullptr){
        return nullptr;
    } else if(head->next == nullptr){
        return head;
    } else {
        ListNode * temp = head;
        ListNode * tail = swapPairs(head->next->next);
        head = head->next;
        head->next = temp;
        head->next->next = tail;
        return head;
    }
    return nullptr;
}

int main(){

    int a[5] = {1,2,3,4,5};
    ListNode *head = makeList(a, 5);
    printListNode(head);
    ListNode *swapped = swapPairs(head);
    printListNode(swapped);

    head = nullptr;
    printListNode(head);
    swapped = swapPairs(head);
    printListNode(swapped);



    head = makeList(a, 1);
    printListNode(head);
    swapped = swapPairs(head);
    printListNode(swapped);

    return 0;
}
