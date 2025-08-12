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
    ListNode* getmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

   ListNode* getreverse(ListNode* head){
        if(head == NULL || head->next == NULL ){
            return head;
        }
        ListNode* h1 = getreverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return h1;

    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){return true;}
        //ListNode* curr = head;
        //1. Find Middle part
        ListNode* middle = getmiddle(head);
        //2. Reverse
        ListNode* temp = middle->next;
        middle->next = getreverse(temp);
       
        // 3. Compare
        ListNode* h1 = head;
        ListNode* h2 =middle->next;

        //4.move into orignal position
        while(h2!=NULL ){
            if(h1->val!=h2->val){
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }

        // temp =  middle->next;
        // middle->next =getreverse(temp);
        


        return true;
        


        
    }
};