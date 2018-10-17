#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#include "token.h"

#define INPUT_BUFFER_SIZE 256

int main(int argc, char ** argv)
{
	int running = 1;
	char input[INPUT_BUFFER_SIZE];
	while(running)
	{
		printf("$ ");
		fgets(input, INPUT_BUFFER_SIZE, stdin);
		size_t length = strlen(input);
		if(input[length - 1] == '\n')
		{
			input[length - 1] = '\0';
		}
		char ** tokens = malloc(MAX_NUM_TOKENS * sizeof(char*));
		int n = tokenise(input, tokens);
		if(n <= 0)
		{
			printf("Please enter valid command.\n");
		}
		else
		{
			if(strcmp(tokens[0], "pwd") == 0)
			{
				printf("Get remote directory\n");
			}
			if(strcmp(tokens[0], "lpwd") == 0)
			{
				printf("Get local directory\n");
			}
			if(strcmp(tokens[0], "dir") == 0)
			{
				printf("Get remote directory listing\n");
			}
			if(strcmp(tokens[0], "ldir") == 0)
			{
				printf("Get local directory listing\n");
			}
			if(strcmp(tokens[0], "cd") == 0)
			{
				printf("Change remote directory\n");
			}
			if(strcmp(tokens[0], "lcd") == 0)
			{
				printf("Change local directory\n");
			}
			if(strcmp(tokens[0], "get") == 0)
			{
				printf("Download a file from the server\n");
			}
			if(strcmp(tokens[0], "put") == 0)
			{
				printf("Upload a file to the server\n");
			}
			if(strcmp(tokens[0], "quit") == 0)
			{
				running = 0;
			}
		}
	}
}
