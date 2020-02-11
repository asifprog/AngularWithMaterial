#include <stdio.h>
#include<stdlib.h>
#include<string.h>
class Helper
{
public:
	static bool Stringcmp(const char*str1, const char*str2)
	{
		int j = 0;
		int cnt = 0;
		int strLen1 = StringLenght(str1);
		int strLen2 = StringLenght(str2);
		if (strLen1 != strLen2)
		{
			return false;
		}
		for (int i = 0; str2[i] != '\0'; i++)
		{
			if (str1[j] == str2[i])
			{
				cnt++;
			}
			else
			{
				return false;
			}
			j++;
		}
		if (cnt == strLen1)
		{
			return true;
		}
		return false;
	}
	static int StringLenght(const char* str)
	{
		int Length = 0;
		for (int i = 0; str[i] != '\0'; i++)
			Length++;
		return Length;
	}
	static char* GetStringFromBuffer(const char* str)
	{
		int strLen = StringLenght(str);
		char* mystr = new char[strLen + 1];
		for (int i = 0; str[i] != '\0'; i++)
			mystr[i] = str[i];
		mystr[strLen] = '\0';
		return mystr;
	}
	static void Stringcopy(char*des, const char*source)
	{
		//des = nullptr;
		int j = 0;
		for (int i = 0; source[i] != '\0'; i++)
		{
			des[j] = source[i];
			j++;
		}
		des[j] = '\0';
	}
};
struct node
{
	char name[20];
	char Roll_No[20];
	char Email[20];
	node *next;
};
class f1
{
	node *first;
	node *last;
public:
	f1()
	{
		first = 0;
		last = 0;
	}
	void readfile(const char filename[])
	{
		int i = 0;
		char buff[100];
		FILE*fin = fopen(filename, "r");


		while (fgets(buff, 99, fin) != NULL)
		{
			//node *temp = new node;
			node *temp = (node*)malloc(sizeof(node));

			Helper::Stringcopy(temp->name, buff);
			fgets(buff, 99, fin);
			Helper::Stringcopy(temp->Roll_No, buff);
			fgets(buff, 99, fin);
			Helper::Stringcopy(temp->Email, buff);
			temp->next = nullptr;

			if (first == 0)
			{
				first = temp;
			}
			else
			{
				node * curr = first;
				while (curr->next != 0)
					curr = curr->next;
				curr->next = temp;
				last = temp;
			}
			i++;
		}
		fclose(fin);
	}
	void insert(char *n, char *r, char *e, const char filename1[])
	{
		//node *temp = new node;
		node*temp = (node*)malloc(sizeof(node));
		temp->next = nullptr;
		Helper::Stringcopy(temp->name, n);

		Helper::Stringcopy(temp->Roll_No, r);
		Helper::Stringcopy(temp->Email, e);
		if (first == 0)
		{
			first = temp;
			last = temp;
		}
		else
		{
			node * curr = first;
			while (curr->next != 0)
				curr = curr->next;
			curr->next = temp;
			last = temp;
		}

		FILE*fout = fopen(filename1, "w");
		node * curr1 = first;
		while (curr1->next != 0)
		{

			fprintf(fout, "%s\t%s\t%s\t\n", curr1->name, curr1->Roll_No, curr1->Email);
			curr1 = curr1->next;
		}
		fprintf(fout, "%s\t%s\t%s\n", curr1->name, curr1->Roll_No, curr1->Email);
		fclose(fout);
	}
	void remove(char*ary, const char filename2[])
	{
		node *curr = first;
		node*prevcurr = nullptr;
		bool  flag = 1;
		while ((Helper::Stringcmp(curr->Roll_No,ary))!=true)
		{
			prevcurr = curr;
			curr = curr->next;
			if (curr->next == nullptr)
			{
				if ((Helper::Stringcmp(curr->Roll_No, ary)) != true)
				{
					flag = 0;
					break;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag==0)
		{
			printf("NO record");
		}
		else
		{
			if (curr == last)
			{
				prevcurr->next = nullptr;
				last = prevcurr;
				free(curr);
			}
			else
			{
				prevcurr->next = curr->next;
				delete curr;
			}


			FILE*fout = fopen(filename2, "w");
			node * curr1 = first;
			while (curr1->next != 0)
			{
				fprintf(fout, "%s\t%s\t%s\t\n", curr1->name, curr1->Roll_No, curr1->Email);
				curr1 = curr1->next;
			}
			fprintf(fout, "%s\t%s\t%s\n", curr1->name, curr1->Roll_No, curr1->Email);

			fclose(fout);
		}

	}
	void print(char *num)
	{
		node *curr = first;
		node*prevcurr = nullptr;
		bool  flag = 1;
		while ((Helper::Stringcmp(curr->Roll_No, num)) != true)
		{
			prevcurr = curr;
			curr = curr->next;
			if (curr->next == nullptr)
			{
				if ((Helper::Stringcmp(curr->Roll_No, num)) != true)
				{
					flag = 0;
					break;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
		{
			printf("NO record");
		}
		else
		{
			printf("name %s", curr->name);
			printf("roll_no %s", curr->Roll_No);
			printf("email  %s", curr->Email);
		}
	}

};
int main(int arg,char*argc[])
{
	f1 f;
	f.readfile(argc[1]);
	int num = 0, num1 = 0, num2 = 0;

	printf("Enter 1 for add   2 for read  3 for delete =");
	//scanf("%d", &num2);
	if (atoi(argc[2]) == 1)
	{
		printf("enter name : ");
		//scanf("%s", &a);
		printf("enter rollno: ");
		//scanf("%s", &b);
		printf("enter email: ");
		//scanf("%s", &c);
		f.insert(argc[3], argc[4],argc[5] , argc[1]);

	}
	if (atoi(argc[2]) == 2)
	{
		printf("Read Record    enter 0 for yourself  1 for frnd1  and respectivly=");
		//scanf("%d", &num1);
		f.print(argc[3]);
	}
	if (atoi(argc[2]) == 3)
	{

		printf("delete Record    enter 0 for yourself  1 for frnd1  and respectivly=");
		//scanf("%d", &num);
		f.remove(argc[2], argc[1]);
	}
	system("pause");
}