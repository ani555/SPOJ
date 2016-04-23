#include<bits/stdc++.h>
using namespace std;
bool comp(unsigned int i,unsigned int j)
{
	return i>j;
}
int main()
{
	unsigned int n,k,i,j,count=0;
	scanf("%u %u",&n,&k);
	unsigned int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%u",&a[i]);
	}
	sort(a,a+n,comp);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]-a[j]==k)
			count++;
			else if(a[i]-a[j]>k)
			break;
		}
	}
	printf("%d\n",count);
	return 0;
}
