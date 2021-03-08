#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Exercise 1-13. Write a program to print a histogram of the length of words
 * in it's input. It is easy to draw the histogram with the bars horizontal, a
 * vertical orientation is more challenging.*/

#define WORD_MAX 50 /*arbitrary limit on word length*/

int main(int argc, char *argv[])
{
	int nlength[WORD_MAX] = {0};
	int len, state, c, max;
	double q;
	int num = 0;

	/* for the horizontal orientation, the histogram for the most frequently 
	 * occuring word length shall be this long, all other frequencies are
	 * scaled accordingly.*/
	char *s = "----------------------------------------------------------";

	len = state = max = 0;
	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t')){
			if (state) {
				if (len < WORD_MAX){
					if (!nlength[len])
						num++;
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

	printf("horizontal orientation:\n");
	for (int i = 0; i < WORD_MAX; i++){
		q = (double) nlength[i] / max;
		if (nlength[i])
			printf("%2d : %.*s\n", i, (int)(q*strlen(s)), s);
	}

	printf("vertical orientation:\n");
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < WORD_MAX; j++) {
			if (nlength[j] >= (max - i) && nlength[j])
				printf("%4c", '*');
			else if (nlength[j])
				printf("%4c", ' ');
		}
		printf("\n");
	}

	for (int i = 0; i < WORD_MAX; i++)
		if (nlength[i])
			printf("%4d", i);
	printf("\n");

}
