#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 1000
string s;
char a[N][2]; 
int vis[N];
int i,j;
//int dir[8][2]={{0,1},{1,0},{1,1},{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1}};
//vector<char> es[];
int flag;
void dfs(char x){
    int t;
    if(x=='m'){
        flag=1;
        return;
    }
    for(t=0;t<i;t++){
        if(a[t][0]==x&&!vis[t]) {
            vis[t]=1;
            dfs(a[t][1]);
            vis[t]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

	
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        s.clear();
        i=0;
        flag=0;
        //
        while(cin>>s){
            a[i][0]=s[0];
            a[i++][1]=s[s.length()-1];

            if(s=="0"){
                for(j=0;j<i;j++){
                    if(a[j][0]=='b') {
                        dfs(a[j][1]);
                        if(flag==1) break;
                    }
                }
                if(flag==1) printf("Yes.\n");
                else printf("No.\n");
                memset(a,0,sizeof(a));
                memset(vis,0,sizeof(vis));
                s.clear();
                i=0;
                flag=0;
            }  
        }
        
        
	
	return 0;
}
