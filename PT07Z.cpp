//graph,tree diameter,bfs
#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
vector<int> G[MAXN];
int distto[MAXN];
bool visited[MAXN];
queue<int> Q;
int n;
int bfs(int s)
{
	visited[s]=true;
	distto[s]=0;
	Q.push(s);
	while(!Q.empty())
	{
		int v=Q.front(); Q.pop();
		for(int i=0;i<G[v].size();i++)
		{
			int v2=G[v][i];
			if(!visited[v2])
			{
				visited[v2]=true;
				distto[v2]=distto[v]+1;
				Q.push(v2);
			}
		}
	}	
	//calc the max dist node from distto arr
	int node,max=-1;
	for(int i=1;i<=n;i++)
	{
		if(distto[i]>max)
		{
			max=distto[i];
			node=i;			//this node is max dist from the curr node & is a leaf node
		}
	}
	return node;
}

int main()
{
	int a,b,e1,e2;
	ios_base::sync_with_stdio(0);
		cin>>n;
		for(int i=0;i<=n;i++)
		G[i].clear();
		
		for(int i=1;i<=n-1;i++)
		{
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
			memset(visited,false,sizeof(visited));
			memset(distto,0,sizeof(distto));
			int x=1;							//x can be any arbitrary node
			e1=bfs(x);
			memset(visited,false,sizeof(visited));
			memset(distto,0,sizeof(distto));
			e2=bfs(e1);
			int diameter=distto[e2];
			cout<<diameter;	
}
