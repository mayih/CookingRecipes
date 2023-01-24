#include "linkedList.h"
#include <stdio.h>
void f(void* object){
	printf("%s=>",(char*)(((node*)object)->data));	
}
int main(){
	linkedList* list = linkedListInitialization(sizeof(int));
	char a[] = "Ao";
	append(list, a);
	
	a[0]++;	
	append(list, a);
	a[0]++;	
	append(list, a);
	a[0]++;	
	append(list, a);
	a[0]++;	
	append(list, a);
/*	for(int i = 0; i < list->numberOfItems;i++){	
		char *data = selectItem(list,i)->data;
		printf("%s=>", data);
	}*/
	applyFunctionFromItemToEnd(list, 0, f);
		
}
