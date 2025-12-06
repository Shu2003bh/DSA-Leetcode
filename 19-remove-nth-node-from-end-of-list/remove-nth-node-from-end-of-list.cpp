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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL ){
            return NULL;
        }

        int cnt = solve(head);
    if(cnt == n){
        if(head->next == NULL){
            return NULL;
        }
        ListNode* temp = head->next;
        delete(head);
        return temp;
    }

    

        int num = cnt-n;
        int i =0;
        ListNode* curr = head;
        while(i!=num-1){
            curr = curr->next;
            i++;

        }
        ListNode* temp = curr->next;
        if(curr->next!=NULL){
        curr->next = temp->next;
        temp->next = NULL;
        }
        else{
            curr->next = NULL;
        }
        delete(temp);
        return head;



        
    }
};