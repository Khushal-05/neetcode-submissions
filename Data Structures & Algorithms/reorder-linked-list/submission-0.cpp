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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // ListNode* prev = nullptr;

        while(fast!=nullptr && fast->next!=nullptr){
            // prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = nullptr;

        // if(prev!=nullptr){
        //     prev->next = nullptr;
        // }

        ListNode* curr = second;
        ListNode* prevPtr = nullptr;

        while(curr != nullptr){
            ListNode* nextPtr = curr->next;
            curr->next = prevPtr;
            prevPtr = curr;
            curr = nextPtr;
        }

        second = prevPtr;

        while(second != nullptr){ //  L27: slow->next = nullptr; If L27 do not exist and slow->next points to second the check condition changes to (second->next != nullptr)
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
