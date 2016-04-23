#include<bits/stdc++.h>
using namespace std;
#define a_to_i(k) ((int)k - '0')
#define i_to_a(k) ((int)k + '0')
bool allDigitsNine(char *n)
{
	int len = strlen(n);
	for(int i=0;i<len;i++)
	{
		if(n[i] != '9')
		return 0;
	}
	return 1;
}

bool isPalindrome(char *n)
{
	int len = strlen(n);
	for(int i=0;i<len;i++)
	{
		if(n[i] != n[len-i-1])
		return 0;
	}
	return 1;
}
bool makePalindrome(char *n)
{
	char n1[1000005];
	strcpy(n1,n);
	int len= strlen(n);
	int mid = (len%2!=0)? len/2 : (len-1)/2;
	for(int i=0;i<=mid;i++)
	{
		n[len-i-1] = n[i];
		
	}
	return (strcmp(n,n1)<=0)? 1:0;
}
char* getNextPalin(char *n)
{
	int len = strlen(n);
	if(allDigitsNine(n))
	{
		for(int i=0;i<=len;i++)
	 	{
	 		n[i]='0';	
		}
		n[0]='1';
		n[len] = '1';
		n[len+1] = '\0';
	}
	 
	else if(isPalindrome(n))
	{
	 	int mid = (len%2!=0)? len/2 : (len-1)/2;
	 	int carry=1;
	 	for(int i=mid;i>=0;i--)
	 	{
	 		int x = a_to_i(n[i]) + carry;
	 		n[i] = i_to_a(x%10);
	 		n[len-i-1] = n[i];
	 		carry = (x%10==0 && x!=0)? 1:0;
	 	}
		
	}
	else
	{
		bool less=makePalindrome(n);
		
		if(less)
		{
			int mid = (len%2!=0)? len/2 : (len-1)/2;
	 		int carry=1;
	 		for(int i=mid;i>=0;i--)
	 		{
	 			int x = a_to_i(n[i]) + carry;
	 			n[i] = i_to_a(x%10);
	 			n[len-i-1] = n[i];
	 			carry = (x%10==0 && x!=0)? 1:0;
	 		}
	 	}
	}
	 return n;
}
int main()
{
	int t;
	char n[1000005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",n);
		char *s = getNextPalin(n);
		printf("%s\n",s);
	}
}
