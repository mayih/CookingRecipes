#ifndef RECIPE_H
#define RECIPE_H

#include "recipeIngredient.h"
#include "recipeStep.h"
#include "../lib/linkedList.h"


typedef struct recipe{
	char* title;
	linkedList* listOfIngredient;	
	linkedList* listOfSteps;	
}recipe;

void setCurrentRecipe(recipe* currentRecipe);

recipe recipeInitialization(char *title);

void appendIngredient(recipeIngredient ingredient);
void popIngredient(INT_TYPE(SIZE_OF_INT) ingredientIndex);

void appendStep(recipeStep step);
void popStep(INT_TYPE(SIZE_OF_INT) stepIndex);

char* stepsToString();
char* ingredientsToString();
char* recipeToString();

#endif
