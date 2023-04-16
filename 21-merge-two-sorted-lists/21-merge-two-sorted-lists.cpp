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
   ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Check for zero cases
        if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr)
        {
            return list1;
        }

        // Creating pointer to the first or second list based on whose first element is smaller
        ListNode *ptr = list1;
        if (list1->val > list2->val)
        {
            ptr = list2;
            list2 = list2->next;
        }
        else
        {
            list1 = list1->next;
        }

        // Create current pointer refering to the storage ptr and adding to it
        ListNode *curr = ptr;

        // Loop over both lists until one of them is finished
        while (list1 != nullptr && list2 != nullptr)
        {
            // If list1 val is bigger than list2 val then list2 val is smaller and point the next of curr and ptr to list2
            if (list1->val > list2->val)
            {
                curr->next = list2;
                list2 = list2->next;
            }
            else
            {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }

        // adding remaining elements of bigger list.
        if (!list1)
            curr->next = list2;
        else
            curr->next = list1;

        return ptr;
    }
};