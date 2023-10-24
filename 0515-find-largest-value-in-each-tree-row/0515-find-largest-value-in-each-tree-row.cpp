class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>temp;
       vector<vector<int>>ans;
        if(root==NULL) return temp;
        q.push(root);
        while(q.empty()!=true)
        {   vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++)
            {   TreeNode* t=q.front();q.pop();
                v.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(v);
         int ma=v[0];
         for(int i=1;i<v.size();i++)
             ma=max(ma,v[i]);
         temp.push_back(ma);
        }
        return temp;
    }
};