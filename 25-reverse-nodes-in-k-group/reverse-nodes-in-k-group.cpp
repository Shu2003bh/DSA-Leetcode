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
 ListNode* kthnode( ListNode* head ,int k){
     ListNode* temp =head;
     k-=1;
     while(temp!=NULL && k>0){
        k--;
        temp = temp->next;
     }
     return temp;
 }
  ListNode* rev( ListNode* head){
    if(head == NULL || head->next==NULL){
        return head;
    }
     ListNode* temp = rev(head->next);
     head->next->next=head;
     head->next = NULL;
     return temp;
  }
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* temp = head;
          ListNode* prev = NULL;
          while(temp!=NULL){
             ListNode* knode = kthnode(temp,k);
             if(knode==NULL){
                if(prev){
                    prev->next=temp;
                }
                break;
             }
              ListNode* nextnode = knode->next;
              knode->next = NULL;

               ListNode* revhead = rev(temp);
               if(temp == head){
                head = revhead;
               }else{
                prev->next = revhead;
               }

               prev = temp;
               temp = nextnode;
          }
          return head;

        
    }
};