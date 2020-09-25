#include<stdio.h>

// input = vvce output =4
int slen(char s[])
{
	int i=0,count=0;
	while(s[i]!='\0')
	{
		count=count+1;
		i=i+1;
	}
	return count;
}
int scmpi(char s1[],char s2[],int i)
{
	int k=0,j=0;
	int n1,n2;
	n1=slen(s1);// lenght of string1
	n2=slen(s2);// lenght of string2

	while(k<n2)
	{
		if(s1[k+i]==s2[k])
		{
			j=j+1;
		}
		k=k+1;
	}
if(j==n2)   // both the stings are equal 
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int find(char s1[],char s2[])
{
	int i=0;
	int n1,n2;
	n1=slen(s1);
	n2=slen(s2);
	while(i<=(n1-n2+1))
	{
		if(scmpi(s1,s2,i)==1)
		{
			return i;
		}
		i=i+1;
	}
	return -1;
}
void my_s_r(char t[],char p[],char r[],char d[])
{
	int i=0,j=0,k=0,n1=0,n2=0,n3=0,flag=0;
	n1=slen(t); // lenght of main string
	n2=slen(p); // lenght of pattern 
	n3=slen(r); // lenght of replace string

	while(i<n1-n2+1)
	{
		flag=scmpi(t,p,i);
		if(flag==1)
		{
			// just copy the characters form main stirng reach i
			while(j<i)
			{
				d[k]=t[j];
				k++;
				j++;
			}
			j=0;
while(j<n3)
			{
				d[k]=r[j];
				k++;
				j++;
			}
			i=i+n2;
			j=i;
		}
		else
		{
			i++;
		}
	}
	while(j<n1)
	{
		d[k]=t[j];
		k++;
		j++;
	}
	d[k]='\0';

			
}
void main() 
{
	char STR[20];
	char PAT[20];
	char REP[20];
	char DEST[30];
	int index=0;
	printf("\n enter your main string:");
	scanf("%s",STR);
	printf("\n enter your pattern");
	scanf("%s",PAT);
	printf("\n enter the replacement string:");
	scanf("%s",REP);
	my_s_r(STR,PAT,REP,DEST);
	printf("\n the result is %s",DEST);
	
}
