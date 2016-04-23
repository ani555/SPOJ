#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 20001
queue<int> q;
stack<int> st;
int parent[MAXN];
int value[MAXN];
int t,n;
void bfs(int s)
{
	q.push(s);
	parent[s] = 0;
	while(!q.empty())
	{
		int currmod = q.front()%n;
		q.pop();
//		printf("%d\n",currmod);
		if(currmod==0)
		{
			while(parent[currmod]>0)
			{
				st.push(value[currmod]);
				currmod = parent[currmod];
			}
			st.push(1);
			while(!st.empty())
			{
				printf("%d",st.top());
				st.pop();
			}
			printf("\n");
			while(!q.empty())
			q.pop();
			return;
		}
		int left=(currmod*10)%n;
		if(parent[left]==-1)
		{
			parent[left]=currmod;
			q.push(left);
			value[left] = 0;
		}
		int right = (currmod*10+1)%n;
		if(parent[right]==-1)
		{
			parent[right]=currmod;
			q.push(right);
			value[right] = 1;
		}
			
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(parent,-1,sizeof(int)*n);
		memset(value,0,sizeof(int)*n);
		bfs(1);
	}
}
