class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int result = 0;
        for(int j = 1; j < n-1; j++){
            int leftMin = 0;
            int leftMax = 0;
            int rightMin = 0;
            int rightMax = 0;
            for(int i = j-1; i >= 0; i--){
                if(rating[i] < rating[j]) leftMin++;
                if(rating[i] > rating[j]) leftMax++;
            }
            for(int k = j+1; k < n; k++){
                if(rating[k] < rating[j]) rightMin++;
                if(rating[k] > rating[j]) rightMax++;
            }
            result += leftMin * rightMax + leftMax * rightMin;
        }
        return result;
    }
};