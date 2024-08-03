class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* head = root;
        while(true){
            if(head->val < val){
                if(head->right != NULL){
                    head = head->right;
                }else{
                    head->right = new TreeNode(val);
                    break;
                }
            }else{
                if(head->left != NULL){
                    head = head->left;
                }else{
                    head->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};