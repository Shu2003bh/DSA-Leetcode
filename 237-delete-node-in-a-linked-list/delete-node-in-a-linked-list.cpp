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
        ListNode* nextone=node->next;
        while( nextone->next !=NULL){
           temp->val = nextone->val;
           nextone = nextone->next;
           temp = temp->next;

        }
       temp->val = nextone->val;
       temp->next = NULL;
        
        
    }
};