class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;  
        
        while(!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currLevel;
            int totalSum = 0;
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currLevel.push_back(node);
                if(node->left) {
                    q.push(node->left);
                    totalSum += node->left->val;
                }
                if(node->right) {
                    q.push(node->right);
                    totalSum += node->right->val;
                }
            }
            for(TreeNode* node : currLevel) {
                int siblingSum = 0;
                if(node->left) siblingSum += node->left->val;
                if(node->right) siblingSum += node->right->val;
                
                if(node->left) 
                    node->left->val = totalSum - siblingSum;
                if(node->right)
                    node->right->val = totalSum - siblingSum;
            }
        }
        return root;
    }
};