#include <stdio.h>
#include <stdlib.h>

#ifndef X
#error X is not defined
#endif

void str_to_tale(int *t, char *str)
{
        int i;

        for(i=0; i<X*X; i++)
                t[i]=(int)strtol(str, &str, 10);

        return;
}

void output_count(unsigned long long int count[X*X][X*X])
{
	int i, j;

	fputs("#elem", stdout);
	for(i=0; i<X*X; i++)
		printf(" %d", i);
	putchar('\n');
	for(i=0; i<X*X; i++){
		printf("%d", i+1);
		for(j=0; j<X*X; j++)
			printf(" %llu", count[i][j]);
		putchar('\n');
	}

	return;
}

int main()
{
	unsigned long long int count[X*X][X*X]={{0}};
	int ms[X*X];
	int i;
	char str[0xffff];

	while(!feof(stdin)){
		fgets(str, 0xffff, stdin);
		str_to_tale(ms, str);
		for(i=0; i<X*X; i++)
			count[i][ms[i]-1]++;
	}

	output_count(count);

	return 0;
}
