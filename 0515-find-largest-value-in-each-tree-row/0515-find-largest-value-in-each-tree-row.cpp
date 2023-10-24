class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>temp;
       vector<vector<int>>ans;
        if(root==NULL) return temp;
        q.push(root);
        while(q.empty()!=true)
        {   vector<int>level;
            int n=q.size();
            for(int i=0;i<n;i++)
            {   TreeNode* t=q.front();q.pop();
                level.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(level);
         int maximum=level[0];
         for(int i=1;i<level.size();i++)
             maximum=max(maximum,level[i]);
         temp.push_back(maximum);
        }
        return temp;
    }
};