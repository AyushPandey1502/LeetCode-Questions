class Solution {
public:
    bool checkFlipEquiv(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2) return true;  
        if (!root1 || !root2 || root1->val != root2->val) return false;
        
        bool withoutFlip = checkFlipEquiv(root1->left, root2->left) && checkFlipEquiv(root1->right, root2->right);
        bool withFlip = checkFlipEquiv(root1->left, root2->right) && checkFlipEquiv(root1->right, root2->left);
        return withoutFlip || withFlip;
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return checkFlipEquiv(root1, root2);  
    }
};
