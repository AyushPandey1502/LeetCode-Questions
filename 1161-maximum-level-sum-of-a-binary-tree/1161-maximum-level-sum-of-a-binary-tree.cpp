class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN, maxLvl = 0;     
        int currLvl = 1;  

        while(!q.empty()) {
            int size = q.size();
            int lvlSum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lvlSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(lvlSum > maxSum) {
                maxSum = lvlSum;
                maxLvl = currLvl;
            }
            currLvl++; 
        }
        return maxLvl;
    }
};
