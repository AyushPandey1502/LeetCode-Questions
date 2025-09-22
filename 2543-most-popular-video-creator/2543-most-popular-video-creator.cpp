struct Info {
    long long totalViews = 0;
    int bestViews = -1;
    string bestId;
};

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                              vector<string>& ids,
                                              vector<int>& views) {
        unordered_map<string, Info> data;
        long long maxViews = 0;

        for (int i = 0; i < views.size(); i++) {
            auto& info = data[creators[i]];
            info.totalViews += views[i];
            maxViews = max(maxViews, info.totalViews);
            if (views[i] > info.bestViews ||
                (views[i] == info.bestViews && ids[i] < info.bestId)) {
                info.bestViews = views[i];
                info.bestId = ids[i];
            }
        }
        vector<vector<string>> result;
        for (auto& [creator, info] : data) {
            if (info.totalViews == maxViews) {
                result.push_back({creator, info.bestId});
            }
        }
        return result;
    }
};
