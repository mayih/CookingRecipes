#include "recipeStep.h"
#include <stdlib.h>
#include <string.h>

recipeStep recipeStepIntialization(char* stepString){
	size_t lenStep = strlen(stepString);
	recipeStep step = {.stepString = (char*)malloc(lenStep * sizeof(char))};
	
	strncpy(step.stepString, stepString, lenStep);
	return step;
}
