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

    void Insertattail(ListNode* &head,ListNode* &tail,int d){
        ListNode* temp =new ListNode(d) ;
        if(head==NULL){
            head = temp ;
            tail = temp ;
            return;

        }
        else{
            tail->next = temp;
            tail=temp;
        }
    }

    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp = rev(head->next);
        head->next->next= head;
        head->next = NULL;
        return temp;
    }

    ListNode* add(ListNode* head1,ListNode* head2){
        int carry = 0;
        ListNode* anshead = NULL;
        ListNode* anstail = NULL;
        while(head1!=NULL || head2!=NULL || carry!=0 ){
            int val1 = 0;
            if(head1 != NULL){
                val1 = head1->val;
            }
            int val2 = 0;
            if(head2!=NULL){
                val2 = head2->val;
            }

            int sum = carry + val1 +val2;
            int digit = sum %10;
            Insertattail(anshead,anstail,digit);
            carry = sum/10;
            if(head1!=NULL)
              head1 = head1->next;
            if(head2 !=NULL)
               head2 = head2->next;

            

        }
        return anshead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;

        ListNode* ans = add(first,second);

        //ans = rev(ans);
        return ans;

        
    }
};