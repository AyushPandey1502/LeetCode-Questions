class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        vector<int> result;
        int pos = 0, neg = 0;
        for(int x : nums){
            if(x > 0) positive.push_back(x);
            else negative.push_back(x);
        }
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0) result.push_back(positive[pos++]);
            else result.push_back(negative[neg++]);
        }
        return result;
    }
};