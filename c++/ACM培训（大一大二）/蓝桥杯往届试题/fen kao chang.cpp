// #include <cmath>
// #include <iostream>
// #include <cstring>
// #include <string>
// #include <algorithm>
// #include <cstdio>
// #include <vector>
// #include <set>
// #include <map>
// #include <functional>
// using namespace std;
// #define N 102
// int m,n,a,b,i,k,j,num;
// int parent[10002];
// vector<int> g[N];
// int vis[N*N];
// bool check(){
//     int i,j;
//     for(i=1;i<=n;i++){
//         if(vis[i]) {
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     while(cin>>n>>m){
//         num=0;
//         memset(vis,0,sizeof(vis));
//         //
//         for(i=0;i<m;i++){
//             cin>>a>>b;
//             g[min(a,b)].push_back(max(a,b));
//         }
//         vis[1]=1;
//         for(i=1;i<=n;i++){
//             if(!vis[i]) continue;
//             for(j=0;j<g[i].size();j++){
//                 vis[g[i][j]]=1;
//             }
//             for(k=i+1;k<=n;k++){
//                 if(find(g[i].begin(),g[i].end(),k) == g[i].begin() ){
//                     vis[k]=0;
//                 }
//             }
//             vis[i]=0;
//             num++;
//             if(check()) break; 
//         }
//         cout<<num<<endl;
//         // for(i=1;i<=m*n;i++){
//         //     cout<<"i="<<i<<" "<<"parent[i]="<<parent[i]<<endl;
//         // }
//     }
//     system("pause");
//     return 0;
// }
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
#define N 102
vector <int> g[N];
int vis[N];
int main(){
    int m,n,i,j,a,b,num;
    while(cin>>n>>m){
        memset(vis,0,sizeof(vis));
        num=0;
        //
        for(i=1;i<=m;i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(i=1;i<=n;i++){
            if(vis[i]) continue;
            for(j=1;j<=n;j++){
                if(vis[j]) continue;
                if(find(g[i].begin(),g[i].end(),j)==g[i].end())//没找到
                {
                    vis[j]=1;
                }
            }
            vis[i]=1;
            num++;
        }
        cout<<num<<endl;
        // vector<int>::iterator ret;
        // for(ret=g[1].begin();ret<g[1].end();ret++){
        //     cout<<*ret<<" ";
        // }
    }
    system("pause");
    return 0;
}