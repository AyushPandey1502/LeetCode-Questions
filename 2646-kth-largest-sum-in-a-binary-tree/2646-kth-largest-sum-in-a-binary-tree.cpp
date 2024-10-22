class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        multiset<long long> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            long long lvlSum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lvlSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.insert(lvlSum);
        }
        if(result.size() < k) return -1;
        
        auto it = result.rbegin();
        advance(it, k - 1); 
        return *it;
    }
};
