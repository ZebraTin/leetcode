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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        unordered_set<ListNode*> setA;
        ListNode* temp = headA;
        while (temp != NULL)
        {
            setA.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != NULL)
        {
            if (setA.count(temp))
                return temp;
            temp = temp->next;
        }

        return NULL;
        
    }
};

//// double pointer
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB)
        {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }
        return pA;
        
    }
};


/*两个链表的交点之后，两个链表剩余长度一定相同，
 *因此首先找到两个链表长度较小的一个
 *从这一点开始往后同时遍历两个链表的剩余部分，可以得到交点
 */
class Solution {
public:
    int getLength(ListNode* head)
    {
        int len = 0;
        while (head != NULL)
        {
            len = len+1;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode* pA = headA;
        ListNode* pB = headB;

        int lenA = getLength(pA);
        int lenB = getLength(pB);
        if (lenA > lenB){
            while(lenA-- >lenB)
            {
                pA = pA->next;
            }
            while(pA != NULL)
            {
                if (pA == pB)
                    return pA;
                pA = pA->next;
                pB = pB->next;
            }
        }
        else{
            while(lenB-- >lenA)
            {
                pB = pB->next;
            }
            while(pA != NULL)
            {
                if (pA == pB)
                    return pA;
                pA = pA->next;
                pB = pB->next;
            }
        }
        return NULL;
    }
};