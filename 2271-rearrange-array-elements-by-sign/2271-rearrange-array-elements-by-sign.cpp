class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos;
        queue<int> neg;
        vector<int> result;
        for (int x : nums) {
            if (x > 0) pos.push(x);
            else neg.push(x);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                result.push_back(pos.front());
                pos.pop();
            } else {
                result.push_back(neg.front());
                neg.pop();
            }
        }
        return result;
    }
};