#include <stdio.h>
#include <string.h>

/* Write a program to print a histogram of the frequencies of different characters
 * in it's input.*/

int main()
{
	int nchar[128] = {0}, c;
	int max = 0;
	double q;

	char *s = "------------------------------------------------------";

	max = 0;
	while((c = getchar()) != EOF) {
		if (c >= 0 && c <= 127){
			++nchar[c];
			if (nchar[c] > max)
				max = nchar[c];
		}
	}

	for (int i = 0; i < 128; i++){
		if (nchar[i]) {
			q = (double) nchar[i] / max;
			if (i != '\n' && i != ' ' && i != '\t')
				printf("%c: %.*s\n", i, (int)(q * strlen(s)), s);
			else if ( i == '\n')
				printf("\\n: %.*s\n", (int)(q * strlen(s)), s);
			else if ( i == '\t')
				printf("\\t: %.*s\n", (int)(q * strlen(s)), s);
			else if ( i == ' ')
				printf("_: %.*s\n", (int)(q * strlen(s)), s);
		}
	}
}
