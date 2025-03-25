class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while(head){
            vals.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = vals.size() - 1;
        while(left <= right && vals[left] == vals[right]){
            left++;
            right--;
        }
        return left >= right;
    }
};