#include<string.h>
#include<bits/stdc++.h>
using namespace std;
struct word
{
	char str1[100];
	int num;
}A[1000];
int n=10;
char str1[1000][100];
void print(int n,int t)
{
	if(n<t)
	t=n;
	for(int i=0;i<t;i++)
	cout<<"<"<<A[i].str1<<">"<<A[i].num<<endl<<endl;
}
void sort1(int t)
{
	struct word a;
	for(int i=0;i<t;i++)
	{
		for(int j=i+1;j<t;j++)
		{
			if(A[i].num<A[j].num)
			{
				a=A[i];A[i]=A[j];A[j]=a;
			}
		}
	}
	print(n,t);
}
void findsame(int n)
{ 
	int t=0;
	int s[n];
		for(int i=0;i<n;i++)
			s[i]=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]==0)
		{
			for(int j=0;;j++)
			{
				A[t].str1[j]=str1[i][j];
				if(!str1[i][j])
				break;
			}
			A[t].num++;
			s[i]=1;
			for(int m=0;m<n;m++)
			if(s[m]==0&&strcmp(A[t].str1,str1[m])==0)
			{
				A[t].num++;
				s[m]=1;
			}
			t++;
		}
	}
	sort1(t);
}


void countphrase(string str)
{
	int k=0,t=0;
	int count=0;
	for(int i=0;i<str.length()+1;i++)
	{
		if(str[i]<='Z'&&str[i]>='A')
		str[i]=str[i]+32;
	}
	for(int i=0;i<str.length()+1;i++)
	{
		if((str[i]<='z'&&str[i]>='a')&&count<=4)
		count++;
		if(count>4&&str[i]!=' '&&str[i]!='\0')
		count++;
		if(count>=4&&(str[i]==' '||str[i]=='\0'))
		{
			for(int j=i-count+1;j<i;j++)
			{
				str1[k][t]=str[j];
				t++;
			}
			k++;
			t=0;
			count=0;
		}
		if((str[i]==' '||str[i]=='\0')&&count<4)
		count=0;
	}
	findsame(k);
}
int main()
{
	string word;     
	getline(cin,word);
	countphrase(word);
	
	return 0;
}
