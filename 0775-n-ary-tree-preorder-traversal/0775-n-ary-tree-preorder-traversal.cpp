class Solution {
public:
    void preorderTraversal(Node* root, vector<int>& result){
        if(root){
            result.push_back(root->val);
            for(int i = 0; i < root->children.size(); i++){
                preorderTraversal(root->children[i], result);
            }
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }
};