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
    int getLength(ListNode* head){
        int len=0;
        while(head){
            head = head->next;
            ++len;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = head;
        int len = getLength(head);
        int step = len-n;
        if(step>0){
          while(step>1){
                head = head->next;
                --step;
            }   
            head->next = head->next->next;   
        }
        else{
            res = res->next;
        }      
        return res;
    }
};


/// slow and fast pointer
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dump;
        for(int i=0; i<n; ++i){
            fast = fast->next;
        }

        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};