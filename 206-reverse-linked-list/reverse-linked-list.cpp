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
ListNode* Reverse(ListNode* &head) {
    if(head==NULL || head->next ==NULL){
        return head;
    }
   
    ListNode* temp = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
    ListNode* reverseList(ListNode* head) {
  
        return Reverse(head);
         
        
        
    }
};