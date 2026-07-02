class Twitter {
public:
    unordered_map<int,unordered_set<int>> flw;
    unordered_map<int,vector<pair<int,int>>> twt;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {

        time++;
        twt[userId].push_back({time,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto i : twt[userId]){
            pq.push({i.first,i.second});
        }

        

        for(auto i : flw[userId]){
            for(auto j : twt[i]){
                 pq.push({j.first,j.second});
                
            }
        }
        vector<int> res;

        while(!pq.empty() && res.size()<10){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
        
    }
    
    void follow(int followerId, int followeeId) {

        flw[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        flw[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */