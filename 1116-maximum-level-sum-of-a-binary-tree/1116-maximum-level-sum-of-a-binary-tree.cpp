class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        set<pair<int, int>> levelSum;
        int lvl = 1;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            levelSum.insert({sum, lvl++});
        }
        int maxLevelSum = INT_MIN;
        int level = -1;
        for(auto it : levelSum){
            if(it.first > maxLevelSum){
                maxLevelSum = it.first;
                level = it.second;
            }
        }
        return level;
    }
};