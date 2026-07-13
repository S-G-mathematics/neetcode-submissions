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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        ListNode* a=list1;
        ListNode* b=list2;
        ListNode* ans=nullptr;
        ListNode* head=ans;
        while(a!=nullptr && b!=nullptr){
            if(ans==nullptr){
                if(a->val<=b->val){
                    ans=a;
                    head=ans;
                    a=a->next;
                }else{
                    ans=b;
                    head=ans;
                    b=b->next;
                }
            }
            if(a!=nullptr && b!=nullptr){
                if(a->val<=b->val){
                    ans->next=a;
                    ans=ans->next;
                    a=a->next;
                }else{
                    ans->next=b;
                    ans=ans->next;
                    b=b->next;
                }
            }
            if(a==nullptr){
                ans->next=b;
                ans=ans->next;
                b=b->next;
            }
            if(b==nullptr){
                ans->next=a;
                ans=ans->next;
                a=a->next;
            }
        }
        return head;
    }
};
