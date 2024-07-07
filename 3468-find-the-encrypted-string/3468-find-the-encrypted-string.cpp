class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string result;
        for(int i = 0; i < n; i++){
            result += s[(i + k) % n];
        }
        return result;
    }
};