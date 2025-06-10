class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int, int> map;
        for(auto it : s) map[it]++;
        int oddMax = 1, evenMin = s.size();
        for(auto it : map){
            if(it.second % 2 == 1) oddMax = max(oddMax, it.second);
            else evenMin = min(evenMin, it.second);
        }
        return oddMax - evenMin;
    }
};