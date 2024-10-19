class Solution {
public:
    string findString(string s, int i, int n){
        if(i == n) return s;
        string newStr = s + "1" ;
        reverse(s.begin(), s.end());
        for(int j = 0; j < s.size(); j++){
            newStr += (s[j] == '0' ? "1" : "0");
        }
        return findString(newStr, i + 1, n);
    }
    char findKthBit(int n, int k) {
        string result = findString("0", 1, n);
        return result[k - 1];
    }
};