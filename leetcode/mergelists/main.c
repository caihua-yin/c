#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *result = NULL, *tmp = NULL;
    while (list1 && list2)
    {
        if (list1->val >= list2->val)
        {
            if (tmp != NULL)
            {
                tmp->next = list2;
                tmp = tmp->next;
            }
            else
            {
                tmp = result = list2;
            }
            list2 = list2->next;

        }
        else
        {
            if (tmp != NULL)
            {
                tmp->next = list1;
                tmp = tmp->next;
            }
            else
            {
                tmp = result = list1;
            }
            list1 = list1->next;
        }
    }

    if (list1)
        if (tmp != NULL)
			tmp->next = list1;
		else
			tmp = result = list1;
    if (list2)
		if (tmp != NULL)
			tmp->next = list2;
		else
			tmp = result = list2;

    return result;
}

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

int main()
{
    struct ListNode *list1, *list2, *resultList;

    // Initialize list1 as 1->2->4
    list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val = 1;

    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 2;

    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
	list1->next->next->next = NULL;

    printf("list1: ");
    printList(list1);

    // Initalize list2 as 1->3->4
    list2 = malloc(sizeof(struct ListNode));
    list2->val = 1;

    list2->next = malloc(sizeof(struct ListNode));
    list2->next->val = 3;

    list2->next->next = malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
	list2->next->next->next = NULL;

    printf("list2: ");
    printList(list2);

    // Merge list1 and list2
    resultList = mergeTwoLists(list1, list2);

    printf("result: ");
    printList(resultList);

    // Destroy result, which will also destroy list1 and list2
    destroyList(resultList);

    return 0;
}
