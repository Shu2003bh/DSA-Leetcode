#include<queue>/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class compare{
    public:
    bool operator()(ListNode* a,ListNode*b){
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k ==0){
            return NULL;
        }
    priority_queue<ListNode*,vector<ListNode*> ,compare> pq;
    for(int i = 0;i<k;i++){
        ListNode* temp = lists[i];
        if(lists[i] != nullptr)
        pq.push(temp);

    }

    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(pq.size()>0){
        ListNode* temp = pq.top();
        pq.pop();
        if(temp->next!=NULL){
            pq.push(temp->next);
        }

        if(head == NULL){
            head =temp;
            tail = temp;

        }
        else{
            tail->next = temp;
            tail = temp;
        }

    }
    return head;
        
    }
};