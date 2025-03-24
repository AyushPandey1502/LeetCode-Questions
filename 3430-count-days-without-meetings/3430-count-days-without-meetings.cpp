class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> events;
        
        for (auto it : meetings) {
            events.push_back({it[0], 1});
            events.push_back({it[1] + 1, -1});
        }
        sort(events.begin(), events.end());
        int result = 0, active = 0, end = 1;
        
        for (auto it : events) {
            int currDay = it.first;
            if (active == 0) result += (currDay - end);
            active += it.second;
            end = currDay;
        }
        if (active == 0) result += (days - end + 1);
        return result;
    }
};
