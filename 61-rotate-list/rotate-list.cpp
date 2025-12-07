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
  int solve(ListNode* head){
      
        int cnt = 0;
        while(head!=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next==NULL || k==0 ){
            return head;
        }

        int n = solve(head);
         k = k%n;
        if(k==0){
            return head;
        }
        int len = n-k;
        ListNode* tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        tail->next = head;

        ListNode* temp1 = head;
        for(int i =1;i<len;i++){
            temp1=temp1->next;
        }

        ListNode* temp2 = temp1->next;
        temp1->next = NULL;

        return temp2;



       

        
    }
};