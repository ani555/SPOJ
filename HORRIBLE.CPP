#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int T,n,q,typ,l,r,v;
ll t[3*MAXN],lazy[3*MAXN];
void update(int pos,int lo,int hi,int qlo,int qhi,ll v)
{
	if(lo>hi) return;
	if(lazy[pos]!=0)
	{
		t[pos]+=lazy[pos]*(hi-lo+1);
		if(lo!=hi)
		{
			lazy[2*pos]+=lazy[pos];
			lazy[2*pos+1]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	//no overlap
	if(lo>qhi || qlo>hi) return;

	//total overlap
	if(lo>=qlo && hi<=qhi) 
	{
		t[pos]+=v*(hi-lo+1);
		if(lo!=hi)
		{
			lazy[2*pos]+=v;
			lazy[2*pos+1]+=v;
		}
		return;
	}
	//partial overlap
	int mid=(lo+hi)/2;
	update(2*pos,lo,mid,qlo,qhi,v);
	update(2*pos+1,mid+1,hi,qlo,qhi,v);
	t[pos]=t[2*pos]+t[2*pos+1];
}
ll query(int pos,int lo,int hi,int qlo,int qhi)
{
	if(lazy[pos]!=0)
	{
		t[pos]+=lazy[pos]*(hi-lo+1);
		if(lo!=hi)
		{
			lazy[2*pos]+=lazy[pos];
			lazy[2*pos+1]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	//no overlap;
	if(lo>hi || lo>qhi || qlo>hi) return 0;
	//total overlap
	if(lo>=qlo && hi<=qhi)
	{
//		cout<<"------"<<lo<<" "<<hi<<" "<<t[pos]<<endl;
		return t[pos];
	}
//	cout<<"------"<<lo<<" "<<hi<<" "<<t[pos]<<endl;
	//partial overlap
	int mid=(lo+hi)/2;
	return query(2*pos,lo,mid,qlo,qhi) + query(2*pos+1,mid+1,hi,qlo,qhi);

}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&q);
		for(int i=0;i<=3*MAXN+1;i++)
		{
			lazy[i]=0;
			t[i]=0;
		}
		while(q--)
		{
			scanf("%d",&typ);
			if(typ==1)
			{
				scanf("%d %d",&l,&r);
				
				printf("%lld\n",query(1,1,n,l,r));
			}
			if(typ==0)
			{
				scanf("%d %d %d",&l,&r,&v);
				update(1,1,n,l,r,v);
			}
		}
	}
}
