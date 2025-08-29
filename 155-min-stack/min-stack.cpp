class MinStack {
public:
    long long mini;
    stack<long long> st;
    MinStack() {
        mini = INT_MAX;
        
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else
{
        if(value<mini){
            st.push(2*value-mini);
            mini = value;
        }
        else{
            st.push(val);

        }}
        
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }
        long long top = st.top();
        st.pop();

        if(top<mini){

            mini = 2*mini - top;
        }
        
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        long long top = st.top();

        if(mini>top){
            return (int)mini;
        }
        else{
            return (int)top;
        }
        
    }
    
    int getMin() {
         if(st.empty()){
            return -1;
        }
        return (int)mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */