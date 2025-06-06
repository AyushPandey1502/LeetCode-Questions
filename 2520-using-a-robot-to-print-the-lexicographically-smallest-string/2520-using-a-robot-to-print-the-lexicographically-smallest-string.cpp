class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> count;
        for (char it : s) count[it]++;

        stack<char> stk;
        string result;
        char minChar = 'a';
        for (char it : s) {
            stk.emplace(it);
            count[it]--;
            while (minChar != 'z' && count[minChar] == 0) minChar++;
            while (!stk.empty() && stk.top() <= minChar) {
                result.push_back(stk.top());
                stk.pop();
            }
        }
        return result;
    }
};