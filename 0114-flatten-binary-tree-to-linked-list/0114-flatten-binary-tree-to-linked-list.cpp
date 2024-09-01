class Solution {
public:
    void makeLinkedList(TreeNode* root, TreeNode*& head) {
        if (root == nullptr) return;
        
        head->right = new TreeNode(root->val);
        head = head->right;
        
        makeLinkedList(root->left, head);
        makeLinkedList(root->right, head);
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        
        TreeNode* dummyHead = new TreeNode();
        TreeNode* head = dummyHead;
        
        makeLinkedList(root, head);
        root->left = nullptr;
        root->right = dummyHead->right->right;
        delete dummyHead; 
    }
};