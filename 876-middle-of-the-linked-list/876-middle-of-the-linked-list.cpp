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
    ListNode *middleNode(ListNode *head)
    {
        int counter = 0;
        ListNode *curr = head;
        ListNode *result = nullptr;

        while (curr != nullptr)
        {
            curr = curr->next;
            counter++;
        }

        int middleCounter = counter / 2;
        counter = 0;
        curr = head;

        while (curr != nullptr)
        {
            if (counter == middleCounter)
            {
                result = curr;
                break;
            }
            curr = curr->next;
            counter++;
        }

        return result;
    }
};