class Solution {
public:
    int result = 0;

    void countPath(TreeNode* root, int targetSum, long long currentSum, unordered_map<long long, int>& prefixSums) {
        if (root == NULL) return;

        currentSum += root->val;
        
        if (currentSum == targetSum) result++;
        if (prefixSums.find(currentSum - targetSum) != prefixSums.end()) {
            result += prefixSums[currentSum - targetSum];
        }
        
        prefixSums[currentSum]++;
        
        countPath(root->left, targetSum, currentSum, prefixSums);
        countPath(root->right, targetSum, currentSum, prefixSums);
        
        prefixSums[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        countPath(root, targetSum, 0, prefixSums);
        return result;
    }
};