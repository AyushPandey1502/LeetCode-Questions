class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while(node){
            if(node->val < p->val && node->val < q->val) node = node->right;
            else if(node->val > p->val && node->val > q->val) node = node->left;
            else return node;
        }
        return nullptr;
    }
};