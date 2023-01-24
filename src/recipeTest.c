#include<stdio.h>
#include<stdlib.h>
#include"recipe.h"
extern char* strdup(const char*);
int main(){
	char title[100];
	
	printf("Enter recipe title :\n");
	scanf("%[^\n]s" ,title);
	recipe r =  recipeInitialization(title);
	setCurrentRecipe(&r);
	
	int choice = -1;
	while(choice){
		printf("Select operation :\n");
		printf("1: Append ingredient\n2: Append step\n3: Remove ingredient\n4: Remove step\n0: Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:

				printf("Enter ingredient name:\n");
				char ingredientName[100];
				scanf("\n%[^\n]s" ,ingredientName);

				printf("Enter quantity:\n");
				uint16_t quantity;
				scanf("%"SCNu16, &quantity);
 

				printf("Enter unit:\n");
				char unit[100];
				scanf("\n%[^\n]s" ,unit);
				
				appendIngredient(recipeIngredientIntialization(ingredientName, quantity, unit));	
				
			break;
			case 2:
				printf("Enter step:\n");
				char step[100];
				scanf("\n%[^\n]s" ,step);

				appendStep(recipeStepIntialization(step));	
			break;
			case 3:
			break;
			case 4:
			break;		
		}
		printf("%s",recipeToString());
		fflush(stdout);
	}	
	
	return 0;
}
