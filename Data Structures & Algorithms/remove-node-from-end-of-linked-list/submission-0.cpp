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
        ListNode* temp = head;
        int sz = 0;
        while(temp != nullptr){
            sz++;
            temp = temp->next;
        }

        int val = sz - n;
        cout<<"Size of LL: "<<sz<<", "<<"Value: "<<val<<endl;

        temp = head;
        ListNode* prev = temp;
        int idx = 0;

        if(val == 0){
            head = temp->next;
        }
        else{
            while(idx != val && temp != nullptr){
                prev = temp;
                idx++;
                temp = temp->next;
            }
            prev->next = temp->next;
            temp->next = nullptr;
        }

        return head;
    }
};
