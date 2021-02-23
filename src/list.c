#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void list_add(struct list_node *headNode, struct list_node *newNode) {

	struct list_node* prev;
	struct list_node* temp =headNode;

	while (temp->next) {
		prev = temp;
		temp = temp->next;
	}
	temp->prev = prev;
	temp->next = newNode;
}

void list_remove(struct list_node *headNode, int data) {

	struct list_node* head = headNode;
	if (head == NULL) {
		return;
	}

	if (head->data == data) {
		headNode = head->next;
		return;
	}

	while(head->next) {
		if (data == head->data) {
			head->prev->next = head->next;
			head = head->next;
			continue;
		}
		head = head->next;
	}
}
