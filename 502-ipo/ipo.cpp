class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        vector<pair<int,int>> project;
        for(int i = 0; i < n; i++){
        project.push_back({capital[i], profits[i]});
        }
        sort(project.begin(),project.end());
        int i = 0;
        priority_queue<int> maxheap;
        while(k>0){
            while(i<n && project[i].first<=w ){
                maxheap.push(project[i].second);
                i++;
            }

            if(maxheap.size()==0){
                break;

            }
            int profit = maxheap.top();
            maxheap.pop();

            w += profit;
            k--;


        }
        return w;
    
        
    }
};