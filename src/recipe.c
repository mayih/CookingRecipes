#include "recipe.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static recipe* currentRecipe = NULL;
static unsigned long lenOfAllIngredients = 0;
static unsigned long lenOfAllSteps = 0;

void setCurrentRecipe(recipe* r){
	currentRecipe = r;
}

recipe recipeInitialization(char *title){
	recipe r = {.title = title, 
		.listOfIngredient = 
			linkedListInitialization(sizeof(recipeIngredient)),
		.listOfSteps = linkedListInitialization(sizeof(recipeStep))		};
	return r;
}

void appendIngredient(recipeIngredient ingredient){
	append(currentRecipe->listOfIngredient, &ingredient);
	lenOfAllIngredients += strlen(ingredient.name);
}
void popIngredient(INT_TYPE(SIZE_OF_INT) ingredientIndex){
	if(ingredientIndex > 0 && ingredientIndex <= currentRecipe->listOfIngredient->numberOfItems){
		recipeIngredient ingredient = *(recipeIngredient*) popItem(currentRecipe->listOfIngredient, --ingredientIndex).data;
		lenOfAllIngredients -= strlen(ingredient.name);
	}else fprintf(stderr, "\nout of boundaries\n");

}

void appendStep(recipeStep step){
	append(currentRecipe->listOfSteps, &step);
	lenOfAllSteps += strlen(step.stepString);
}
void popStep(INT_TYPE(SIZE_OF_INT) stepIndex){
	if(stepIndex > 0 && stepIndex <=  currentRecipe->listOfSteps->numberOfItems){
		recipeStep step = *(recipeStep*)popItem(currentRecipe->listOfSteps, --stepIndex).data;
		lenOfAllSteps -= strlen(step.stepString);
	}else fprintf(stderr, "\nout of boundaries\n");
}

char* stepsToString(){
	if(lenOfAllSteps > 0){
		char* stepsString = (char*) malloc(sizeof(char) * lenOfAllSteps * 2);
		memset(stepsString, '\0', lenOfAllSteps * 2);
	
		linkedList* list = currentRecipe->listOfSteps;
		node* n = list->head->next;
	
		if(list == NULL || n == NULL)
			exit(EXIT_FAILURE);
		for(int i = 0; i < list->numberOfItems;i++, n = n->next){	
			recipeStep step = *(recipeStep*) n->data;
		
			char index[100] = "";
			sprintf(index, "%d: ", i + 1);
			strncat(stepsString, index, strlen(index));

			strncat(stepsString, step.stepString, 
				strlen(step.stepString));
			stepsString[strlen(stepsString)] = '\n';
		}	
	
		return stepsString;
	}
	else {static char eofStr[]="\0";return eofStr;}
}
char* ingredientsToString(){
	if(lenOfAllIngredients > 0){
		char* ingredientsString = (char*) malloc(sizeof(char) * lenOfAllIngredients * 2);
		memset(ingredientsString, '\0', lenOfAllIngredients * 2);
	
		linkedList* list = currentRecipe->listOfIngredient;
		node* n = list->head->next;
	
		if(currentRecipe->listOfIngredient == NULL || n == NULL)
			exit(EXIT_FAILURE);
		for(int i = 0; i < list->numberOfItems;i++, n = n->next){	
			recipeIngredient ingredient = *(recipeIngredient*)n->data;
		
			char index[100] = "";
			sprintf(index, "%d: ", i + 1);
			strncat(ingredientsString, index, strlen(index));

			strncat(ingredientsString, ingredient.name, strlen(ingredient.name));

			char quantityWithUnit[100] = "";
			sprintf(quantityWithUnit, " %"PRIu16" %s\n", ingredient.quantity, ingredient.unit);
			strncat(ingredientsString, quantityWithUnit, strlen(quantityWithUnit));	
		}
	
		return ingredientsString;
	}
	else {static char eofStr[]="\0";return eofStr;}
}
char* recipeToString(){

	unsigned long len = (strlen(currentRecipe->title) + lenOfAllIngredients + lenOfAllSteps) * 2;
	char* recipeString = (char*) malloc(sizeof(char) * len); 
	memset(recipeString, '\0', len);
	
	strncpy(recipeString, currentRecipe->title, strlen(currentRecipe->title));
	
	char ingredientsTitle[] = "\n\n\nIngredient:\n\n";
	strncat(recipeString, ingredientsTitle, strlen(ingredientsTitle));	
	char* ingredientsStringList = ingredientsToString();
	strncat(recipeString, ingredientsStringList, strlen(ingredientsStringList));
	char stepsTitle[] = "\n\nSteps:\n\n";
	strncat(recipeString, stepsTitle, strlen(stepsTitle));
	char* stepsStringList = stepsToString();	
	strncat(recipeString, stepsStringList, strlen(stepsStringList));
	return recipeString;	
}
