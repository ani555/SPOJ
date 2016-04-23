//warning: dp ahead
//dp+binary search
#include<iostream>
#include<algorithm>
using namespace std;
struct order
{
	int start,duration,price;
	bool operator<(const order &x) const
	{
		return start < x.start;
	}
}o[10001];
int dp[10001],n;
int findpsn(int p)
{
	int s=0,e=n,mid;
	while(e-s>1)
	{
		mid=(s+e)/2;
		if(o[mid].start>=p)
		e=mid;
		else
		s=mid;
	}
	return e;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d %d %d",&o[i].start,&o[i].duration,&o[i].price);
		sort(o,o+n);
		dp[n]=0;
		for(i=n-1;i>=0;i--)
		dp[i]=max(dp[i+1],dp[findpsn(o[i].start+o[i].duration)]+o[i].price);
		printf("%d\n",dp[0]);
	}
	return 0;
}
