#include <stdio.h>
#define MAXLINE 1000

/* __getline: read a line into s, return length */

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

/* Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters. */

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = __getline(line, MAXLINE)) > 0)
		if (len > 80)
			printf("%s", line);
}
