class Solution {
public:
    int Nodecnt(ListNode* head){
        int cnt = 0;
        while(head->next!=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==1 && head->next ==  NULL){
            return NULL;
        }

        int cnt = Nodecnt(head);
        int rem = cnt - n +1;
        if(rem == 0){
            return head->next;
        }

        ListNode* prev = NULL;
        ListNode* next = head;


        while(rem){
           prev = next;
           next = next->next;
           rem--;
        }

        prev->next = next->next;
        next->next = NULL;

        return head;

        
    }
};
