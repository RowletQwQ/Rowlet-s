#include <iostream>
#include<stdio.h>
#include<ctype.h>
#include<cstring>

using namespace std;


char Word1[82];
char Word2[82];

int LengthOfWord1 = 0;
int LengthOfWord2 = 0;
int main()
{
	char t;
	while ((t=getchar()) != ' ')
	{
		t=tolower(t);
		if(t<='z'&&t>='a')Word1[LengthOfWord1++]=t;
	}
	while ((t=getchar()) != EOF)
	{
		t=tolower(t);
		if(t<='z'&&t>='a')Word2[LengthOfWord2++]=t;
	}
	
	for(int i=0;i<LengthOfWord1;i++)
	{
		for(int j=i+1;j<LengthOfWord1;j++)
		{
			if(Word1[i]>Word1[j])
			{
				swap(Word1[i],Word1[j]);
			}
		}
	}
	for(int i=0;i<LengthOfWord2;i++)
	{
		for(int j=i+1;j<LengthOfWord2;j++)
		{
			if(Word2[i]>Word2[j])
			{
				swap(Word2[i],Word2[j]);
			}
		}
	}

	bool flag=strcmp(Word1,Word2);
	if (flag==0)
		cout << "yes";
	else
		cout << "no";

	return 0;
}
