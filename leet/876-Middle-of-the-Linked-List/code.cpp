#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
11
1 2 3 4 5 6 7 8 9 10 11
1
1
*/ 
ListNode* middleNode(ListNode* head) {
    ListNode* slow_p = head;
    ListNode* fast_p = head;
    while (fast_p != nullptr && fast_p->next != nullptr ) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
    }
    return slow_p;
}

int main() {
    int n, v;
    std::cin >> n;
    ListNode *head = new ListNode();
    ListNode *node = head;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> v;
        node->next = new ListNode(v);
        node = node->next ;
    }
    ListNode *res = middleNode(head->next);
    std::cout << res->val << std::endl;;
}