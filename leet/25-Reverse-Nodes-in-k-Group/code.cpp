/*
Given the head of a linked list, reverse the nodes of the list k at a time, and
return the modified list.

k is a positive integer and is less than or equal to the length of the linked
list. If the number of nodes is not a multiple of k then left-out nodes, in the
end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be
changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

5
1 2 3 4 5
3

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <string>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* first, ListNode* last) {
    ListNode* cur_head = first;
    ListNode* next_node = nullptr;
    ListNode* prev_node = last;
    while (cur_head != last) {
       next_node = cur_head->next;
       cur_head->next = prev_node;
       prev_node = cur_head;
       cur_head = next_node;
    }
    return prev_node;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) {
        return head;
    }
    ListNode* new_head_p = nullptr;
    ListNode* cur_head = head;
    ListNode* cur_tail = head;

    for(int i = 0 ; i < k ; ++i) {
        if (cur_tail == nullptr ) {
            return head;
        }
        cur_tail = cur_tail->next;
    }
    new_head_p = reverse(cur_head, cur_tail);
    head->next = reverseKGroup(cur_tail, k);

    return new_head_p;
}

void printList(ListNode *head) {
    ListNode *cur_node = head;
    while(cur_node != nullptr){
        std::cout << cur_node->val << " ";
        cur_node = cur_node->next;
    }
    std::cout << std::endl;
}

int main() {
    int n, x, k;
    ListNode head;
    ListNode* cur_node = &head;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> x;
        cur_node->next = new ListNode(x);
        cur_node = cur_node->next;
    }
    std::cin >> k;
    ListNode* res = reverseKGroup(head.next, k);
    // ListNode* res = reverse(head.next, nullptr);
    printList(res);
}

/*
9
1 2 3 4 5 6 7 8 9
3

5
1 2 3 4 5
3

9
1 2 3 4 5 6 7 8 9
2

*/