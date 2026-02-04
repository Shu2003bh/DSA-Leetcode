class Solution {
public:
    void kahns(int n,unordered_map<int,list<int>> &adj,int &cnt){
        vector<int> indeegre(n);
        for(int i =0;i<n;i++){
            for(auto j:adj[i]){
                indeegre[j]++;
            }
        }
        queue<int> q;
 
        for(int i =0;i<n;i++){
            if(indeegre[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            cnt++;
            for(auto i : adj[top]){
                indeegre[i]--;
                if(indeegre[i]==0){
                    q.push(i);
                }
            }

        }
       




    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
        }
        int cnt = 0;

        kahns(numCourses,adj,cnt);
        if(cnt<numCourses){
            return false;
        }
        else{
            return true;
        }
        
    }
};