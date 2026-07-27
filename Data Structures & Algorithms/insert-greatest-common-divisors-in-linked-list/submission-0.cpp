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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr)return head;
        ListNode* temp=head;
        ListNode* nt=head->next;
        while(nt!=nullptr){
            ListNode* curr=new ListNode(gcd(temp->val,nt->val));
            temp->next=curr;
            curr->next=nt;
            temp=nt;
            nt=nt->next;
        }

        return head;
    }
};