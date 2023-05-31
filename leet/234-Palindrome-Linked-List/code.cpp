#include <iostream>
#include <vector>
#include <algorithm>

/*
6
1 2 3 3 2 1

7
1 2 3 4 3 2 1
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* cur)  {
    ListNode* mid = cur;
    ListNode* fast = cur;
    // searching mid
    while(fast != nullptr && fast->next != nullptr) {
        mid = mid->next;
        fast = fast->next->next;
    }
    // reversing nodes after and including mid
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    ListNode* cur_head = mid;
    while (cur_head != nullptr) {
        next = cur_head->next;
        cur_head->next = prev;
        prev = cur_head;
        cur_head = next;
    }
    // comparing
    while (cur != nullptr && prev != nullptr) {
        if(prev->val == cur->val) {
            cur = cur->next;
            prev = prev->next;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n, v;
    std::cin >> n;
    ListNode head;
    ListNode *cur = &head;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> v;
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    bool res = isPalindrome(head.next);
    std::cout << (res ? "TRUE" : "FALSE") << std::endl;
}