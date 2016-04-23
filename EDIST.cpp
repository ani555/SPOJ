#include<bits/stdc++.h>
using namespace std;
char X[2001],Y[2001];
int T[2001][2001];
int edist(char *X,char *Y)
{
	int cost=0;
	int upcell,cornercell,leftcell;
	int m=strlen(X)+1;
	int n=strlen(Y)+1;
	//int T[m][n];
	for(int i=0;i<m;i++)
	{
		T[i][0]=i;
	}
	for(int j=0;j<n;j++)
	{
		T[0][j]=j;
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			upcell=T[i-1][j];
			upcell+=1;
			leftcell=T[i][j-1];
			leftcell+=1;
			cornercell=T[i-1][j-1];
			cornercell+=(X[i-1]!=Y[j-1]);
			T[i][j]=min(min(upcell,leftcell),cornercell);
		}
	}
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<T[i][j]<<"	";
		}
		cout<<endl;
	}*/
	cost=T[m-1][n-1];
	return cost;
}
int main()
{
	int t,result;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",X);
		scanf("%s",Y);
		result=edist(X,Y);
		printf("%d\n",result);
	}
	return 0;
}
