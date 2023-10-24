class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) 
			return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root); 
        while (!q.empty())
        {
            int size = q.size(); 
            int maxi=INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* tmp=q.front();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                if(maxi<tmp->val)
                    maxi=tmp->val;
                q.pop();
            }
            res.push_back(maxi);
        }
        return res;
    }
};