#include <stdio.h>
#include "additionalFunctions.h"

// reads the input until it is a new line.
void flush_n()
{
	char c;
	do
	{
		scanf("%c",&c);
	}while(c != '\n');
}

// a function that helps in reading the input unitl end of the line.
void getString( char* str, int length)
{
	int x;
	for (int i=0; i<length; i++)
	{
		x = scanf("%c", &str[i]);

		// checks if it is newline or scanf is wrong.
		if ( (i>1) && (str[i] == '\n' || str[i] == '\r' || x != 1))
		{
			//if it reaches a new line.
			str[i] = '\0';
			break;
		}
	}
}
