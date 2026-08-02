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

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        auto ptr1 = list1;
        auto ptr2 = list2;

        ListNode dummy;
        auto head_ptr = &dummy;

        while (ptr1 && ptr2)
        {
            if (ptr1->val < ptr2->val)
            {
                head_ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                head_ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            head_ptr = head_ptr->next;
        }

        if (ptr1) head_ptr->next = ptr1;
        if (ptr2) head_ptr->next = ptr2;

        return dummy.next;
    }
};
