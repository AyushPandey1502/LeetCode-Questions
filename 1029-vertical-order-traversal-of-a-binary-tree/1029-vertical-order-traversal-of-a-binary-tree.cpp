class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            nodes[x][y].insert(node -> val);
            if(node -> left){
                q.push({node -> left, {x - 1, y + 1}});
            }
            if(node -> right){
                q.push({node -> right, {x + 1, y + 1}});
            }
        } 

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