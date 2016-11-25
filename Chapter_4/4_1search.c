#include <stdio.h>
#define MAXLINE 100

int getlines(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to be searched */
/* find all lines matching pattern */
main()
{
	char line[MAXLINE];
	int found = 0;

	while (getlines(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0){
			printf("%s", line);
			found++;
		}
	return found;
	
}

int getlines(char s[], int lim)
{
	int c, i;

	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;

}
/* a different solution to get a new line. */ 


int strindex(char s[], char t[])
{
	
	int i, j, k;

	for(i = 0; s[i] != '\n'; i++){
		for( j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0') /* how to make sure the match is a complete pattern */
			return i;
	}
	return -1;
	
}