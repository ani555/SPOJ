#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c-(int)'0')
struct Trie_node
{
	int value;
	Trie_node *children[10];
};
class Trie
{
	private:Trie_node* root;int count;
public:
	Trie()
	{
		root= getnode();
		count=0;
	}
	Trie_node *getnode()
	{
		Trie_node *node=new Trie_node;
		if(node)
		{
			node->value=0;
			for(int i=0;i<10;i++)
				node->children[i]=NULL;
		}
		return node;
	}
	int insert(string key)
	{
		Trie_node *pCrawl=root;
		count++;
		int flag=0;
		int level;
		int index;
		int len=key.length();
		for(level=0;level<len;level++)
		{
			index=CHAR_TO_INDEX(key[level]);
			if(!pCrawl->children[index])
			{
				pCrawl->children[index]=getnode();
				flag=1;
			}
			pCrawl=pCrawl->children[index];
		}
		pCrawl->value=count;
		return flag;
	}
	int search(string key)
	{
		Trie_node *pCrawl=root;
		int level;
		int index;
		int len=key.length();
		for(level=0;level<len;level++)
		{
			index=CHAR_TO_INDEX(key[level]);
			if(!pCrawl->children[index])
				return 0;					//return 0 if null link is encountered
			pCrawl=pCrawl->children[index];
		}
		//cout<<level<<endl;
		for(int i=0;i<10;i++)
		{
			
			if(pCrawl->children[i]!=NULL)
			return -1;
		}
		return pCrawl->value;
	}
};
bool comp(const string &p,const string &q)
{
	return p.length()>q.length();
}
int main()
{
	
	string no[10000];
	int ch,k,t,n,i;
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		Trie tr;
		k=0;
		for(i=0;i<n;i++)
		{
			cin>>no[i];
		}
			sort(no,no+n,comp);
		for(i=0;i<n;i++)
		{
			k=tr.insert(no[i]);
			if(k==0)
			{
				cout<<"NO\n";
				break;
			}
		}
		if(k!=0)
		cout<<"YES\n";
	}
	return 0;
}
