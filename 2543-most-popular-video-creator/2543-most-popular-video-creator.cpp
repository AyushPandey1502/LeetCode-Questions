class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                              vector<string>& ids,
                                              vector<int>& views) {
        unordered_map<string, pair<int, string>> mp;
        unordered_map<string, long long> popularity;
        long long maxViews = 0;

        for (int i = 0; i < views.size(); i++) {
            popularity[creators[i]] += views[i];
            maxViews = max(maxViews, popularity[creators[i]]);
            if (!mp.count(creators[i]) || mp[creators[i]].first < views[i] ||
                (mp[creators[i]].first == views[i] &&
                 mp[creators[i]].second > ids[i])) {
                mp[creators[i]] = {views[i], ids[i]};
            }
        }

        vector<vector<string>> result;
        for (auto& it : popularity) {
            if (it.second == maxViews) {
                result.push_back({it.first, mp[it.first].second});
            }
        }
        return result;
    }
};
