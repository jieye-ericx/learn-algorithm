#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define N 1003
vector<int> m[N];
int n,k,i,t,j,a,x;
int ret,tmp;
int main(){
    ios::sync_with_stdio(false);
    ret=0;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>a;
        m[a%k].push_back(a);
    }
    for(i=0;i<k;i++){
        sort(m[i].begin(),m[i].end(),greater<int>());
    }
    for(i=0;i<k;i++){
        if(m[i].size()<3) continue;
        if(3*i%k==0){
            tmp=m[i][0]+m[i][1]+m[i][2];
            ret=max(ret,tmp);
        }
    }
    for(i=0;i<k;i++){
        if(m[i].size()<2) continue;
        j=(k-2*i%k)%k;
        if(m[i].size()>=1){
            tmp=m[i][0]+m[i][1]+m[j][0];
            ret=max(ret,tmp);
        }
    }   
    for(i=0;i<k;i++){
        if(m[i].size()==0) continue;
        for(j=0;j<k;j++){
            if(i==j||m[j].size()==0) continue;
            x=(k-(i+j)%k)%k;
            if(m[x].size()>=1){
                tmp=m[i][0]+m[j][0]+m[x][0];
                ret=max(ret,tmp);
            }
        }
    }    
    cout<<tmp<<endl;
    system("pause");
	return 0;
}
