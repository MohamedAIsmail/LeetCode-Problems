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
   ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Base Case
        if(head == NULL || k == 1)
            return head;

        ListNode *curr = head;
        ListNode *prev = NULL, *next = NULL;

        int ctr = 0;
        while(curr && ctr < k)
        {
            curr = curr->next;
            ctr++;
        }

        if(ctr < k)
            return head;

        

        // Recursive approach to reverse the list
        curr = head;    
        for(int i = 0; i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ctr++;
        }
        head->next = reverseKGroup(next, k);

            
        
        return prev;
    }
};