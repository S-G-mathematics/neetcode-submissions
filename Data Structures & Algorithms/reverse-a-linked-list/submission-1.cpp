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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;

        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* alpha=head;

        while(alpha!=nullptr){
            alpha=alpha->next;
            temp->next=prev;
            prev=temp;
            temp=alpha;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        if(left==right) return head;

        ListNode* before=nullptr;
        ListNode* temp=head;

        int traverse=left-1;
        while(traverse--){
            before=temp;
            temp=temp->next;
        }

        ListNode* head2=temp;

        int l=right-left;
        while(l--){
            temp=temp->next;
        }

        ListNode* head3=temp->next;
        temp->next=nullptr;

        ListNode* rev=reverseList(head2);

        if(before!=nullptr)
            before->next=rev;
        else
            head=rev;

        head2->next=head3;

        return head;
    }
};