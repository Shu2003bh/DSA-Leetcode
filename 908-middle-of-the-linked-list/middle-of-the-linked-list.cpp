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
ListNode* getmiddle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        if(head->next->next == NULL){
            return head->next;
        }
        return getmiddle(head);
        // ListNode* fast = head->next;
        // ListNode* slow = head;
        // while(fast!=NULL){
        //     fast = fast->next;
        //     if(fast!=NULL){
        //         fast = fast->next;
        //     }
        //     slow = slow->next;
        // }
        // return slow;

        
    }
};