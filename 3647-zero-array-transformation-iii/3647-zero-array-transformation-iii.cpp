class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),[](const vector<int>& a, const vector<int>& b){
                 return a[0] < b[0];
        });

        priority_queue<int> hp;
        vector<int> arr(nums.size() + 1, 0);
        int op = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            op += arr[i];
            while (j < queries.size() && queries[j][0] == i) {
                hp.push(queries[j][1]);
                j++;
            }
            while (op < nums[i] && !hp.empty() && hp.top() >= i) {
                op += 1;
                arr[hp.top() + 1]--;
                hp.pop();
            }
            if (op < nums[i]) return -1;
        }
        return hp.size();
    }
};