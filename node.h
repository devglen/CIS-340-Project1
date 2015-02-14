#ifndef __NODE_H__
#define __NODE_H__
//mynode struct
//header for a node struct whitch holds a single integer and two pointers to other nodes
//element of a doubly linked list of type int
struct mynode {
    int value;
    struct mynode *next;
    struct mynode *prev;
};
//declare methods to sort, print, and free the linked list
struct mynode* quicksort(struct mynode *);
void printlist(struct mynode *);
void createPrevLinks(struct mynode *);
void freelist(struct mynode *);
#endif
