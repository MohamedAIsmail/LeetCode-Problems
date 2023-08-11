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
    ListNode *removeElements(ListNode *head, int val)
    {
        // Base Cases
        if(!head) return head;
        if(head->val == val) return removeElements(head->next, val);

        ListNode *previous = head, *curr = head->next;
        
        while(curr){
            if(curr->val == val){
                previous->next = curr->next;
                curr = curr->next;
            }
            else{
                previous = previous->next;
                curr = curr->next;
            }
            
        }

        return head;
    }
};