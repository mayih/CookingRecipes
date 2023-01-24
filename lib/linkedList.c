#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

linkedList* linkedListInitialization(size_t dataSize){
	linkedList* list =(linkedList*) malloc(sizeof(linkedList));
	node* newNode = (node*)malloc(sizeof(node));
	
	list->dataSize = dataSize;

	if(list == NULL || newNode == NULL)
		exit(EXIT_FAILURE);
	
	newNode->data = malloc(list->dataSize);
	newNode->next = NULL;
	newNode->prev = newNode;
	list->head = newNode;

	list->numberOfItems = 0;	
	return list;
}

void append(linkedList* list, void* data){
	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = malloc(list->dataSize);

	for(unsigned int i = 0; i < list->dataSize; i++)
		*(uint8_t*)((uint8_t*)(newNode->data) + i) = *(uint8_t*)((uint8_t*)data + i);

	if(list == NULL || newNode == NULL)
		exit(EXIT_FAILURE);
	
	list->head->prev->next = newNode;
	newNode->prev = list->head->prev;
	list->head->prev = newNode;
	newNode->next = list->head;
	
	list->numberOfItems++;
}
void addItem(linkedList* list, void *data ,INT_TYPE(SIZE_OF_INT) index){
	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = malloc(list->dataSize);
	
	for(unsigned int i = 0; i < list->dataSize; i++)
		*(uint8_t*)((uint8_t*)(newNode->data) + i) = *(uint8_t*)((uint8_t*)data + i);

	if(list == NULL || newNode == NULL)
		exit(EXIT_FAILURE);
	
	node* n = selectItem(list, index);
	newNode->next = n;
	newNode->prev = n->prev;
	n->prev->next = newNode;
	n->prev = newNode;

	list->numberOfItems++;
}

node* selectItem(linkedList* list, INT_TYPE(SIZE_OF_INT) index){
	
	node* newNode = list->head->next;

	if(list == NULL || newNode == NULL)
		exit(EXIT_FAILURE);
	
	while(index--)
		newNode = newNode->next;
	
	return newNode;
}

void removeItem(linkedList* list, INT_TYPE(SIZE_OF_INT) index){
	node* nodeToRemove = selectItem(list, index);
	node* prevNode = nodeToRemove->prev;
	node* nextNode = nodeToRemove->next;
	nextNode->prev = prevNode;
	prevNode->next = nextNode;

	free(nodeToRemove);
	list->numberOfItems--;
}
node popItem(linkedList* list, INT_TYPE(SIZE_OF_INT) index){
	node* nodeToRemove = selectItem(list, index);
	node* prevNode = nodeToRemove->prev;
	node* nextNode = nodeToRemove->next;
	nextNode->prev = prevNode;
	prevNode->next = nextNode;
	
	node nodeToReturn = *nodeToRemove;
	free(nodeToRemove);
	list->numberOfItems--;
	
	return nodeToReturn;
}
void removeLastItem(linkedList* list){
	
	node* lastNode = list->head->prev;
	node* newLastNode = lastNode->prev;
	list->head->prev = newLastNode;
	newLastNode->next = list->head;

	free(lastNode);	
	list->numberOfItems--;
}
node popLastItem(linkedList* list){
	
	node* lastNode = list->head->prev;
	node* newLastNode = lastNode->prev;
	list->head->prev = newLastNode;
	newLastNode->next = list->head;

	node nodeToReturn = *lastNode;
	free(lastNode);	
	list->numberOfItems--;
	
	return nodeToReturn;
}

void applyFunctionAtItem
(linkedList* list, INT_TYPE(SIZE_OF_INT) index, void (*function)(void* object)){
	node* newNode = selectItem(list, index);
	if(list == NULL || newNode == NULL)
		exit(EXIT_FAILURE);
	function(newNode);
}
void applyFunctionFromItemToEnd
(linkedList* list, INT_TYPE(SIZE_OF_INT) index, void (*function)(void* object)){
	node* newNode = selectItem(list, index);

	if(list == NULL || newNode == NULL)
		exit(EXIT_FAILURE);
	do
		function(newNode);
	while((newNode = newNode->next) != list->head);		
}
