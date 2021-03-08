#include <stdio.h>

/*Exercise 1-12. Write a program that prints it's input one word per line.*/

int main()
{
	int c, state;

	state = 0;
	while((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t') && !state)
			putchar('\n');
		if (c == ' ' || c == '\t'){
			state = 1;
			continue;
		}
		else if (state)
			state = 0;
		putchar(c);
	}
}
