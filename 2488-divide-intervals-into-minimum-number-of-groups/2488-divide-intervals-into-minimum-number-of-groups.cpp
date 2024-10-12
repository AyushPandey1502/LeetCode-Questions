class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> evts;
        for (auto& it : intervals) {
            evts.push_back({it[0], 1});
            evts.push_back({it[1] + 1, -1});
        }
        
        sort(evts.begin(), evts.end());
        
        int maxGrp = 0, currGrp = 0;
        for (auto& evt : evts) {
            currGrp += evt.second;
            maxGrp = max(maxGrp, currGrp);
        }
        
        return maxGrp;
    }
};
