//dp-knapsack
#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int n,int W)
{
	int K[n+1][W+1];int fee=W;
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i==0||w==0)
			K[i][w]=0;
			else if(wt[i-1]<=w)
			{
				K[i][w]=max(K[i-1][w-wt[i-1]]+val[i-1],K[i-1][w]);
			}
			else
			K[i][w]=K[i-1][w];
		}
	}
	while(K[n][fee]==K[n][fee-1])
	{
		fee--;
	}
	printf("%d ",fee);
	return K[n][W];
}
int main()
{
	int n,W;
	while(1)
	{
		scanf("%d %d",&W,&n);
		if(W==0 && n==0)
		break;
		int val[n],wt[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&wt[i],&val[i]);
		}
		int res=knapsack(wt,val,n,W);
		printf("%d\n",res);
	}
}
