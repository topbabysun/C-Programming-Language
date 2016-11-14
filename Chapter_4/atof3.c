#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAXLINE 100

double atof(char s[]);
int getlines(char s[], int max);
main()
{
	double sum, atof(char []);
	char line[MAXLINE];
	int getlines( char line[], int max);

	sum = 0;
	while (getlines(line, MAXLINE) > 0)
		printf("\t%e\n", sum += atof(line));
	return 0;

}


/* atof: convert string s to double */
/* also handle scientific notation, e.g: 123.45e-6 */



double atof(char s[])
{
	double val, power, p;
	int i, j, sign1, sign2, val2;

	for (i = 0; isspace(s[i]); i++)
		;
	sign1 = (s[i] == '-')? -1 : 1;
	if ( s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if(s[i] == 'e' || s[i] == 'E'){
		i++;
		sign2 = (s[i]=='-')? -1:1;  
		if (s[i] == '-' || s[i]== '+')
			i++;
		for ( val2 = 0; isdigit(s[i]) ; i++)
			val2 = val2 * 10 + s[i] - '0';
		if (sign2>0)
			for(j=0;j<val2;j++)
				power /= 10;
		else
			for(j=0;j<val2;j++)
				power *= 10;
	}
	
	
	return sign1 * val/power;
}

int getlines(char s[], int max)
{
	int c, i;

	i = 0;
	while( --max > 0 && ( c = getchar())!= EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
