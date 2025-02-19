class Solution {
public:
    void generateStrings(string s, int n, int k, int& index, string& result) {
        if (n == 0) {
            index++;
            if (index == k) result = s;
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) { 
            if (!s.empty() && s.back() == ch) continue;
            generateStrings(s + ch, n - 1, k, index, result);
            if (!result.empty()) return; 
        }
    }

    string getHappyString(int n, int k) {
        string result;
        int index = 0;
        generateStrings("", n, k, index, result);
        return result;
    }
};
