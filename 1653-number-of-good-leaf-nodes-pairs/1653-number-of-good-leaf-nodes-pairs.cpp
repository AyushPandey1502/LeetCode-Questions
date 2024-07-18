// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY : O(N)
class Solution {
public:
    void makeGraph(TreeNode* root, TreeNode* prev,unordered_map<TreeNode*, vector<TreeNode*>>& adj,
                   unordered_set<TreeNode*>& leaf) {
        if (root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL){
            leaf.insert(root);
        }
        if(prev != NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        makeGraph(root->left, root, adj, leaf);
        makeGraph(root->right, root, adj, leaf);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leaf;
        makeGraph(root, NULL, adj, leaf);

        int count = 0;
        for(auto &lf : leaf){
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(lf);
            visited.insert(lf);

            for(int level = 0; level <= distance; level++){
                int size = q.size();
                while(size--){
                    TreeNode* current = q.front();
                    q.pop();
                    if(current != lf && leaf.count(current)){
                        count++;
                    }
                    for(auto &ngbr : adj[current]){
                        if(!visited.count(ngbr)){
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};