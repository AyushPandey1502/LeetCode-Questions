class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int count = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                temp.push_back(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            if(!is_sorted(temp.begin(), temp.end())){
                for(int i = 0; i < size; i++){
                    int k = i;
                    for(int j = i + 1; j < size; j++){
                        if(temp[j] < temp[k]){
                            k = j;
                        }
                    }
                    if(k != i){
                        swap(temp[i], temp[k]);
                        count++;
                    }
                }
            }
        }
        return count;
    }
};