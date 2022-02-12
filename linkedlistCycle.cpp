/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        seen.insert(head);
        while(head != NULL)
        {
            head = head->next;
            if (seen.count(head))
                return true;
            seen.insert(head);
        }
        return false;
    }
};


/**
 slow and fast pointer
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow != fast)
        {
            if (fast == NULL || fast->next == NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;

    }
};