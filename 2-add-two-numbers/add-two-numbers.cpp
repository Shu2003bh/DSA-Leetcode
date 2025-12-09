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
    void insertattail(ListNode* &head,ListNode* &tail,int d){
        ListNode* temp = new ListNode(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;

        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int a= 0,b=0,sum=0;
            if(l1!=NULL){
                a = l1->val;

            }

            if(l2!=NULL){
                b = l2->val;
            }
            sum = a+b+carry;
            int digit = sum%10;
            insertattail(head,tail,digit);
            carry = sum/10;

            if(l1!=NULL){
                l1 = l1->next;
            }
            if(l2!=NULL){
                l2 = l2->next;
            }


        }
        return head;

        
        
    }
};