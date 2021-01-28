#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;
map<string,int> M;
int in[100];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<2*i;i++)
		{
			in[i]=0;
		}
		M.clear();
		int idx=0;
		for(i=0;i<n;i++)
		{
			char str1[50],str2[50];
			scanf("%s%s",str1,str2);
			string a=str1;
			string b=str2;
			int idxa,idxb;
			if(M.find(a)==M.end())
			{
				idxa=idx;
				M[a]=idx++;
			}
			else idxa=M[a];
			if(M.find(b)==M.end())
			{
				idxb=idx;
				M[b]=idx++;
			}
			else idxb=M[b];
			in[idxb]++;
			int cnt=0;
		}
		int cnt=0;
		for(i=0;i<n;i++)
		{
			if(in[i]==0)cnt++;
		}
		puts(cnt==1?"YES":"NO");
	}
	return 0;
}