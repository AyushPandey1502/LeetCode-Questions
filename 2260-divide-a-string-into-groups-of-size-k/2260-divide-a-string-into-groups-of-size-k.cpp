class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result; 
        int n = s.size();
        int curr = 0;  
        while (curr < n) {
            result.push_back(s.substr(curr, k));
            curr += k;
        }
        result.back() += string(k - result.back().length(), fill);
        return result;
    }
};