#include <iostream>
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *next_node;
        ListNode *prev_node = nullptr;
        while (head != nullptr)
        {
            next_node = head->next;
            head->next = prev_node;
            prev_node = head;
            head = next_node;
        }
        return head;
    }
};

int main() {

}