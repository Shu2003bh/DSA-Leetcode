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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        vector<int> arr;
        for(auto i : lists){
            if(i==NULL){
                continue;
            }
           while(i!=NULL){
            arr.push_back(i->val);
            i = i->next;
           }
        }
        if(arr.size() == 0) return NULL;

        sort(arr.begin(),arr.end());
        ListNode* head = new ListNode(arr[0]);
       ListNode*  curr = head;
        // curr = curr->next;
        for(int i =1;i<arr.size();i++){
            ListNode* node = new ListNode(arr[i]);
                curr->next = node;
                curr = curr->next;

            

        }
        
            return head;


        
    }
};