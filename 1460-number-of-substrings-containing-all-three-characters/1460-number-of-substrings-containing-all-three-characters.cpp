class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        unordered_map<char, int> map;
        int left = 0, right = 0, n = s.size();
        while(right < n){
            map[s[right]]++;
            while(left < right && map.size() == 3){
                count += n - right;
                if(--map[s[left]] == 0) map.erase(s[left]);
                left++;
            }
            right++;
        }
        return count;
    }
};