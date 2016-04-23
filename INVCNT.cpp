//merge sort
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
	ll merge(vector<ll> &a,vector<ll> &aux,ll lo,ll mid,ll hi)
	{
		ll count=0;
		ll i=lo,j=mid+1;
		for(ll k=lo;k<=hi;k++)
		aux[k]=a[k];
		for(ll k=lo;k<=hi;k++)
		{
			if(i>mid)
			a[k]=aux[j++];
			else if(j>hi)
			a[k]=aux[i++];
			else if(aux[i]<=aux[j])
			a[k]=aux[i++];
			else
			{
				a[k]=aux[j++];
				count+=(mid-i+1);
			}
		}
		return count;
	}
	ll msort(vector<ll> &a,vector<ll> &aux,ll lo,ll hi)
	{
		ll inv_count=0;
		if(lo<hi)
		{
			ll mid=(hi+lo)/2;
			inv_count=msort(a,aux,lo,mid);
			inv_count+=msort(a,aux,mid+1,hi);
			inv_count+=merge(a,aux,lo,mid,hi);
		}
		return inv_count;
	}
	ll merge_sort(vector<ll> &a)
	{
		vector<ll> aux(a.size());
		return msort(a,aux,0,a.size()-1);
	}
int main()
{
	ll t,n;
	scanf("%lld",&t);
	while(t--)
	{	
		scanf("%lld",&n);
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&v[i]);
		}
		ll ans=merge_sort(v);
		printf("%lld\n",ans);
	}
	return 0;
}
