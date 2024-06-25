// BRUTE FORCE APPROACH
class Solution {
public:
    void inorderTrav(TreeNode* root, vector<int> &nodes) {
        if (root == NULL) return;
        inorderTrav(root->left, nodes);
        nodes.push_back(root->val);
        inorderTrav(root->right, nodes);
    }

    void formGreaterSumTree(TreeNode* root, unordered_map<int, int> &sumMap) {
        if (root == NULL) return;
        formGreaterSumTree(root->left, sumMap);
        root->val = sumMap[root->val];
        formGreaterSumTree(root->right, sumMap);
    }

    TreeNode* bstToGst(TreeNode* root) {
        vector<int> nodes;
        inorderTrav(root, nodes);
        vector<int> prefixSum(nodes.size(), 0);
        prefixSum[nodes.size() - 1] = nodes.back();
        for (int i = nodes.size() - 2; i >= 0; i--) {
            prefixSum[i] = nodes[i] + prefixSum[i + 1];
        }
        unordered_map<int, int> sumMap;
        for (int i = 0; i < nodes.size(); i++) {
            sumMap[nodes[i]] = prefixSum[i];
        }
        formGreaterSumTree(root, sumMap);
        return root;
    }
};
