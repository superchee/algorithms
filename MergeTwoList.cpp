
//Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
#include <stdlib.h>

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1) return l2;
    if (!l2) return l1;

    struct ListNode* phead = NULL, *pIdx = NULL;

    if(l1->val < l2->val){
        phead = l1;
        l1 = l1->next;
    }
    else{
        phead = l2;
        l2 = l2->next;
    }

    pIdx = phead;

    while (l1 && l2){
        if(l1->val < l2->val){
            pIdx->next = l1;
            l1 = l1->next;
        }
        else{
            pIdx->next = l2;
            l2 = l2->next;
        }
        pIdx = pIdx->next;
    }

    if(l1){
        pIdx->next = l1;
    }

    if(l2){
        pIdx->next = l2;
    }

    return phead;
}