// TIME COMPLEXITY : O(N*LOG(N))
// SPACE COMPLEXITY : O(N)
// INORDER TRAVERSAL

class Solution {
public:
    map<int, map<int, multiset<int>>> nodes;

    void inorderTraversal(TreeNode* root, int x, int y){
        if(root == NULL) return;
        inorderTraversal(root -> left, x - 1, y + 1);
        nodes[x][y].insert(root -> val);
        inorderTraversal(root -> right, x + 1, y + 1);
    }
    

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorderTraversal(root, 0, 0);
        vector<vector<int>> result;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};
