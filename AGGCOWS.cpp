//problem-AGGCOWS spoj
//includes special binary search
#include<bits/stdc++.h>
using namespace std;
int n,c;
int atleastx(long long a[],long long x)				//funcn to check if the c cows can be placed with least dist x
{
	int cows=1;
	long long lastpos=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]-lastpos>=x)
		{
			cows++;
			if(cows==c)
			return 1;
			lastpos=a[i];
		}
	}
	return 0;
}
long long binarysearch(long long a[])
{
	long long lo=0,hi=a[n-1];						//narrow down search to an optimal soln such that all cows are placed such that lo-1 is the max min dist betn them
	while(lo<hi)
	{
		long long mid=(lo+hi)/2;
		if(atleastx(a,mid)==1)
		lo=mid+1;
		else
		hi=mid;
	}
	return lo-1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&c);
		long long a[n+1];
		for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
		sort(a,a+n);
		printf("%lld\n",binarysearch(a));
	}
	return 0;
}
