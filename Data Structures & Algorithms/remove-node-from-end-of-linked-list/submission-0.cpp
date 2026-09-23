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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        auto root = head;
        while(root!=nullptr){
            len++;
            root = root->next;
        }
        int x = (len-n+1);
        ListNode* prev = nullptr; ListNode* target = head;
        if(x==1) return head->next;
        for(int i=1;i<x;i++){
            prev = target;
            target = target->next;
        }
        prev->next = target->next;
        return head;
    }
};
