class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (const auto& path : logs) {
            if (path == "../") {
                if (result > 0) result--;
            } else if (path != "./") {
                result++;
            }
        }
        return result;
    }
};