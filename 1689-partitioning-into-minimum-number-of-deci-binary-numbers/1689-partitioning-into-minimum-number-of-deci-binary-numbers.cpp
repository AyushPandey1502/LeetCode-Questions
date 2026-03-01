class Solution {
public:
    int minPartitions(string n) {
        int result = 0;
        for (auto it : n){
            result = max(result, it - '0');
        }
        return result;
    }
};