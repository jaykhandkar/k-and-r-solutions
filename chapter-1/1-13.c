#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Exercise 1-13. Write a program to print a histogram of the length of words
 * in it's input. It is easy to draw the histogram with the bars horizontal, a
 * vertical orientation is more challenging.*/

#define WORD_MAX 50 /*arbitrary limit on word length*/

/*print the histogram horizontally or vertically, depending on whether the
 * program is invoked as <argv[0] -h> or <argv[0] -v>*/
int main(int argc, char *argv[])
{
	int nlength[WORD_MAX] = {0};
	int len, state, c, max, vertical;
	double q;

	/*the histogram for the most frequently occuring word length shall be
	 * this long, all other frequencies will be scaled accordingly*/
	char *s = "----------------------------------------------------------";

	if (argc != 2) {
		printf("usage: 1-13 [-h][-v]\n");
		exit(0);
	}
	if (strcmp(argv[1], "-h") == 0)
		vertical = 0;
	else if (strcmp(argv[1], "-v") == 0)
		vertical = 1;
	else{
		printf("usage: 1-13 [-h][-v]\n");
		exit(0);
	}

	len = state = max = 0;
	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t')){
			if (state) {
				if (len < WORD_MAX){
					nlength[len]++;
					if (nlength[len] > max)
						max = nlength[len];
				}
				len = 0;
				state = 0;
			}
			continue;
		}
		else if (state == 0)
			state = 1;
		len++;
	}
	printf("max=%d \n", max);
	for (int i = 0; i < WORD_MAX; i++){
		q = (double) nlength[i] / max;
		if (nlength[i])
			printf("%2d : %.*s\n", i, (int)(q*strlen(s)), s);
	}
}
