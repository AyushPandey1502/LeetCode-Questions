class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> q;
        for(int x: nums){
            if((x&1)==1) 
                q.push_back(x);
            else
                q.push_front(x);     
        }
        return vector<int>(q.begin(), q.end());
    }
};