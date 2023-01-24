#ifndef RECIPEINGREDIENT_H
#define RECIPEINGREDIENT_H

#include"../lib/def.h"

typedef struct recipeIngredient{
	char* name;
	uint16_t quantity;
	char* unit; 
}recipeIngredient;

recipeIngredient recipeIngredientIntialization(char* name, uint16_t quantity, char* unit);

#endif
