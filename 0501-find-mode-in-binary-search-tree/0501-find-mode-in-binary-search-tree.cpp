class Solution {
private:
    void findOccurrence(TreeNode* root, unordered_map<int, int> &map){
        if(root){
            findOccurrence(root->left, map);
            map[root->val]++;
            findOccurrence(root->right, map);
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        unordered_map<int, int> map;
        
        findOccurrence(root, map);
        int maxCount = 0; 
        for (const auto& it : map) {
            maxCount = max(maxCount, it.second);
        }

        for (const auto& it : map) {
            if (it.second == maxCount) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};