class Solution {
public:
    bool checkCuts(vector<pair<int, int>>& proj){
        sort(proj.begin(), proj.end());
        vector<pair<int, int>> intervals;
        for(auto it : proj){
            if(intervals.empty()) intervals.push_back(it);
            else{
                if(it.first < intervals.back().second){
                    intervals.back().second = max(intervals.back().second, it.second);
                }else intervals.push_back(it);
            }
        }
        return intervals.size() >= 3;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xProj, yProj;
        for(auto it : rectangles){
            xProj.push_back({it[0], it[2]});
            yProj.push_back({it[1], it[3]});
        }
        return checkCuts(xProj) || checkCuts(yProj);
    }
};