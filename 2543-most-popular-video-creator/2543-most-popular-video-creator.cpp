class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, set<pair<long long, string>>> mp;
        unordered_map<string, long long> popularity;
        long long maxViews = 0;
        for(int i = 0; i < views.size(); i++){
            popularity[creators[i]] += views[i];
            maxViews = max(maxViews, popularity[creators[i]]);
            mp[creators[i]].insert({-views[i], ids[i]});
        }
        vector<vector<string>> result;
        for(auto it : popularity){
            if(it.second == maxViews){
                result.push_back({it.first, mp[it.first].begin()->second});
            }
        }
        return result;
    }
};