class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, minLen = INT_MAX, count = 0, startIndex = 0;
        unordered_map<char, int> freq;
        for(auto it : t) freq[it]++;
        while(right < s.size()){
            if(freq[s[right]] > 0){
                count++;
            }
            freq[s[right]]--;
            while(count == t.size()){
                if(minLen > (right - left + 1)){
                    startIndex = left;
                    minLen = right - left + 1;
                }
                freq[s[left]]++;
                if(freq[s[left]] > 0) count--;
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};