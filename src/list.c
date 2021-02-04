#include<stdio.h>
#include "list.h"

void list_add(struct list_node *headNode, struct list_node *newNode) {

	struct list_node *nodeAddress =headNode;

	while ((nodeAddress->next) != NULL) {
		nodeAddress = nodeAddress->next;
	}
	nodeAddress->next = newNode;
}

void list_remove(struct list_node *headNode, struct list_node *prevNode) {

	while (headNode != NULL) {

	struct list_node *nodeAddress =prevNode;

	if (((headNode->next) = nodeAddress)) {

		struct list_node *keyNode = headNode->next->next;

		headNode->next = keyNode;

		}
		headNode = headNode->next;
	}
}


void main() {

}
