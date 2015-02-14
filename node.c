//include header files
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

//quicksort method
//takes one node pointer and recursively sorts in acending order, returning the head node
struct mynode* quicksort(struct mynode *head)
{
	//return if there is only one element
	if (head->next == NULL) {
		return head;
	}
	
	//declarations for creating a left and right list with less and 
	//greater values than the first in the list, respectively 
	//NOTE: the left and right lists have empty first nodes
	struct mynode *current = head;
	int pivot = head->value;
	struct mynode *leftstart = (struct mynode *)malloc(sizeof(struct mynode));
	struct mynode *rightstart = (struct mynode *)malloc(sizeof(struct mynode));
	struct mynode *left = leftstart;
	struct mynode *right = rightstart;
	
	//parse through the entire list, spliting into left and right lists
	//depending on if they are greater or lesser than the pivot
	while (current->next !=NULL) {
	    current = current->next;
		if (current->value < pivot) {
			left->next = (struct mynode *)malloc(sizeof(struct mynode));
			left = left->next;
			left->value = current->value;
		} else {
			right->next = (struct mynode *)malloc(sizeof(struct mynode));
			right = right->next;
			right->value = current->value;
		}
	}
    
	//fill the empty first node of the right list with the pivot
	rightstart->value = pivot;
	//if there are new values in the left list
	//then append the sorted left list to the sorted right list with the pivot
	if (left != leftstart) {
		left->next = rightstart;
		leftstart = quicksort(leftstart->next);
		createPrevLinks(leftstart);
		return leftstart;
	} else {
	    //if there are no new values in the left list, skip it
	    //just sort the right list with the pivot in it and return it
		rightstart->next  = quicksort(rightstart->next);
		createPrevLinks(rightstart);
		return rightstart;
	}
}

//creatPrevLinks Method
//parses through a list and creates links to previous nodes
//this makes it a doubly linked list
void createPrevLinks(struct mynode *node)
{
	struct mynode *previous = (struct mynode *)malloc(sizeof(struct mynode));	
	while (node->next != NULL) {
		previous = node;
		node = node->next;
		node->prev = previous; 
	}
}

//printlist method
//loops through a given linked list and prints the data in each node
void printlist(struct mynode *head)
{
    struct mynode *node = head;
    int i;
    for (i=1; node->next!=NULL; i++) {
	printf("%3d ",node->value);
        node = node->next;  
        //goes down a line if the number of data poins printed exceeds 20 per line
        if (i % 20 == 0) {
            printf("\n");
        }
    }
    printf("%3d ",node->value);
    printf("\n");
}

//freelist method
//deletes all the nodes of a given head, effectively erasing the linked list
void freelist(struct mynode *head)
{
    struct mynode *temp, *node = head;
    //deletes all nodes after the head
    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
    //deletes the head node
    head = NULL;
}
