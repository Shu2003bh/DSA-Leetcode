class Solution {
public:
    int evalRPN(vector<string>& s) {
  stack<int> st;
        int total =0;
        for(int i =0;i<s.size();i++){
            string token = s[i];
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                if(s[i]=="+"){
                    
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    total = b+a;

                }

                else if(s[i]=="-"){
                     int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    total = b-a;

                }

                else if(s[i] == "/"){
                      int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    total = b/a;

                }

                else{
                     int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    total = b*a;


                }
                st.push(total);
            }
            
            else{
                st.push(stoi(s[i]));
            }
            
       

        }
        total = st.top();
        st.pop();
        return total;
    }
};