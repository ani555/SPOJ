#include<iostream>
#include<map>
#define ll long long int
using namespace std;
map<ll,ll> coins;
map<ll,ll>::iterator x;
ll maxsum(ll n)
{
	ll s1,s2,s3,sum;
	if(n<(n/2+n/3+n/4))						//checks whether for a given n it is less than n/2+n/3+n/4 (this will satisfy for n>3)
	{
		x=coins.find(n/2);					//finds for n/2 in map
		if(x==coins.end())					//in case n/2 is not found find() will return end()	
		{
			s1=maxsum(n/2);					//that means we need to go top to bottom and find the sum for lower sub values
		}
		else
		{
			s1=x->second;					//if found then return that value of sum from the map
		}
		x=coins.find(n/3);					//same as for n/2
		if(x==coins.end())
		{
			s2=maxsum(n/3);
		}
		else
		{
			s2=x->second;
		}
		x=coins.find(n/4);
		if(x==coins.end())
		{
			s3=maxsum(n/4);					//same as for n/4
		}
		else
		{
			s3=x->second;
			
		}
		sum=s1+s2+s3;						//after recursive calling till bottom store the sum corresponding to n in map
		coins.insert(pair<ll,ll>(n,sum));
		return sum;
	}
	else
	return n;								//for n<=3
}
 
int main()
{
	ll c;
	while(scanf("%lld",&c)!=EOF)
	{
	printf("%lld\n",maxsum(c));
	}
	return 0;
} 
