#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

typedef struct Link_s
{
    struct Link_s *previousLink;
    int data;
    struct Link_s *followingLink;
} Link;

typedef struct LinkedList_s
{
    int nbLinks;
    Link *first;
} LinkedList;

#endif
