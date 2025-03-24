class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int result = 0, end = 0;
        sort(meetings.begin(), meetings.end());
        for(auto it : meetings){
            if(it[0] > end + 1) result += it[0] - end - 1;
            end = max(end, it[1]);
        }
        result += days - end;
        return result;
    }
};