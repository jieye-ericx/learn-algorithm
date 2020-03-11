#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
#define N 100100


int father[N],fri[N];
int t,n,i,k;
map<string,int> mp;


int findset(int x){
	if(x!=father[x])
		father[x]=findset(father[x]);//回溯，路径压缩
	return father[x];
}
void unit(int x,int y){
    int xl=findset(x);
    int yl=findset(y);
    if(xl!=yl){
        father[yl]=xl;
        fri[xl]+=fri[yl];
    }
}
int main(){
    char name1[30],name2[30];
    while(~scanf("%d",&t))
        while(t--){
            k=1;
            for(i=0;i<N;i++){
            father[i]=i;
            fri[i]=1;
            }
            mp.clear();
            /////////////
            scanf("%d",&n);
            for(i=0;i<n;i++){
                scanf("%s %s",name1,name2);
                //cin>>name1>>name2;
                if(mp.find(name1)==mp.end()){
                    mp[name1]=k++;
                }
                if(mp.find(name2)==mp.end()){
                    mp[name2]=k++;
                }
                unit(mp[name1],mp[name2]);
                printf("%d\n",fri[findset(mp[name1])]);
            }
        }
    return 0;   
}