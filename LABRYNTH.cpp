//find the diameter of tree
#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pi pair <int,int>
#define I first
#define J second
using namespace std;
char maze[1001][1001];
pi next;
int R,C,best;
void dfs(int i,int j,int d)
{
	if(i<0 || i>=R || j<0 || j>=C || maze[i][j]!='.') return;
	maze[i][j]='v';
	dfs(i+1,j,d+1);
	dfs(i,j+1,d+1);
	dfs(i,j-1,d+1);
	dfs(i-1,j,d+1);
	maze[i][j]='.';
	if(d>best)
	{
		best=d;
		next.I=i;
		next.J=j;
	}
}

int find()
{
	int maxlen=0;
	if(maze[next.I][next.J]!='.') return 0;
	while(1)
	{
		best=0;
		dfs(next.I,next.J,0);
		if(best<=maxlen)
		break;
		else
		maxlen=best;
	}
	return maxlen;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	cin>>C>>R;
	for(int i=0;i<R;i++)
	scanf("%s",maze[i]);
	next.I=next.J=0;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(maze[i][j]=='.')
			{
				next.I=i;
				next.J=j;
				break;
			}
		}
	}
	printf("Maximum rope length is %d.\n", find());
	}
	return 0;
}
