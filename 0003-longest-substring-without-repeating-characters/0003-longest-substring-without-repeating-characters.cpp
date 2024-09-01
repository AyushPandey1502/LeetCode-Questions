// OPTIMIZED APPROACH - 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_map<char, int> map;

        while(right < s.size()){
            if(map.find(s[right]) == map.end() || map[s[right]] < left){
                map[s[right]] = right; 
                maxLen = max(maxLen, right - left + 1);
                right++;
            }else{
                left = map[s[right]] + 1; 
            }
        }
        return maxLen;
    }
};
