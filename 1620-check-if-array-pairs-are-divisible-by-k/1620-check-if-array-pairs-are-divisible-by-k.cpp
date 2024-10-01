class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        for (int num : arr) {
            int rem = ((num % k) + k) % k;
            map[rem]++;
        }
        
        for (auto& [rem, count] : map) {
            if (rem == 0) { 
                if (count % 2 != 0) return false;
            } else if (map[rem] != map[k - rem]) {
                return false;
            }
        }
        return true;
    }
};
