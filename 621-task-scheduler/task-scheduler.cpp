class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> var(26, 0);
        for(auto i : tasks){
            var[i-'A']++;

        }
        priority_queue<int> pq;
        for(int i: var){
            if(i>0)
            pq.push(i);
        }
        int cnt = 0;
        queue<int> q;
        while(!pq.empty()||!q.empty()){

            int num = 0;
            while(num<n+1){
                if(!pq.empty())
                {
                int freq = pq.top();
                pq.pop();
                
                freq--;
                if(freq>0){
                    q.push(freq);
                }
                }
                cnt++;
                num++;
             if(pq.empty() && q.size()==0){
                    break;
                }
               
            }
            while(!q.empty()){
                int front = q.front();
                q.pop();
                pq.push(front);
            }
        }

        return cnt;
        
    }
};