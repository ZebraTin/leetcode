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
 
//// 先把前半部分链表存下来，然后将两个链表进行顺序对比
class Solution {
public:
    int getLength(ListNode* head)
    {
        int len=0;
        while(head)
        {
            len = len+1;
            head = head->next;
        }
        return len;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        stack<ListNode*> stk;
        int len = getLength(head);
              for (int i=0; i<len/2; i++){
                stk.push(head);
                head = head->next;
        }
        if(len%2){
            head = head->next;
        }
        while(head)
        {
            if (head->val == stk.top()->val)
                stk.pop();
            else
                return false;
            head = head->next;
        }
        return true;
    }
};


//// 先反转前半部分链表，然后将两个链表进行顺序对比
class Solution {
public:
    int getLength(ListNode* head)
    {
        int len=0;
        while(head){
            len = len+1;
            head = head->next;
        }
        return len;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        int len = getLength(head);
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        for(int i=0; i<len/2; i++)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        if(len%2){
           curr = curr->next;
        }

        while(pre)
        {
            if(pre->val != curr->val)
                return false;
            pre = pre->next;
            curr = curr->next;
        }
        return true;
    }
};


//// 先把链表中的值全部存进一个vector中，然后在vector中对比
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        vector<int> values;
        while(head){
            values.emplace_back(head->val);
            head = head->next;
        }
        int len = values.size();
        for(int i=0; i<len/2; i++)
        {
            if (values[i] != values[len-i-1])
                return false;
        }
        return true;
    }
};

/* fast/slow pointer
   快指针比慢指针快一倍，所以快指针到链表末尾时，慢指针到链表的一半
   把前半部分链表反转，然后对比前半部分和后半部分；
   快指针实现了获得链表长度的功能。
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        
        ListNode* fast = head;
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        if(fast)
            curr = curr->next;
            
        while(pre)
        {
            if(pre->val != curr->val)
                return false;
            pre = pre->next;
            curr = curr->next;
        }
        return true;
    }
};
