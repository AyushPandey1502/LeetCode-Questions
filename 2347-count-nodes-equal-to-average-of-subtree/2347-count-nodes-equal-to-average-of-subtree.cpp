class Solution {
public:
    int count = 0;
    pair<int, int> calculateSubtreeValues(TreeNode* currentNode){
        if(!currentNode) return {0, 0};
        auto leftSubtree = calculateSubtreeValues(currentNode->left);
        auto rightSubtree = calculateSubtreeValues(currentNode->right);

        int sumOfValues = leftSubtree.first + rightSubtree.first + currentNode->val;
        int numNodes = leftSubtree.second + rightSubtree.second + 1;

        if(numNodes != 0 && sumOfValues / numNodes == currentNode->val) count++;
        return {sumOfValues, numNodes};
    }
    int averageOfSubtree(TreeNode* root) {
        calculateSubtreeValues(root);
        return count;
    }
};