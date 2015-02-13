//include header files
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

//quicksort method
//takes one node pointer and recursively sorts in acending order, returning the head node
//this function definition is not what is specified for the assignment - Derek
struct mynode* quicksort(struct mynode *head)
{

	if( head->next == NULL)
	{
		return head;
	}

	struct mynode *current = head;
	int pivot = head->value;
	struct mynode *left = (struct mynode *)malloc(sizeof(struct mynode));
	struct mynode *right = (struct mynode *)malloc(sizeof(struct mynode));
	struct mynode *leftstart = left;
	struct mynode *rightstart = right;
	do
	{
		current = current->next;

		if(current->value < pivot)
		{

			left->next = (struct mynode *)malloc(sizeof(struct mynode));
			left = left->next;
			left->value = current->value;
			
		}
		else
		{
			right->next = (struct mynode *)malloc(sizeof(struct mynode));
			right = right->next;
			right->value = current->value;

		}
	}while(current->next !=NULL);


	if(rightstart != right)
	{
		rightstart = rightstart->next;
		rightstart = quicksort(rightstart);
		printf("right");

		printlist(rightstart);

		head->next =rightstart;
		rightstart->prev = head;
	}

	if(leftstart != left)
	{
		leftstart = leftstart->next;
		leftstart = quicksort(leftstart);
		printf("left");

		printlist(leftstart);

		left->next = head;
		head->prev = left;
		return leftstart;
	}
	else
	{
		return head;
	}


}

//printlist method
//loops through a given linked list and prints the data in each node
void printlist(struct mynode *head)
{
    struct mynode *node = head;
    int i;

    for (i=1; node->next; i++) {
        printf("%3d ", node->value);
        node = node->next;  
        //goes down a line if the number of data poins printed exceeds 20 per line
        if (i % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

//freelist method
//deletes all the nodes of a iven head, effectively erasing the linked list
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
