//dp-knapsack
#include<bits/stdc++.h>
using namespace std;
int K[3][2000001]={0};
int knapsack(int wt[],int val[],int n,int W)
{
	for(int i=0;i<=n;i++)
	{
	int j=(i%2==0) ? 1:0;
		int k=!j;
		for(int w=0;w<=W;w++)
		{
			if(wt[i-1]<=w)
			{
				K[j][w]=max(K[k][w-wt[i-1]]+val[i-1],K[k][w]);
			}
			else
			K[j][w]=K[k][w];
		}
	}
	if(n&1)
	return K[0][W];
	else
	return K[1][W];
}
int main()
{
		int n;
		int W;
		scanf("%lld %ld",&W,&n);
		int val[n],wt[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&val[i],&wt[i]);
		}
		int res=knapsack(wt,val,n,W);
		printf("%d\n",res);
}
