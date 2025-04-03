class Solution {
public:

    vector<int> nextsmallerelment(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i = n-1;i>=0;i--){
            int curr = arr[i];

            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

     vector<int> prevsmallerelment(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n) ;
        stack<int> st;
        st.push(-1);

        for(int i = 0;i<n;i++){
            int curr = arr[i];

            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextsmallerelment(heights);

        vector<int> prev(n);
        prev = prevsmallerelment(heights);

        int area = INT_MIN;
        for(int i =0;i<n;i++){
            int l = heights[i];

            if(next[i]==-1){
                next[i]=n;
            }
            int b = next[i]-prev[i]-1;

            int newarea = l*b;
            area = max(area,newarea);
        }
        return area;


        
    }
};