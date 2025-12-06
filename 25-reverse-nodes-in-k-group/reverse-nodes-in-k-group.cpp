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
    int solve(ListNode* head, int k){
      
        int cnt = 0;
        while(head!=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = solve(head,k);
        int rem = cnt/k; 

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        int j = 0;

        while(rem!=0){
            ListNode* st = prev->next;
            ListNode* then = st->next;
            for(int i =0;i<k-1;i++){
                st->next = then->next;
                then->next = prev->next;
                prev->next = then ;
                then = st->next;
            }
            // if(then!=NULL && then->next !=NULL)
            prev = st;

        
         
               rem--;
        }
        // prev->next = curr;
        return dummy->next;
        
    }
};