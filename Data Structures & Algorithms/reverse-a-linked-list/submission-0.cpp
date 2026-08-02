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

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head) return head;

        auto ptr = head;
        ListNode* prev = nullptr;

        while (ptr)
        {
            auto ptr_next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = ptr_next;
        }

        return prev;
    }
};
