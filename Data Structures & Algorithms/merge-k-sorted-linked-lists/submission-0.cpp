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
    struct CompareNode{
        bool operator() (ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*> &lists){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

        for(ListNode* listHead : lists){
            if(listHead != nullptr){
                minHeap.push(listHead);
            }
        }

        while(!minHeap.empty()){
            ListNode* minNode = minHeap.top();
            minHeap.pop();

            tail->next = minNode;
            tail = tail->next;

            if(minNode->next != nullptr){
                minHeap.push(minNode->next);
            }
        }
        ListNode* resultHead = dummy.next;
        return resultHead;
    }
};
