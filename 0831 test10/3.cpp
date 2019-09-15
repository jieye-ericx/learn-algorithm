/*#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;
#define N 10
struct node{
    int we;
    int sp;
    int num;
}mice[N];

bool cmp(node n1,node n2){
    if(n1.we!=n2.we){
        return n1.we<n2.we;
    }else return n1.sp<n2.sp;
}

int i,j,n,Max,Mmax;
int dp[N];
int main(){
    i=0;
    Max=0;Mmax=0;
    for(j=0;j<N;j++){
        dp[j]=1;
    }
    //
    while(scanf("%d%d",&mice[i].we,&mice[i].sp)!=EOF&&mice[i].we){
        mice[i].num=i;
        
    }
    n=i;
    sort(mice,mice+i,cmp);
    //for(j=0;j<i;j++){
    //    cout<<mice[j].we<<" "<<mice[j].sp<<endl;
    //}cout<<n;

    for(i=0;i<n;i++){
        Max=0;
        for(j=i;j>=0;j--){
            if(mice[i].we>mice[j].we && mice[i].sp<mice[j].sp && Max<=dp[j]){
                Max=dp[j];
            }
        }
        dp[i]+=Max;
        if(dp[i]>Mmax){
            Mmax=dp[i];
        }
    }
    cout<<Mmax;

    system("pause"); 
    return 0;

}*/

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node{
	int w;
	int s;
	int no;
}mice[1111];
struct node1{
	int pre;
	int num;
}dp[1111];
bool cmp(node a,node b)
{
	if(a.w==b.w)
		return a.s>b.s;
	return a.w<b.w;
}
int main()
{
	int i,j,k,max,t;
	i=0;
	while(scanf("%d%d",&mice[i].w,&mice[i].s)!=EOF)
	{
		mice[i].no=i+1;
		i++;
		//if(i==9)
		//	break;
	}
	sort(mice,mice+i,cmp);
	//printf("\n");
	//for(j=0;j<i;j++)
	//	printf("%d %d\n",mice[j].w,mice[j].s);
	//printf("\n");
    for(j=0;j<i;j++)
	{
		dp[j].num=1;
		dp[j].pre=0;
	}
	max=1;
	t=1;
	for(j=1;j<i;j++)
	{
		for(k=0;k<j;k++)
		{
			if(mice[k].s>mice[j].s&&mice[k].w<mice[j].w)
			{
				if(dp[j].num<dp[k].num+1)
				{
					dp[j].num=dp[k].num+1;
					dp[j].pre=k;
				}
			}
		}
		if(dp[j].num>max)
		{
			max=dp[j].num;
			t=j;
		}
	}
	printf("%d\n",max);
	int m[1111];
    for(j=1;j<=max;j++)
	{
		m[j]=t;
		t=dp[t].pre;
	}
	for(k=max;k>=1;k--)
		printf("%d\n",mice[m[k]].no);
	return 0;
}
