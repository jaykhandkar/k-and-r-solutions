#include <stdio.h>

/*Exercise 1-9. Write a program to copy it's input to it's output, replacing
 * each string of one or more blanks by a single blank.*/

int main()
{
	int c, state;

	state = 0;
	while((c = getchar()) != EOF) {
		if (c != ' ' || !state)
		       putchar(c);
		if (c == ' ')
			state = 1;
		else if(state)
			state = 0;
	}	
}

