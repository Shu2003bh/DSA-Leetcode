class Solution {
public:
    ListNode* mergeTwoNode(ListNode* l1,ListNode* l2){
        if(l1==NULL || l2==NULL){
            return l1 == NULL ? l2 : l1;
        }

        if(l1->val>=l2->val){
            l2->next = mergeTwoNode(l1,l2->next);
            return l2;
        }
        else{
            l1->next = mergeTwoNode(l1->next,l2);
            return l1;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        ListNode* head = lists[0];
        for(int i =1;i<lists.size();i++){
            head = mergeTwoNode(head,lists[i]);
        }
        return head;
        
    }
};