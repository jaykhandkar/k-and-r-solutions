#include <stdio.h>

/* Exercise 1-19. Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses it's input one line
 * at a time. */

#define MAXLINE 1000

void reverse(char s[], int len)
{
	int i, j, temp;

	i = 0;
	j = len - 1;
	while (i <= j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

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
		reverse(line, len-1);
		printf("%s", line);
	}
}
