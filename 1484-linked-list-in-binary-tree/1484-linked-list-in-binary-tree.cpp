class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, head, root);
    }
    
    bool dfs(ListNode* head, ListNode* current, TreeNode* root) {
        if (current == nullptr) return true;  
        if (root == nullptr) return false; 
        
        if (current->val == root->val) {
            current = current->next;  
        } else if (head->val == root->val) {
            head = head->next; 
        } else {
            current = head;  
        }
        
        return dfs(head, current, root->left) || dfs(head, current, root->right); 
    }
};