class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for(auto it : intervals){
            if(result.empty()) result.push_back(it);
            else{
                if(it[0] <= result.back()[1]){
                    result.back()[1]= max(result.back()[1], it[1]);
                }else result.push_back(it);
            }
        }
        return result;
    }
};