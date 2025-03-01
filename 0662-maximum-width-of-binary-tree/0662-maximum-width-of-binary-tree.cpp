class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        long long result = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            long long size = q.size();
            long long first, last, min = q.front().second;
            for(int i = 0; i < size; i++){
                long long index = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = index;
                if(i == size-1) last = index;
                if(node->left) q.push({node->left, 2*index+1});
                if(node->right) q.push({node->right, 2*index+2});
            }
            result = max(result, last - first + 1);
        }
        return result;
    }
};