#include "recipeIngredient.h"
#include <stdlib.h>
#include <string.h>
recipeIngredient recipeIngredientIntialization(char* name, uint16_t quantity, char* unit){
	char voidUnit[]="";
	size_t lenName = strlen(name);
	size_t lenUnit = strlen(unit);
	recipeIngredient ingredient = {.name = (char *)malloc(lenName * sizeof(char)), 
					.quantity = quantity, .unit = unit == NULL? voidUnit : (char *)malloc(lenUnit * sizeof(char))};
	strncpy(ingredient.name, name, lenName);
	strncpy(ingredient.unit, unit, lenUnit);
	return ingredient;
}
