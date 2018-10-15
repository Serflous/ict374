#include "token.h"

int tokenise(char inputLine[], char * token[])
{	
	int i = 0;
	char * tokenArray = strtok(inputLine, " \t\n");
	token[i] = tokenArray;
	for(i = 1; tokenArray != NULL && i < MAX_NUM_TOKENS; i++)
	{
		tokenArray = strtok(NULL, " \t\n");
		token[i] = tokenArray;
	}

	return i-1;
}
