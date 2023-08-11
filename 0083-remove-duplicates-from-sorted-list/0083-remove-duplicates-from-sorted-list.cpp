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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Base cases
        if(!head) return head;
        int arr[201] = {0}; // freq array
        
        arr[head->val + 100] = 1;
        
        ListNode *curr = head->next, *previous = head;

        while(curr){
            if(arr[curr->val + 100] == 1){
                previous->next = curr->next;
                curr = curr->next;
            }   
            else{
                arr[curr->val + 100] = 1;
                previous = previous->next;
                curr = curr->next;
            }
        }

        return head;
    }
};