class Solution {
public:
    int calculate(int i, string s, unordered_set<string> set, unordered_map<int, int>& map){
        if(i >= s.size()) return 0;
        if(map.count(i)) return map[i];
        int result = 1 + calculate(i + 1, s, set, map);
        for(int j = i; j < s.size(); j++){
            string str = s.substr(i, j - i + 1);
            if(set.count(str)){
                result = min(result, calculate(j + 1, s, set, map));
            }
        }
        return map[i] = result;
    }
    int minExtraChar(string s, vector<string>& dict) {
        unordered_map<int, int> map;
        unordered_set<string> set(dict.begin(), dict.end());
        return calculate(0, s, set, map);
    }
};