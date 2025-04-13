/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL){
            return false;
        }
        ListNode* n1 = head;
        ListNode* n2 = head;

        while(n1!=NULL && n1->next!= NULL){
            n1 = n1->next->next;
            n2 = n2->next;

            if(n1 == n2){
                return true;
            }
        }
        return false;

        
    }
};