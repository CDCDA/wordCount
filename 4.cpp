void aa(int n)
{
	int flag=0;
	for(int i=0;i<=n;i++)
	{
		if(strcmp(A[i].str1,str1[i])==0)
		{
			A[i].num++;
			flag=1;
			n++;
		}
		if(flag==0)
		{
			for(int j=0;str[i][j];j++)
			A[n].str1[j]=str1[i][j];
			A[n].num++;
			n++;
		}
	}
	for(int i=0;i<3;i++)
	{
		cout<<A[i].str<<A[i].num<<endl;
	}
}
