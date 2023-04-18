/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // Initialize two pointers, slow and fast, to the head of the linked list.
        ListNode *slow = head;
        ListNode *fast = head;


        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        // If the fast pointer reaches the end of the list without meeting the slow pointer,
        // there is no cycle in the linked list. Return nullptr.
        return nullptr;
    }
};