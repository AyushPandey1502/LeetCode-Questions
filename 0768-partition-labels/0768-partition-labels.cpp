class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> map;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(map.count(s[i]) == 0) map[s[i]] = {i, i}; 
            else map[s[i]][1] = i;
        }

        vector<vector<int>> intervals;
        for(auto it : map) {
            intervals.push_back(it.second);
        }

        sort(intervals.begin(), intervals.end());
        vector<int> result;
        int start = intervals[0][0], end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] > end) {  
                result.push_back(end - start + 1);
                start = intervals[i][0];
                end = intervals[i][1];
            } else end = max(end, intervals[i][1]);
        }

        result.push_back(end - start + 1);
        return result;
    }
};
