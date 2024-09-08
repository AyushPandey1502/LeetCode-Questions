class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        ListNode* current = head;
        
        int len = 0;
        while (current) {
            len++;
            current = current->next;
        }

        int partSize = len / k;
        int extraNodes = len % k;

        current = head;
        for (int i = 0; i < k && current; i++) {
            result[i] = current;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;
            
            for (int j = 1; j < currentPartSize; j++) {
                if (current) {
                    current = current->next;
                }
            }

            if (current) {
                ListNode* nextPart = current->next;
                current->next = nullptr;
                current = nextPart;
            }
        }
        return result;
    }
};
