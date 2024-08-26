class Solution {
public:
    vector<int> result;
    void postOrder(Node* root) {
        if (root == NULL)
            return;
        for (Node* child : root->children)
            postOrder(child);
        result.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        postOrder(root);
        return result;
    }
};