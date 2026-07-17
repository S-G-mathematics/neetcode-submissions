/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        ListNode* tail = head;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return {prev, tail};
    }

    int size(ListNode* head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int n = size(head);
        int groups = n / k;

        if (groups == 0) return head;

        ListNode* curr = head;
        ListNode* newHead = nullptr;
        ListNode* prevTail = nullptr;

        while (groups--) {

            // Current group starts here
            ListNode* groupHead = curr;

            // Move to last node of this group
            for (int i = 1; i < k; i++)
                curr = curr->next;

            // Save next group's head
            ListNode* nextGroup = curr->next;

            // Cut current group
            curr->next = nullptr;

            // Reverse current group
            auto p = reverse(groupHead);

            if (!newHead)
                newHead = p.first;
            else
                prevTail->next = p.first;

            prevTail = p.second;

            curr = nextGroup;
        }

        // Attach remaining nodes
        prevTail->next = curr;

        return newHead;
    }
};