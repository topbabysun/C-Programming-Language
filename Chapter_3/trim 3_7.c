#include <string.h>
#include <stdio.h>
#define LEN 100

/* atoi: convert s to integer version 2*/
int trim(char s[]);

main()
{
	int i, c, n, m;
	char s[LEN];
	int loop = 1;
	while(loop){
		for (i = 0; i < LEN - 1 && (c = getchar()) != EOF && c != '\n'; i++)
			s[i] = c;
		s[i] = '\0';
		if (c == EOF)
			loop = 0;
		n = strlen(s);
		printf("%s %d\n", s, n);
		trim(s);
		m = strlen(s);
		printf("%s %d\n", s, m);
	}
}

int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n]!= ' '&& s[n] != '\n' && s[n] != '\t')
			break;
	s[n+1] = '\0';
	return n;
}
