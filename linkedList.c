#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

LinkedList *initList(void)
{
    LinkedList *list = malloc(sizeof(list));

    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    list->nbLinks = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

void displayList(LinkedList *list)
{
    Link *currentLink;
    currentLink = list->first;

    while (currentLink != NULL)
    {
        printf("%d -> ", currentLink->data);
        currentLink = currentLink->followingLink;
    }

    printf("\n\n");
}

void displayReverseList(LinkedList *list)
{
    Link *currentLink;
    currentLink = list->last;

    while (currentLink != NULL)
    {
        printf("%d <- ", currentLink->data);
        currentLink = currentLink->previousLink;
    }

    printf("\n\n");
}

void insertEnd(LinkedList *list, int data)
{
    Link *currentLink;
    Link *previousLink;
    Link *newLink;

    newLink = malloc(sizeof(newLink));

    if (newLink == NULL)
    {
        exit(EXIT_FAILURE);
    }

    currentLink = list->first;
    previousLink = currentLink;

    while (currentLink != NULL)
    {
        previousLink = currentLink;
        currentLink = currentLink->followingLink;
    }

    newLink->data = data;
    newLink->followingLink = NULL;

    if (previousLink != NULL)
    {
        newLink->previousLink = previousLink;
        previousLink->followingLink = newLink;
    }
    else
    {
        newLink->previousLink = NULL;
        list->first = newLink;
    }

    list->last = newLink;
    list->nbLinks++;
}

void insertStart(LinkedList *list, int data)
{
    Link *newLink;

    newLink = malloc(sizeof(newLink));

    if (newLink == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newLink->previousLink = NULL;
    newLink->data = data;

    if (list->first == NULL)
    {
        newLink->followingLink = NULL;
    }
    else
    {
        newLink->followingLink = list->first;
        list->first->previousLink = newLink;
    }

    list->first = newLink;

    if (list->last == NULL)
    {
        list->last = newLink;
    }

    list->nbLinks++;
}

int insertInd(LinkedList *list, int data, int ind)
{
    if (ind < 0 || ind > (list->nbLinks)+1)
    {
        printf("\nCan't insert at that index\n");
        return 0;
    }

    if (ind == 0)
    {
        insertStart(list, data);
    }
    else if (ind == (list->nbLinks)+1)
    {
        insertEnd(list, data);
    }
    else
    {
        Link *currentLink;
        Link *newLink;

        newLink = malloc(sizeof(newLink));

        if (newLink == NULL)
        {
            exit(EXIT_FAILURE);
        }

        currentLink = list->first;

        for (int i=1; i<ind; i++)
        {
            currentLink = currentLink->followingLink;
        }

        // Inserting newLink between currentLink and currentLink->followingLink

        if (currentLink == NULL || currentLink->followingLink == NULL)
        {
            printf("Anomaly in the chained list\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            newLink->data = data;
            newLink->followingLink = currentLink->followingLink;
            newLink->previousLink = currentLink;
            currentLink->followingLink->previousLink = newLink;
            currentLink->followingLink = newLink;
            list->nbLinks++;
        }
    }

    return 1;
}

int deleteEnd(LinkedList *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else if (list->nbLinks == 0)
    {
        printf("You can't delete anything from an empty list\n");
        return 0;
    }
    else
    {
        Link *toDelete = list->last;
        list->last->previousLink->followingLink = NULL;
        list->last = list->last->previousLink;
        free(toDelete);
    }

    return 1;
}

int main(void)
{
    LinkedList *list;
    list = initList();

    insertInd(list, 2, 2);
    insertEnd(list, 4);
    insertInd(list, 22, 2);
    insertStart(list, 1);
    insertInd(list, 222, 2);
    insertEnd(list, 5);
    insertStart(list, 0);
    insertEnd(list, 6);

    displayList(list);
    displayReverseList(list);

    deleteEnd(list);

    displayList(list);
    displayReverseList(list);

    return 0;
}
