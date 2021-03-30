#include <stdio.h>

/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and delete entirely blank lines. */

#define MAXLINE 1000

int __getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = __getline(line, MAXLINE)) > 0) {
		if (len > 1) {
			int i = len-2;
			while ((line[i] == ' ' || line[i] == '\t') && i >= 0){
				line[i] = '\n';
				line[i+1] = '\0';
				i--;
			}
			printf("%s", line);
		}
	}
}
