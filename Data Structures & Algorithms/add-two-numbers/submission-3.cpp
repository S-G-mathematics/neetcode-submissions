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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        ListNode* ans=nullptr;
        int carry=0;
        ListNode* a=l1;
        ListNode* b=l2;
        ListNode* head;
        while(a!=nullptr || b!=nullptr){
            if(ans==nullptr){
                int k=a->val+b->val;
                a=a->next;
                b=b->next;
                if(k<10){
                    ans=new ListNode(k);
                    carry=0;
                }
                else{
                    ans=new ListNode(k-10);
                    carry=1;
                }
                head=ans;
                continue;
            }
            if(a!=nullptr && b!=nullptr){
                int k=a->val+b->val+carry;
                a=a->next;
                b=b->next;
                if(k<10){
                    ans->next=new ListNode(k);
                    carry=0;
                }
                else{
                    ans->next=new ListNode(k-10);
                    carry=1;
                }
                ans=ans->next;
                continue;
            }
            if(a==nullptr){
                int k=b->val+carry;
                if(k<10){
                    ans->next=new ListNode(k);
                    carry=0;
                }
                else{
                    ans->next=new ListNode(k-10);
                    carry=1;
                }
                b=b->next;
                ans=ans->next;
                continue;
            }
            if(b==nullptr){
                int k=a->val+carry;
                if(k<10){
                    ans->next=new ListNode(k);
                    carry=0;
                }
                else{
                    ans->next=new ListNode(k-10);
                    carry=1;
                }
                a=a->next;
                ans=ans->next;
                continue;
            }
        }
        if(carry==1){
            ans->next=new ListNode(1);
        }
        return head;
        
    }
};
