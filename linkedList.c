#include <stdlib.h>
#include <stdio.h>
#include "listeChainee.h"


LinkedList *initList(void)
{
    LinkedList *list = malloc(sizeof(list));
    Link *link = malloc(sizeof(*link));

    if (list == NULL || link == NULL)
    {
        exit(EXIT_FAILURE);
    }

    link->previousLink = NULL;
    link->data = 0;
    link->followingLink = NULL;

    list->nbLinks = 1;
    list->first = link;

    return list;
}

void displayList(LinkedList *list)
{
    currentLink = link->first;
    while (currentLink-> != NULL)
    {
        printf("%d -> \n", );
    }
}

int main(void) {

    LinkedList *list;
    list = initList();

    return 0;
}
