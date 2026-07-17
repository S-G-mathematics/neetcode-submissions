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
ListNode* mim(vector<ListNode*>& lists) {

    int idx = -1;
    int mn = INT_MAX;

    for(int i = 0; i < lists.size(); i++) {

        if(lists[i] == nullptr)
            continue;

        if(lists[i]->val < mn){
            mn = lists[i]->val;
            idx = i;
        }
    }

    if(idx == -1)
        return nullptr;

    ListNode* ans = lists[idx];
    lists[idx] = lists[idx]->next;

    if(lists[idx] == nullptr)
        lists.erase(lists.begin() + idx);

    return ans;
}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr;
        int n=lists.size();
        if(n==0)return nullptr;
        if(n==1)return lists[0];
        head=mim(lists);
        ListNode* temp=head;
        while(lists.size()>0){
            temp->next=mim(lists);
            temp=temp->next;
        }
        return head;
    }
};
