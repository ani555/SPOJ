//be careful of the input output format
#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')
struct Trie_node
{
	int value;
	Trie_node *children[26];
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
			for(int i=0;i<26;i++)
				node->children[i]=NULL;
		}
		return node;
	}
	void insert(char *key)
	{
		Trie_node *pCrawl=root;
		count++;
		int level;
		int index;
		int len=strlen(key);
		for(level=0;level<len;level++)
		{
			index=CHAR_TO_INDEX(key[level]);
			if(!pCrawl->children[index])
			{
				pCrawl->children[index]=getnode();
			}
			pCrawl=pCrawl->children[index];
		}
		pCrawl->value=count;
	}
	int search(char *key)
	{
		Trie_node *pCrawl=root;
		int level;
		int index;
		int flag=0;
		int len=strlen(key);
		for(level=0;level<len;level++)
		{
			index=CHAR_TO_INDEX(key[level]);
			if(!pCrawl->children[index])
				return 0;					//return 0 if null link is encountered
			pCrawl=pCrawl->children[index];
		}
		for(int i=0;i<26;i++)
		{
			if(pCrawl->children[i]!=NULL)
			{
			flag=1;
			break;
			}
		}
	//	cout<<pCrawl->value<<" "<<flag<<endl;
		//cout<<level<<endl;
		if(flag==1)
		{
		
		dfs(key,pCrawl,level,level);			//prints all the words that contains the given prefix
		if(flag==1 && pCrawl->value==0)
		return flag;							//if prefix terminates on a intermediate node with value=0
		return pCrawl->value;					//if prefix terminates on a intermediate node with value!=0
		}
		else
		return flag;		//if the prefix occurs in no word print no match
		//cout<<level<<endl;
		
		}
	void dfs(char *str,Trie_node *curr,int pre,int level)
	{
		if(curr->value!=0 && level>pre)
		{
		cout<<str<<"\n";
		}
		for(int i=0;i<26;i++)
		{
			
			if(curr->children[i]!=NULL)
			{
			char ch='a'+i;
			str[level]=ch;
			//cout<<str[level];
			str[level+1]='\0';
			//cout<<str<<level<<endl;
			//cout<<i<<" "<<str<<endl;
			//curr=curr->children[i];
			dfs(str,curr->children[i],pre,level+1);
			}
		}
	}
};
bool comp(const string &p,const string &q)
{
	return p.length()>q.length();
}
int main()
{
	char word[30];
	char prefix[30];
	int ch,k,t,n,i;
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	Trie tr;
	cin>>t;
	while(t--)
	{
		
		cin>>word;
		tr.insert(word);
	}
	cin>>k;
		for(i=1;i<=k;i++)
		{
		cin>>prefix;
		cout<<"Case #"<<i<<":"<<"\n";
		
		if(!tr.search(prefix))
		{
			cout<<"No match.\n";
		}
		}
	return 0;
}
