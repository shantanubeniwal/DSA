/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

// -- solution code --
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode *tail = dummy;

    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        tail->next = newNode;
        tail = newNode;

        newNode->val = (sum % 10);
        carry = (sum / 10);
    }
    return dummy->next;
}
