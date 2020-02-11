#include <stdio.h>
#include<stdlib.h>
int main(int arg,char *argc[])
{
	char var_ary[10] = {'0','1','2','3','4','5','6','7','8','9'};
	FILE*fin;
	fin=fopen(argc[1], "r");
	char org_ary[100];
	int counter = 0;
	while ((org_ary[counter] = fgetc(fin)) != EOF)
	{
		counter++;
	}
	int var_counter=0;
	int i = 0, j = 0;
	while (i<counter)
	{
		while (j < 10)
		{
			if (var_ary[j] == org_ary[i])
			{
				var_counter++;
			}
			j++;;
		}
		j = 0;
		i++;
	}
	printf("Total are %d\n", var_counter);
	system("pause");
}