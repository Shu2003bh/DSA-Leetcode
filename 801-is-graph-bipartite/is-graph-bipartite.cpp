class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> col(n,-1);
        for(int i =0;i<n;i++){
            queue<int> q;
            if(col[i]==-1){
            col[i]=0;
            q.push(i);
            }
            while(!q.empty()){
                int top = q.front();
                q.pop();
                for(auto nbr : graph[top]){
                    if(col[nbr]==-1){
                        col[nbr]=1-col[top];
                        q.push(nbr);
                    }
                    if(col[nbr]==col[top]){
                        return false;
                    }
                }
            }

        }
        return true;
        
    }
};