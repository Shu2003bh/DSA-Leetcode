class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int n = points.size();
        for(int i =0;i<k;i++){
            int a = points[i][0];
            int b = points[i][1];
            int val = (a*a)+(b*b);
            pq.push({val,i});
        }

         for(int i =k;i<n;i++){
            int a = points[i][0];
            int b = points[i][1];
            int val = (a*a)+(b*b);

            if(pq.top().first > val){
                pq.pop();
                pq.push({val,i});
            }
           
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> temp;
            auto top = pq.top();
            pq.pop();
            temp.push_back(points[top.second][0]);
            temp.push_back(points[top.second][1]);
            ans.push_back(temp);
        }

        return ans;

        
    }
};
