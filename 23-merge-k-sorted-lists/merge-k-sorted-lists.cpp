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

    ListNode* merged(ListNode* l1,ListNode* l2){
        if(!l1){
            return l2;

        }
        if(!l2){
            return l1;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(l1&&l2){
            if(l1->val > l2->val){
                curr->next = l2;
                l2 = l2->next;
            }
            else{
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }

        while(l1){
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }

        while(l2){
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }

        return dummy->next;
    }

    ListNode* solve(int left,int right,vector<ListNode*>& lists){
        if(left>right){
            return NULL;
        }
        if(left == right){
    return lists[left];
}


        int mid = (left + right)/2;
        ListNode*l1 = solve(left,mid,lists);
        ListNode*l2 = solve(mid+1,right,lists);
        return merged(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;      
              }
              return solve(0,lists.size()-1,lists);
        
    }
};