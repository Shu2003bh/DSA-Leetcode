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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        

        ListNode* curr = prev->next;
        while(curr!=NULL && curr->next!=NULL){
        bool isflag = false;
            while(curr->next != NULL && curr->val == curr->next->val){
                isflag = true;
                curr = curr->next;
            }

            if(isflag){
                prev->next = curr->next;
                
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
        
        
    }
};