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
        Node* temp = head;
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        // Step1- Create a Clone List
        while(temp!=NULL){
            Insertattail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }

        // Step 2- Create  a relation between original node and clone node
        Node* ognode = head;
        Node* clnode = clonehead;

        while(ognode!=NULL ){
            Node* ptr1 = ognode->next;
            ognode->next = clnode;
            ognode = ptr1;

            Node* ptr2 = clnode->next;
            clnode->next = ognode;
            clnode = ptr2;
        }

        //step3- make pointer of         
        temp = head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;

        }
        //step  4 - revert;
        ognode = head;
        clnode = clonehead;

        while(ognode!=NULL ){
           ognode->next = clnode->next;
           ognode = ognode->next;
           if(ognode!=NULL){
            clnode->next = ognode->next;
           }
           clnode =clnode->next;
        }

        return clonehead;


        
    }
};