class Solution {
public:
    string makeFancyString(string s) {
        char lastChar = '#';
        int count = 0;
        string result = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == lastChar) count++;
            else{
                lastChar = s[i];
                count = 1;
            }
            if(count >= 3) continue;
            result += s[i];
        }
        return result;
    }
};