#include <stdio.h>

/*Exercise 1-8. Write a program to count blanks, tabs and newlines.*/
int main()
{
	int c, nt, nb, nl;

	nt = nb = nl = 0;
	while((c = getchar()) != EOF) {
		if (c == '\n')
			nl++;
		if (c == '\t')
			nt++;
		if (c == ' ')
			nb++;
	}
	printf("blanks=%d tabs=%d newlines=%d\n", nb, nt, nl);
}
