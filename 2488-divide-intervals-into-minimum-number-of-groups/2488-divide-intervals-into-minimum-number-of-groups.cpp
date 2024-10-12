class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> events;
        
        for (auto interval : intervals) {
            events[interval[0]]++; 
            events[interval[1] + 1]--;  
        }
        
        int maxGroups = 0;
        int currGroups = 0;
        for (auto event : events) {
            currGroups += event.second;
            maxGroups = max(maxGroups, currGroups);
        }
        return maxGroups;
    }
};
