#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,Q,a,b,Max;
int maps[10][10];
void dfs(int x, int y, int step) {
    if(x>=N) {
        Max=max(Max,step);
        return;
    }
    if(y >= M) { //重新从下一行的0开始
        dfs(x+1,0,step);
        return;
    }
    if(maps[x][y]==1) { //若当前位置已经有棋子则不处理，从同行的下一个开始处理
        dfs(x,y+1,step);//
        return;
    }
    dfs(x,y+1,step);//当前位置不选择放东西
    bool success=true;
    int flag=0;
    for(int i=y-1; i>=0; i--) {//检查同行不能有冲突
        if(maps[x][i]==1) {
            flag++;
        }
        if(maps[x][i]==2) {
            if(flag==1) {
                success=false;
                break;
            } else {
                flag++;
            }
        }
    }
    flag=0;
    for(int i=x-1; i>=0; i--) {//检查同列不能有冲突
        if(maps[i][y]==1) {
            flag++;
        }
        if(maps[i][y]==2) {
            if(flag==1) {
                success=false;
            } else {
                flag++;
            }
        }
    }
    if(!success)return;
    maps[x][y]=2;
    dfs(x,y+1,step+1);
    maps[x][y]=0;
}
int main() {
    while(~scanf("%d%d%d",&N,&M,&Q)) {
        memset(maps,0,sizeof(maps));
        for(int i=0; i<Q; i++) {
            scanf("%d%d",&a,&b);
            maps[a][b]=1;
        }
        Max=0;
        dfs(0,0,0);
        printf("%d\n",Max);
    }
    return 0;
}
