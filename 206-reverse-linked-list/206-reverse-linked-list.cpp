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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *previousResult = nullptr;
        ListNode *forward;
        ListNode *curr = head;

        // Initial check if the head is empty to avoid extra time
        if (head == nullptr)
            return head;

        while (curr != nullptr)
        {
            forward = curr->next;
            curr->next = previousResult;
            previousResult = curr;
            curr = forward;
        }
        return previousResult;
    }
};