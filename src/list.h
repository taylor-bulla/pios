#include<stdio.h>

struct list_node {
	int data;
	struct list_node *next;
	struct list_node *prev;
};

void list_add(struct list_node *headNode, struct list_node* newNode);
void list_remove(struct list_node* headNode, int data);
