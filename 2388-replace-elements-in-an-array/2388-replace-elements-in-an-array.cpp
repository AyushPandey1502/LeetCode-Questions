class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        unordered_map<int,int> hm; 
        for(int i =0;i<nums.size();i++){
            hm[nums[i]] = i; 
        }
        for(int i =0;i<operations.size();i++){
            nums[hm[operations[i][0]]] = operations[i][1];
            hm[operations[i][1]] = hm[operations[i][0]]; 
        }
        return nums;
    }
};