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
        void Insertattail(Node* &head,Node* &tail,int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;

            
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while(temp!=NULL){
            Insertattail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }

        temp = head;
        Node* temp2 = clonehead;
        unordered_map<Node*,Node*> oldtonew;
        while(temp!=NULL && temp2!=NULL){
            oldtonew[temp]=temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }

        temp = head;
        temp2 = clonehead;
        while(temp!=NULL && temp2!=NULL){
            temp2->random=oldtonew[temp->random];
            temp = temp->next;
            temp2 = temp2->next;

        }
        return clonehead;

        
    }
};