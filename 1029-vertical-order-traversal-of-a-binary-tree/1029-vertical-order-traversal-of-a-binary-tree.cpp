class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<pair<TreeNode*, vector<int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> nodes;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int x = q.front().second[0];
            int y = q.front().second[1];
            q.pop();
            nodes[x][y].insert(node->val);
            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        } 

        for(auto x : nodes){
            vector<int> temp;
            for(auto y : x.second) temp.insert(temp.end(), y.second.begin(), y.second.end());
            result.push_back(temp);
        }
        return result;
    }
};