class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                level.push_back(node -> val);
                for(int i = 0; i < node->children.size(); i++){
                    q.push(node->children[i]);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};