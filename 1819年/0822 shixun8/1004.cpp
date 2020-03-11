#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
#include<functional>
//#include<Windows.h>
#include<map>
using namespace std;

int num[27],target,flag=0,x[5],v[14],d[14];
int s,cnt;
char a[14],b[14];

bool compute(int a,int b,int c,int d,int e){
    if(a - b*b + c*c*c - d*d*d*d + e*e*e*e*e==target)
    return true;
    else return false;
}

void dfs(int dep){
    int i;
    //if(flag){
    //    return;
    //}
    if(dep>=5){
        if(compute(x[0],x[1],x[2],x[3],x[4])){
            for(cnt=0;cnt<5;cnt++){
                b[cnt]=x[cnt]+16+'0';
            }
            //flag=1;
        }
        return;
    }
    for(i=0;i<strlen(a);i++){
        if(!v[i]){
            x[dep]=d[i];
            v[i]=1;
            dfs(dep+1);
            v[i]=0;
        }
    }
}

int main(){
    for(s=1;s<27;s++){
        num[s]=s;
    }
    while(~scanf("%d%s",&target,a),target){
        //if(target==0&&a[0]=='E'&&a[1]=='O'&&a[2]=='F')
        //    break;
        for(s=0;s<strlen(a);s++){
            d[s]=num[a[s]-'0'-16];
        }
        sort(d,d+strlen(a));
        
        dfs(0);
        
        if(strlen(b)){
            printf("%s\n",b);   
        }else{
            printf("no solution\n");
        }
        ////////////////
        memset(v,0,sizeof(v));
        memset(x,0,sizeof(x));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        //flag=0;
    }
    
    //system("pause");
    return 0;
}