/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* newhead = new Node(head->val); 
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        unordered_map<Node*,Node*> mp;

        mp[head]=newtemp;
        while(oldtemp!=NULL){
            Node* node1 = new Node(oldtemp->val);
            mp[oldtemp] = node1;

            newtemp->next = node1;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        oldtemp = head;
        newtemp=newhead;
        while(oldtemp!=NULL){
            newtemp->random=mp[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        return newhead;



        
    }
};