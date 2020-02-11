#include <stdio.h>
#include<stdlib.h>
int main(int arg,char *argc[])
{
	int temp = 0,counter_noVol=0;
	char vol_ary[6] = {'a','e','i','o','u'};
	FILE*fin; 
	fin= fopen(argc[1], "r");
	int counter = 0;
	char org_ary[100];
	char newary[100];
	int alp=0;
	while ((org_ary[counter] = fgetc(fin)) != EOF)
	{
		counter++;
	}
	for (int i = 0; i < counter; i++)
	{
		newary[i] = org_ary[i];
	}
	char word_ary[20];
	char ary[100];
	int i = 0, j = 0, cnt = 0, cnt1 = 0;
	int o = 0, cnt2 = 0, cnt3 = 0, p = 0, q = 0;
	int tcounter = 0;


	while (tcounter < counter)
	{

		while (org_ary[i] != ' ')
		{
			if (org_ary[i] == '.')
			{
				break;
			}
			word_ary[cnt3] = org_ary[i];
			cnt3++;
			i++;
		}
		i++;
		while (p < cnt3)
		{
			while (j < 5)
			{
				if (vol_ary[j] == word_ary[p])
				{
					alp++;
					cnt--;
					for (int k = p; k < cnt3; k++)
					{
						word_ary[k] = word_ary[k + 1];
					}
				}
				j++;
			}
			cnt++;
			j = 0;
			p++;
		}
		int l = cnt - 1;
		for (int k = 0; k < (cnt / 2); k++)
		{
			temp = word_ary[l];
			word_ary[l] = word_ary[k];
			word_ary[k] = temp;
			l--;
		}

		for (int r = 0; r < cnt; r++)
		{
			ary[q] = word_ary[r];
			q++;
		}
		ary[q] = ' ';
		q=q+1;

		tcounter = tcounter + cnt3 + 1;
		cnt3 = 0;
		p = 0;
		cnt = 0;
	}


	j = 0;
	counter_noVol = counter;
	counter_noVol = counter_noVol - alp;
	cnt =counter_noVol;
	for (int i = 0; i < counter; i++)
	{
		while (j < 5)
		{
			if (newary[i] == vol_ary[j])
			{
				cnt++;
				cnt1 = cnt;
				for (int k = cnt1 - 1; k >= i; k--)
				{
					ary[k] = ary[k - 1];
				}
				ary[i] = newary[i];
			}
			j++;
		}
		j = 0;
	}
	ary[counter-1] = '.';
	for (int i = 0; i < counter; i++)
	{
		printf("%c", ary[i]);
	}
	system("pause");
}