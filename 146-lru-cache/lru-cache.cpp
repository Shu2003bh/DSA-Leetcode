class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key,int val){
            this->key = key;
            this->val = val;
        }

    };
    int cap;
    unordered_map<int,Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;    
    }

    void AddNode(Node* newnode){
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;


    }
    void DelNode(Node* newnode){

        Node* prevv = newnode->prev;
        Node* nextt = newnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;

    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* res = mp[key];
            int ans = res->val;
            DelNode(res);
            mp.erase(key);

            AddNode(res);
            mp[key]= head->next;
            return ans;

        }
        return -1;


        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
             Node* res = mp[key];
            DelNode(res);
            mp.erase(key);


        }

        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            DelNode(tail->prev);
        }

        AddNode(new Node(key,value));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */