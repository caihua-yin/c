#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* list)
{
    struct ListNode *tmp = list;
    while (tmp)
    {
        printf("%d", tmp->val);
        if (tmp->next)
            printf("->");
        tmp = tmp->next;
    }
    if (list)
        printf("\n");
}

void destroyList(struct ListNode* list)
{
    struct ListNode *tmp = list;
    while(tmp)
    {
        list = list->next;
        free(tmp);
        tmp = list;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *result = NULL, *p = NULL;
    int tmp = 0, carry = 0;
    while (l1 || l2)
    {
        if (p != NULL)
        {
            p->next = malloc(sizeof(struct ListNode));
            p = p->next;
        }
        else
            result = p = malloc(sizeof(struct ListNode));

        if (l1 && l2)
            tmp = l1->val + l2->val + carry;
        else if (l1)
            tmp = l1->val + carry;
        else
            tmp = l2->val + carry;

        if (tmp >= 10)
        {
            p->val = tmp % 10;
            carry = 1;
        }
        else
        {
            p->val = tmp;
            carry = 0;
        }

        if (l1)
            l1 = l1->next;

        if (l2)
            l2 = l2->next;
    }

    return result;
}

int main()
{
    struct ListNode *list1, *list2, *resultList;

    // Initialize list1 as 2->4->3
    list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val = 2;

    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 4;

    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 3;
    list1->next->next->next = NULL;

    printf("list1: ");
    printList(list1);

    // Initalize list2 as 5->6->4
    list2 = malloc(sizeof(struct ListNode));
    list2->val = 5;

    list2->next = malloc(sizeof(struct ListNode));
    list2->next->val = 6;

    list2->next->next = malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    printf("list2: ");
    printList(list2);

    resultList = addTwoNumbers(list1, list2);
    printf("result: ");
    printList(resultList);

    destroyList(resultList);
    destroyList(list1);
    destroyList(list2);

    return 0;
}
