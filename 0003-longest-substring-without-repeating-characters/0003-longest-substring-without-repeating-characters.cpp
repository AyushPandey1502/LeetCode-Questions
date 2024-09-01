// OPTIMIZED APPROACH - 2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_set<int> set;

        for(int right = 0; right < s.size(); right++){
            if(set.find(s[right]) != set.end()){
                while(left < right && set.find(s[right]) != set.end()){
                    set.erase(s[left++]);
                }
            }
            set.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
