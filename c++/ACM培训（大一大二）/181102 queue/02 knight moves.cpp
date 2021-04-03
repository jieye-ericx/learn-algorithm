// 题意：在8*8棋盘上给定两个点，求将马从一个点移到另一个点所需要的最少步数。
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
#include <queue>
using namespace std;
#define N 9
int vis[N][N];
int bo[N][N];
int dir[8][2]={{-2,1},{-1,2},{1,2},{2,2},{2,-2},{1,-2},{-1,-2},{-2,-1}};

bool legal(int x,int y){

}

int main(){
	int i,now,x,y,dx,dy;
    string st,en;
    pair<pair<int,int>,int> cur;
    pair<int ,int>cur1;
    while(cin>>st>>en){
        memset(vis,0,sizeof(vis));
        //
        queue<pair<int,int>,int>qu;
        x=st[0]-'a'+1;
        y=st[1]-'0';
        qu.push(make_pair(make_pair(x,y),0));
        vis[x][y]=1;
        while(!qu.empty()){
            cur=qu.front();
            cur1=cur.first;
            x=cur1.first;
            y=cur1.second;
            if(x==en[0]-'a'+1 && y==en[1]-'0') {
                std::cout << "To grt from "<<st<<" to "<<en<<" takes "<<cur.second<<"steps..." << '\n';
                break;
            }
            qu.pop();

            for(i=0;i<8;i++){
                dx=x+dir[i][0];
                dy=y+dir[i][1];
                if(dx<1||dx>8||dy<1||dy>8) continue;
                if(vis[dx][dy]) continue;
                vis[dx][dy]=1;
                qu.push(make_pair(make_pair(dx,dy),cur.second+1));
	    		}
	    	}
    } 

    system("pause");
    return 0;
}
