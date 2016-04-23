#include<iostream>
using namespace std;
int main()
{
	int n;
	int sum,count,share;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
		break;
		int a[n];
		count=0;
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%n==0)
		{
			share=sum/n;
			for(int i=0;i<n;i++)
			{
				if(a[i]>=share)
				{
					count=count+a[i]-share;
				}
			}
			printf("%d\n",count);
		}
		else
		printf("%d\n",-1);
	}
	return 0;
	
}
