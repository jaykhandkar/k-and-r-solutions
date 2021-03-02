#include <stdio.h>
#include <string.h>

/*Exercise 1-13. Write a program to print a histogram of the length of words
 * in it's input. It is easy to draw the histogram with the bars horizontal, a
 * vertical orientation is more challenging.*/

#define WORD_MAX 50 /*arbitrary limit on word length*/

int main()
{
	int nlength[WORD_MAX] = {0};
	int len, state, c, max;
	double q;

	/*the histogram for the most frequently occuring word length shall be
	 * this long, all other frequencies will be scaled accordingly*/
	char *s = "----------------------------------------------------------";

	len = state = max = 0;
	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t')){
			if (state) {
				nlength[len]++;
				if (nlength[len] > max)
					max = nlength[len];
				len = 0;
				state = 0;
			}
			continue;
		}
		else if (state == 0){
			state = 1;
		}
		len++;
	}
	for (int i = 0; i < WORD_MAX; i++){
		q = (double) nlength[i] / max;
		if (nlength[i])
			printf("%2d : %.*s\n", i, (int)(q*strlen(s)), s);
	}
}
