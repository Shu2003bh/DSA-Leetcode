class MinStack {
    stack<long long> st; // Use long long to prevent overflow
    long long mini;      // Use long long for minimum value
    
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long value = val; // Convert to long long
        
        if(st.empty()) {
            st.push(value);
            mini = value;
        }
        else {
            if(value < mini) {
                // Store the encoded value using long long to prevent overflow
                st.push(2 * value - mini);
                mini = value;
            } else {
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty()) {
            return;
        }
        
        long long top_val = st.top();
        st.pop();
        
        if(top_val < mini) {
            // Decode to find the previous minimum
            long long prev_min = 2 * mini - top_val;
            mini = prev_min;
        }
    }
    
    int top() {
        if(st.empty()) {
            return -1;
        }
        
        long long top_val = st.top();
        
        if(top_val < mini) {
            // If encoded value, return current minimum
            return (int)mini;
        } else {
            return (int)top_val;
        }
    }
    
    int getMin() {
        if(st.empty()) {
            return -1;
        }
        return (int)mini;
    }
};