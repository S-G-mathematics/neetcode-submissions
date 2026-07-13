class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;

        if (head == nullptr) return nullptr;

        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }

        // Remove first node
        if (n == size) {
            return head->next;        // <-- CHANGED
        }

        int k = size - n + 1;

        temp = head;

        int t = k - 2;                // <-- CHANGED

        while (t--) {                 // stop at previous node
            temp = temp->next;
        }

        temp->next = temp->next->next; // <-- CHANGED

        return head;                  // <-- CHANGED
    }
};