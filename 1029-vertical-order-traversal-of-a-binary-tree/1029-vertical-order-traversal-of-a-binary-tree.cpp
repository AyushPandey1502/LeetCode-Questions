class Solution {
public:
    map<int, map<int, multiset<int>>> nodes;

    void dfs(TreeNode* root, int x, int y){
        if(root == nullptr) return;
        nodes[x][y].insert(root->val);
        dfs(root->left, x-1, y+1);
        dfs(root->right, x+1, y+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        dfs(root, 0, 0);

        for(auto x : nodes){
            vector<int> temp;
            for(auto y : x.second){
                temp.insert(temp.end(), y.second.begin(), y.second.end());
            }
            result.push_back(temp);
        }
        return result;
    }
};