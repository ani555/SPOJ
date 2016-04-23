#include<bits/stdc++.h>
#define MAXN 300005
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define ppi pair<pair<int,int>,int>
#define vpi vector<pi>
#define vpii vector<ppi>
using namespace std;
int a[MAXN],res[MAXN],cnt[1000001];
vpii lri;
int t,n,m,l,r,BLOCK=550,ans;
bool cmp(ppi x,ppi y)
{
	if(x.first.first/BLOCK!=y.first.first/BLOCK) return x.first.first/BLOCK<y.first.first/BLOCK;
	return x.first.second<y.first.second; 
}
void add(int pos)
{
	cnt[a[pos]]++;
	if(cnt[a[pos]]==1) ans++;
}
void remove(int pos)
{
	cnt[a[pos]]--;
	if(cnt[a[pos]]==0) ans--;
}
int main()
{
	scanf("%d",&n);
//	BLOCK=sqrt(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d",&l,&r);
		l--;r--;
		lri.push_back(make_pair(make_pair(l,r),i));
	}

	sort(lri.begin(),lri.end(),cmp);
	int currL=0,currR=0;
	ans=0;
	for (int i = 0; i < m; ++i)
	{
		int L=lri[i].first.first, R=lri[i].first.second;
		
		while(currL<L)
		{
			remove(currL);
			currL++;
		}
		while(currL>L)
		{
			add(currL-1);
			currL--;
		}
		while(currR<=R)
		{
			add(currR);
			currR++;
		}
		while(currR>R+1)
		{
			remove(currR-1);
			currR--; 
		}
		res[lri[i].second]=ans;
	}
	for (int i = 0; i < m; ++i)
	{
		printf("%d\n",res[i]);
	}
}
