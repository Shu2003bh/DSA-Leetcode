/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* frwd = node->next ;
        while(frwd->next!=NULL){
            temp->val = frwd->val;
            frwd = frwd->next;
            temp = temp->next;
            
        }
       
       temp->val = frwd->val;
       temp->next = NULL;
      
        
    }
};