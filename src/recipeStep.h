#ifndef RECIPESTEP_H
#define RECIPESTEP_H

#include "../lib/def.h"

typedef struct recipeStep{
	char* stepString;
}recipeStep;

recipeStep recipeStepIntialization(char* stepString);

#endif
