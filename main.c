/*
Project 1
Class:          CIS 340
Authors :       Derek Morey, James Doherty, Sam Turnage
Description:    Accepts a number of integers, creates a doubly linked list, and then
                quickssorts and prints them before and after the sort.
*/

//declare headers for input and node manipulation
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

//main method
int main(void)
{
    struct mynode *list = (struct mynode *)malloc(sizeof(struct mynode)); //head of linked list
    struct mynode *node = list; //used to traverse linked list
    //populate a list of integers using input and the head of the linked list
    //stops if an input value is 0
    int entered = 1;
    while(entered){
        scanf("%d", &(entered));
	//if the number read wasn't 0 then record a new node
	if(entered != 0)
	{
		node->next = (struct mynode *)malloc(sizeof(struct mynode));
		node = node->next;
        	node->value = entered;
	}
    }
    //to avoid NULL pointer errors the above list has to be populated
    //with the first element as nothing, so we move past it
    list = list->next;
    createPrevLinks(list);
    printf("List before sort: \n");
    printlist(list);

    //sort the list
    list = quicksort(list);

    printf("List after sort: \n");
    printlist(list);

    //clears the list of its pointers, avoiding memory leaks
    freelist(list);

    return 0;
}
