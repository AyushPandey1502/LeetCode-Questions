class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<double> averages;
        sort(nums.begin(), nums.end());
        while(left < right){
            double avg = (nums[left++] + nums[right--]) / 2.0;
            averages.push_back(avg);
        }
        return *min_element(averages.begin(), averages.end());
    }
};