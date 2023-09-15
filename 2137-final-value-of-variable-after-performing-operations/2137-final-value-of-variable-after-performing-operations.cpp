class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (const string& str : operations) {
            X += (str[1] == '+') ? 1 : -1;
        }
        return X;
    }
};
