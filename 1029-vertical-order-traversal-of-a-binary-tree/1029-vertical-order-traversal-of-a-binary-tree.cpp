// TIME COMPLEXITY : O(N*LOG(N))
// SPACE COMPLEXITY : O(N)
// POSTORDER TRAVERSAL

class Solution {
public:
    map<int, map<int, multiset<int>>> nodes;

    void postorderTraversal(TreeNode* root, int x, int y){
        if(root == NULL) return;
        postorderTraversal(root -> left, x - 1, y + 1);
        postorderTraversal(root -> right, x + 1, y + 1);
        nodes[x][y].insert(root -> val);
    }
    

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        postorderTraversal(root, 0, 0);
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
