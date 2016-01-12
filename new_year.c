#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BIN_LEN 16

char* dtob(int dec_num)
{
	char *bin_str = (char*)malloc(BIN_LEN + 1);
	char index[] = "01";
	int i = 0;

	do
	{
		bin_str[i++] = index[dec_num % 2];
		dec_num /= 2;
	}while(dec_num);
	bin_str[i] = '\0';

	return bin_str;
}

int main()
{
	char *p_bin_year = NULL;
	int *p_ary_rlt = NULL;
	int n_dec_year;
	int i = 0, j = 0;

	printf("Please input a decimal year:");
	scanf("%d", &n_dec_year);

	if((n_dec_year <= 0))
	{
		printf("ERROR: decimal year input is not legal.\n");
		return 0;
	}

	p_bin_year = dtob(n_dec_year);	// convert decimal year to binary

	// calculate results of binary
	p_ary_rlt = (int*)malloc(BIN_LEN * sizeof(int));
	while(p_bin_year[i] != '\0')
	{
		if(p_bin_year[i] == '1')
		{
			p_ary_rlt[j] = (int)pow(2, i);	
			j++;
		}
		i++;
	}
	j--;	// ignore end char of result array

	// output calculate result of programmer's year
	for(; j>=0; j--)
	{
		if(j != 0)
			printf("%d + ", p_ary_rlt[j]);
		else
			printf("%d", p_ary_rlt[j]);
	}
	printf(" = %d\n", n_dec_year);
	
	free(p_ary_rlt);
	free(p_bin_year);

	return 0;
}
