/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/
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


ListNode* merge(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) {
        return l2;
    } 
    if(l1 == nullptr) {
        return l1;
    }
    if(l1->val > l2->val) {
        l2->next = merge(l1, l2->next);
        return l2;
    } else {
        l1->next = merge(l2, l1->next);
        return l1;
    }
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode* res = nullptr;
    for(int i = 0 ; i < lists.size() ; ++i) {
        res = merge(lists[i], res);
    }
    return res;
}


int main() {

}