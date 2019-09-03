
#include <stdlib.h>

//Definition for singly-linked list.
 struct ListNode {
     int val;
    struct ListNode *next;
};


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

struct ListNode* mergesplit(struct ListNode** lists, int nStart, int nEnd){
    if (nStart == nEnd) return lists[nStart];

    int mid = nStart + ((nEnd - nStart)>>1);

    struct ListNode* l1 = mergesplit(lists, nStart, mid);
    struct ListNode* l2 = mergesplit(lists, mid+1, nEnd);

    return mergeTwoLists(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    
    if (listsSize == 0) return NULL;

    if (listsSize == 1) return lists[0];

    int mid = listsSize>>1;

    return mergeTwoLists(mergeKLists(lists, mid), mergeKLists(lists+mid, listsSize-mid));
}




struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (!lists || listsSize == 0) return NULL;

    struct ListNode* returnList = mergesplit(lists, 0, listsSize-1);

    return returnList;
}

