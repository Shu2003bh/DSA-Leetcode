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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL ) return NULL;


        ListNode* temp1 = new ListNode(0);
        ListNode* temp2 = new ListNode(0);
        ListNode* smaller = temp1;
        ListNode* greater = temp2;

        while(head!=NULL){
            if(head->val<x){
                smaller->next = head;
                smaller = smaller->next;
            }
            else if(head->val>=x){
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
         smaller->next = temp2->next;
         greater->next = NULL;
         return temp1->next;




        
    }
};