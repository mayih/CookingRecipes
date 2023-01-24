#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "def.h"

#define SIZE_OF_INT 16

typedef struct node node;
struct node{
	void* data;
	node* next;
	node* prev;
};
typedef struct linkedList{
	node* head;
	INT_TYPE(SIZE_OF_INT) numberOfItems;
	size_t dataSize;
}linkedList;

linkedList* linkedListInitialization(size_t dataSize);

void append(linkedList* list, void* data);
void addItem(linkedList* list, void* data,INT_TYPE(SIZE_OF_INT) index);

node* selectItem(linkedList* list, INT_TYPE(SIZE_OF_INT) index);

void removeItem(linkedList* list, INT_TYPE(SIZE_OF_INT) index);
node popItem(linkedList* list, INT_TYPE(SIZE_OF_INT) index);
void removeLastItem(linkedList* list);
node popLastItem(linkedList* list);

void applyFunctionAtItem
	(linkedList* list, INT_TYPE(SIZE_OF_INT) index, void (*function)(void* object));
void applyFunctionFromItemToEnd
	(linkedList* list, INT_TYPE(SIZE_OF_INT) index, void (*function)(void* object));
		
#endif		
