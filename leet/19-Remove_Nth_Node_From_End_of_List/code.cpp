/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <deque>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** new_head = &head;
        ListNode* cur_head = head;
        std::deque<ListNode** > d;
        int c = 0;
        while (cur_head != nullptr)
        {
            if (d.size() > n) {
                d.pop_front();
            }
            d.push_back(&cur_head);
            cur_head = cur_head->next;
        }
        if(d.size() >= n) {
            ListNode** p1 = d[0];
            ListNode** p2 = d[1];
            (*p1)->next = (*p2)->next;
        }
        return *new_head;
    }
};