
#include <stdlib.h>

/**Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
**/
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *l3 = NULL, *l1current = NULL, *l2current = NULL, *l3current = NULL, *temp1 = NULL;
	int nSum = 0, nCarry = 0;

	l1current = l1;
	l2current = l2;
	l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next = NULL;
	l3current = l3;
	nSum = l1current->val + l2current->val;
	if (nSum < 10) {
		l3current->val = nSum;
		nCarry = 0;
	}
	else {
		l3current->val = nSum % 10;
		nCarry = 1;
	}

	l1current = l1current->next;
	l2current = l2current->next;
	
	while (l1current != NULL || l2current != NULL) {
		if (l1current == NULL)
		{
			while (l2current != NULL) {
				temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
                temp1->next = NULL;
				nSum = l2current->val + nCarry;
				if (nSum < 10) {
					temp1->val = nSum;
					nCarry = 0;
				}
				else {
					temp1->val = nSum % 10;
					nCarry = 1;
				}
				l3current->next = temp1;
				l3current = temp1;
				l2current = l2current->next;
			}
		}
		else if(l2current == NULL) {
			while (l1current != NULL) {
				temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
                temp1->next = NULL;
				nSum = l1current->val + nCarry;
				if (nSum < 10) {
					temp1->val = nSum;
					nCarry = 0;
				}
				else {
					temp1->val = nSum % 10;
					nCarry = 1;
				}
				l3current->next = temp1;
				l3current = temp1;
				l1current = l1current->next;
			}
		}
		else {
			temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp1->next = NULL;
			nSum = l1current->val + l2current->val + nCarry;
			if (nSum < 10) {
				temp1->val = nSum;
				nCarry = 0;
			}
			else {
				temp1->val = nSum % 10;
				nCarry = 1;
			}
			l3current->next = temp1;
			l3current = temp1;
			l2current = l2current->next;
			l1current = l1current->next;
		}
	}

	if (nCarry != 0) {
		temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp1->val = nCarry;
		temp1->next = NULL;
		l3current->next = temp1;
		l3current = temp1;
	}

	return l3;

}