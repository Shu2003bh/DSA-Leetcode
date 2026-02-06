class Solution {
public:

    bool dfs(string a , string b,double &temp,unordered_map<string,vector<pair<string,double>>> &mp, unordered_set<string> &vis){
        if(a==b){
            return true;
        }
        vis.insert(a);


        for(auto i :mp[a]){
        string nbr = i.first;
        double wt = i.second;

        if(vis.count(nbr)){
            continue;
        }

        else if(vis.count(nbr)==0){
            temp *= wt;
            bool cycle = dfs(nbr,b,temp,mp,vis);
            if(cycle){
                return true;
            }
            temp /= wt;
        }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string,vector<pair<string,double>>> mp;

        for(int i =0;i<equations.size();i++){
            string a= equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            mp[a].push_back({b,val});
            mp[b].push_back({a,1/val});
        }
        vector<double> ans;

        for(int i =0;i<queries.size();i++){

            string a = queries[i][0];
            string b = queries[i][1];

            if(mp.count(a)==0 || mp.count(b)==0){
                ans.push_back(-1);
            }
            else{
                unordered_set<string> vis;
                double temp = 1;
                if(dfs(a,b,temp,mp,vis)){
                    ans.push_back(temp);
                }

                else{
                    ans.push_back(-1);
                }
            }

        }

        return ans;
        


    }
};