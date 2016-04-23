#include <bits/stdc++.h>
using namespace std;
void rev(char *x,char *y)
{
	long int n=strlen(x);
	for(long int i=0;i<n;i++)
	{
		y[n-i-1]=x[i];
	}
	y[n]='\0';
}
long int lcs(char x[],char y[])
{
	long int m=strlen(x);long int n=strlen(y);
	long int k=min(m,n);
	long int l=max(m,n);
	vector< vector<long int> > c(2,vector<long int>(n+1,0));
	long int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			c[1][j]=c[0][j-1]+1;
			else
			{
				c[1][j]=max(c[0][j],c[1][j-1]);
			}
		}
		for(j=1;j<=n;j++)
		c[0][j]=c[1][j];
	}
	return c[1][k];
}

int main()
{
	char x[6101],y[6101];
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
	scanf("%s",x);
	rev(x,y);
	long int l=lcs(x,y);
	printf("%ld\n",strlen(x)-l);
	}
	return 0;
}
