#include <stdio.h>

/* Exercise 1-16. Revise the main routine of the longest-line program so 
 * that it will correctly print the length of arbitrarily long input lines,
 * and as much as possible of the text. */

#define MAXLINE 1000 

/* __getline to avoid conflict with standard library getline */
int __getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line*/
int main()
{
	int len, len_long;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = __getline(line, MAXLINE)) > 0){
		len_long = 0;
		if (line[len-1] == '\n'){
			if (len > max) {
				max = len;
				copy(longest, line);
			}
		}
		else {
			copy(longest, line);
			len_long += len;
			while ((len = __getline(line, MAXLINE)) > 0 &&
					line[len-1] != '\n')
				len_long += len;
			len_long += len;
			if (len_long > max){
				max = len_long;
			}
		}
	}
	if (max > 0){
		printf("%s\n", longest);
		printf("%d\n", max);
	}
	return 0;
}

/*getline: read a line into s, return length. */
int __getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy from to 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
