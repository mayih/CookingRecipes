#include "family.h"
static family* currentFamily = NULL;
family familyInitialization(char* lastName){
	family f = {.lastName = lastName,
			.listOfMember = malloc(sizeof(member))};	
}

