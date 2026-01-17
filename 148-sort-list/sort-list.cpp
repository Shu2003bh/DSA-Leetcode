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
ListNode* solve(vector<int>& arr) {
    if(arr.size() == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for(int i = 1; i < arr.size(); i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}
    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        vector<int> nums ;
        ListNode* curr = head;

        while(curr!=NULL && curr->next!=NULL){
            nums.push_back(curr->val);
            curr = curr->next;
        }
        nums.push_back(curr->val);

        sort(nums.begin(),nums.end());
        curr = solve(nums);
        return curr;


        
    }
};