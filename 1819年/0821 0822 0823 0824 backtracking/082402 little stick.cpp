//Description POJ2817
//乔治拿来一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过50个长度单位。
//然后他又想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。
//请你设计一个程序，帮助乔治计算木棒的可能最小长度。每一节木棍的长度都用大于零的整数表示。
//Input
//输入包含多组数据，每组数据包括两行。第一行是一个不超过64的整数，表示砍断之后共有多少节木棍。
//第二行是截断以后，所得到的各节木棍的长度。在最后一组数据之后，是一个零。
//Output
//为每组数据，分别输出原始木棒的可能最小长度，每组数据占一行。
//Sample Input 
//9 
//5 2 1 5 2 1 5 2 1 
//4 
//1 2 3 4 
//0
//Sample Output 
//6 
//5
#include <cmath>
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

#define N 65
int a[N],vis[N];
int n,len,num,rest;//num根数

int dfs(int k,int cur_len,int st){//st表示从哪里开始
    int i,pre=0;
    if(k>num-1){
        return 1;
    }
    for(i=st;i<n;i++){
        if(!vis[i] && a[i]!=pre){
            pre=0;
            if(cur_len+a[i]==len){
                rest-=a[i];
                vis[i]=1;
                if(dfs(k+1,0,0)) return 1;
                rest+=a[i];
                vis[i]=0;
            } else if(cur_len+a[i]<len){
                vis[i]=1;
                rest-=a[i];
                if(dfs(k,cur_len+a[i],i+1)) return 1;
                if(cur_len+rest<len) break;//不取a[i]剩余的木棍总长与
                rest+=a[i];
                vis[i]=0;
            }else if(cur_len+a[n-1]>len){//较弱剪枝
                break;
            }
            pre=a[i];
        }
        
    }

}

int main(){
    ios::sync_with_stdio(false);
    int i,s=0;
    while(cin>>n,n){
        for(i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        sort(a,a+n,greater<int>());
        for(i=a[n-1];i<=s/2;i++){
            if(!s%i){
                rest=s; 
                len=i;//表示小木棍的拼凑长度
                num=s/i;//在该拼凑长度下的根数
                memset(vis,0,sizeof(vis));
                if(dfs(1,0,0)){
                    cout<<"yes"<<endl;
                }else{
                    cout<<"no"<<endl;
                }
            }

        }
    }
    

    system("pause");
    return 0;
}