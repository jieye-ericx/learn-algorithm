#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
//1006
// int vis[10];
// int ws(int i){
//     int cnt=0;
//     while(i>0){
//         i/=10;
//         cnt++;
//     }
//     return cnt;
// }
// bool check(int i){
//     int a=i,b,flag=0;
//     while(a>0){
//         b=a%10;
//         a/=10;
//         if(vis[b]!=1){
//             flag=1;
//             break;
//         }
//     }
//     if(flag) return false;
//     else return true;
// }
//1007
// int a[14],vis[14],sum;
// void dfs(int de){
//     if(de>=9) {
//         double t1=(double)a[1],t2=(double)a[2]/(double)a[3],
//         d=(double)a[4],e=(double)a[5],f=(double)a[6],
//         g=(double)a[7],h=(double)a[8],i=(double)a[9],
//         t3=(100*d+10*e+f)/(100*g+10*h+i);
//         if( abs(t1+t2+t3-10)>0.0000001 ) return;
//         //if(t1+t2+t3!=10) return;
//         else {
//             sum++;
//             return;
//         }
//         return ;
//     }

//     for(int i=1;i<=9;i++){
//         if(vis[i]==0){
//             a[de+1]=i;
//             vis[i]=1;
//             dfs(de+1);
//             vis[i]=0;
//         }
//     }
    
// }

//1016
// int a[10]={0,1,2,0,0,5,9,0,8,6},p[4],vis[10]={1,1,1,0,0,1,1,0,1,1};
// bool check(int i){
//     int a=i,b,flag=0;
//     if(i%10==0) return false;
//     while(a>0){
//         b=a%10;
//         a/=10;
//         if(!vis[b]){
//             flag=1;
//             break;
//         }
//     }
//     if(flag) return false;
//     else return true;
// }

// int turn(int i){
//     int t,k=0;
//     memset(p,0,sizeof(p));
//     while(i>0){
//         t=i%10;
//         p[k++]=a[t];
//         i/=10;
//     }
//     return p[0]*1000+p[1]*100+p[2]*10+p[3];
// }

//1017
// int a[14],cnt;
// void dfs(int n,int num){
//     if(n>13) return;
//     if(num>=13){
//         if(num==13){
//         cnt++;
//         }
//         return;
//     }
//     for(int i=0;i<=4;i++){
//         dfs(n+1,num+i);
//     }
// }

//1014
// int cnt=0,a[12],vis[12];
// void dfs(int N,int shop){
//     if(N==100&&shop==11) {
//         cnt++;
//         for(int i=1;i<=10;i++) cout<<a[i];
//         cout<<endl;
//         return;
//     }
//     if(shop>=11||N<=0) return;
//     a[shop]=0;
//     dfs(N-shop,shop+1);
//     a[shop]=1;
//     dfs(N*2,shop+1);
//     return;
// }

//1024
// int prime[10000000],cnt=0;
// bool isp(int x){
//     for(int i=2;i<=sqrt(x);i++){
//         if(x%i==0) return false;
//     }
//     return true;
// }

//1025
// int i,j,vis[10][10],ans;
// int dir[4][2] = {0,1,1,0,0,-1,-1,0};
// void dfs(int x,int y){
//     if(x==0||y==0||x==6||y==6){
//         ans++;
//         return;
//     }

//     for(int i=0;i<4;i++){
//         int dx1=x+dir[i][0];
//         int dy1=y+dir[i][1];
//         if(dx1<0||dy1<0||dx1>6||dy1>6){
//             continue;
//         }
//         int dx2=6-dx1;
//         int dy2=6-dy1;

//         if(vis[dx1][dy1]) continue;
//         vis[dx1][dy1]=1;
//         vis[dx2][dy2]=1;
//         dfs(dx1,dy1);
//         vis[dx1][dy1]=0;
//         vis[dx2][dy2]=0;
//     }
// }
//方法2
// int a[18], c, m[6][6], vis[6][6], ans;
// int dir[4][2] = {1,0,-1,0,0,1,0,-1};
// 连通返回1，不连通返回0 
// int bfs(int x, int y){
// 	int x1, y1, dx, dy, cnt = 0;
// 	queue<pair<int, int> > qu;
// 	qu.push(make_pair(x, y));
// 	pair<int, int> pa;
// 	vis[x][y] = 1;
// 	while(!qu.empty()){
// 		pa = qu.front();
// 		qu.pop();
// 		cnt++;
// 		x1 = pa.first;
// 		y1 = pa.second;
// 		for(int i=0; i<4; i++){
// 			dx = x1 + dir[i][0];
// 			dy = y1 + dir[i][1];
// 			if(vis[dx][dy])
// 				continue;
// 			if(m[dx][dy]==1)
// 				continue;
// 			if(dx<0 || dy<0 || dx>5 || dy>5)
// 				continue;
// 			qu.push(make_pair(dx, dy));
// 			vis[dx][dy] = 1; 
// 		}
// 	}
// 	return (cnt==18);
// }

int main(){
    // 1001
    // cout<<"15";

    //1002
    //cout<<"2299";

    //1003
    //cout<<"1988";

    //1004
    // for(int x=1;x*23<=823;x++){
    //     for(int y=1;y*19<=823;y++){
    //         if(x*23+y*19==823){
    //             cout<<x<<" "<<y<<"\n";
    //         }
    //     }
    // }

    //1005
	//cout<<"6048";

    //1006
    // int a,b,c,flag;
    // for(int i=1;i<999;i++){
    //     for(int j=i+1;j<=999;j++){
    //         if(ws(i)+ws(j)!=4) continue;
    //         memset(vis,0,sizeof(vis));
    //         flag=0;
    //         a=i;
    //         while(a>0){
    //             b=a%10;
    //             a/=10;
    //             if(vis[b]!=0){
    //                 flag=1;
    //                 break;
    //             }
    //             vis[b]=1;
    //         }
    //         if(flag) continue;
    //         a=j;
    //         while(a>0){
    //             b=a%10;
    //             a/=10;
    //             if(vis[b]){
    //                 flag=1;
    //                 break;
    //             }
    //             vis[b]=1;
    //         }
    //         if(flag) continue;
    //         c=i*j;
    //         if(ws(c)!=4) continue;
    //         if(check(c)){
    //             memset(vis,0,sizeof(vis));
    //             flag=0;
    //             a=c;
    //             while(a>0){
    //                 b=a%10;
    //                 a/=10;
    //                 if(vis[b]!=0){
    //                     flag=1;
    //                     break;
    //                 }
    //                 vis[b]=1;
    //             }   
    //             if(flag) {

    //             }else
    //             cout<<i<<" "<<j<<endl;
    //         }
    //     }
    // }
    // cout<<"12";
    //1007
    // sum=0;
    // dfs(0);
    // cout<<sum;
    // a[1]=6,a[2]=8,a[3]=3,a[4]=9,a[5]=5,a[6]=2,a[7]=7,a[8]=1,a[9]=4;
    // double t1=(double)a[1],t2=(double)a[2]/(double)a[3],
    //     d=(double)a[4],e=(double)a[5],f=(double)a[6],
    //     g=(double)a[7],h=(double)a[8],i=(double)a[9],
    //     t3=(100*d+10*e+f)/(100*g+10*h+i);
    //1008
    // int a,b,c,d,t,m,n;
    // for(int i=317;i<=999;i++){
    //     t=i;
    //     a=t/100;
    //     t%=100;
    //     b=t/10;
    //     t%10;
    //     c=t;
    //     d=i*i;
    //     m=d/100000;
    //     n=d%10;
    //     if(a==m&&n==b) cout<<i<<endl;
    // }
    // cout<<"897";
    //1009
    // cout<<"1312.50";
    //1010
    //cout<<"7";
    //1011
    //cout<<"105";
    //1012
    //cout<<"145";
    //1013
    // for(int a=1;a<=20;a++){
    //     for(int b=a-1;b>0;b--){
    //         for(int c=b-1;c>0;c--){
    //             for(int d=c-1;d>0;d--){
    //                 if(b*c*d*b*d++a*c*d+aa*b*c==a*b*c*d) cout<<a<<","<<b<<","<<c<<","<<d<<",0"<<endl;
    //             }
    //         }
    //     }
    // }
    //cout<<"12,6,4,2,0\n15,10,3,2,0\n18,9,3,2,0\n20,5,4,2,0";
    
    //1014
    
    // dfs(10,1);
    // cout<<cnt;
    //cout<<"0010110011\n0111010000\n1011010000";
    
    //1015
    // int vis[10],a,b,flag,i;
    // unsigned long long tt;
    // for(i=203881;i<1000000;i++){
    //     memset(vis,0,sizeof(vis));
    //     flag=0;
    //     a=i;
    //     while(a>0){
    //         b=a%10;
    //         a/=10;
    //         if(vis[b]){
    //             flag=1;
    //             break;
    //         }
    //         vis[b]=1;
    //     }
    //     if(flag) continue;
    //     tt=(long long)i*(long long)i;
    //     while(tt>0){
    //         b=tt%10;
    //         tt/=10;
    //         if(vis[b]){
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(!flag) cout<<i;
    // }

    //1016

    
    // int i,j,m,n;
    // for(i=1000;i<10000;i++){
    //     if(!check(i)) continue;
    //     for(j=i+1;j<10000;j++){
    //         if(check(i)&&check(j)){
    //             m=turn(i),n=turn(j);
    //             if(m+n-i-j==558){
    //                 cout<<i<<" "<<m<<"\n"<<j<<" "<<n<<"\n\n";
    //             }
    //         }
    //     }
    // }
    //cout<<"9088";

    //1017
    // memset(a,0,sizeof(a));
    // dfs(0,0);
    // cout<<cnt;

    //1018
    //cout<<"0.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911375";
    
    //1019
    // double t=1.0,m;
    // for(int i=4;i<=9;i++){
    //     m=(double)i;
    //     t=t-1.0/m;
    // }
    // cout<<11.0/t;
    //cout<<"2520";
    
    //1020
    // vector<int> p;
    //long long int t=pow(111,3);
    // int m=0;
    // for(int i=1;i<t;i+=2){
    //     m=0;
    //     p.clear();
    //     for(int j=i;m<=t;j+=2){
    //         m+=j;
    //         p.push_back(j);
    //         if(m==t) break;
    //     }
    //     if(m==t) break;
    // }
    // for(vector<int>::iterator it=p.begin();it!=p.end();it++)
    //     cout<<*it<<endl;
    // int x=0;
    // for(int o=371;o<=2367;o+=2){
    //     x+=o;
    // }
    // cout<<"371";

    //1021
    //cout<<"1580";
    //1022
    // int a[12]={1,2,3,4,5,6,7,8,9,10,11,12},x;
    // do
    // {
    // 	if (a[0]==1&&a[1]==8&&a[11]==3)
    // 	{
    // 		x=a[0]+a[2]+a[5]+a[7];
    // 		if (x==a[0]+a[3]+a[6]+a[10] && x==a[7]+a[8]+a[9]+a[10]
    // 		 && x==a[1]+a[2]+a[3]+a[4] && x==a[1]+a[5]+a[8]+a[11] && x==a[4]+a[6]+a[9]+a[11])
    // 		 {
    // 		 	cout<<a[5];
    // 		 	break;
    // 		 }
    // 	}
    // }while (next_permutation(a,a+12));
    
    //1023
    // 180.90 88
    // 10.25 65
    // 56.14 90
    // 104.65 90
    // 100.30 88
    // 297.15 50
    // 26.75 65
    // 130.62 50
    // 240.28 58
    // 270.62 80
    // 115.87 88
    // 247.34 95
    // 73.21 90
    // 101.00 50
    // 79.54 50
    // 278.44 70
    // 199.26 50
    // 12.97 90
    // 166.30 78
    // 125.50 58
    // 84.98 90
    // 113.35 68
    // 166.57 50
    // 42.56 90
    // 81.90 95
    // 131.78 80
    // 255.89 78
    // 109.17 90
    // 146.69 68
    // 139.33 65
    // 141.16 78
    // 154.74 80
    // 59.42 80
    // 85.44 68
    // 293.70 88
    // 261.79 65
    // 11.30 88
    // 268.27 58
    // 128.29 88
    // 251.03 80
    // 208.39 75
    // 128.88 75
    // 62.06 90
    // 225.87 75
    // 12.89 75
    // 34.28 75
    // 62.16 58
    // 129.12 50
    // 218.37 50
    // 289.69 80
    // double a,b,c=0;
    // for(int i=1;i<=50;i++){
    //     cin>>a>>b;
    //     c+=a*b/100.0;
    // }
    // cout<<c;
    //  cout<<"5200";

    //1024
    // memset(prime,0,sizeof(prime));
    // for(int i=1;i<1000000;i++){
    //     if(isp(i)) {
    //         prime[i]=1;
    //         //cout<<i<<endl;
    //     }
    // }
    // int flag=0,y=0;
    // for(int i=0;i<1000000;i++){
    //     if(y) break;
    //     if(prime[i]!=1) continue;
    //     for(int j=i+1;j<1000000;j++){
    //         flag=0;
    //         if(prime[j]!=1) continue;
    //         int d=j-i;
    //         if(j+10*d>1000000) continue;
    //         if(prime[j+10*d]!=0) continue;
    //         for(int h=1;h<9;h++){
    //             if(prime[j+d*h]!=1){
    //                 flag=1;
    //                 break;
    //             }
    //         }
    //         if(flag) continue;
    //         else {
    //             cout<<d;
    //             y=1;
    //             break;    
    //         }
    //     }
    // }
    //cout<<"210";
    //1025
    //https://blog.csdn.net/qq_34594236/article/details/72375517
    // memset(vis,0,sizeof(vis));
    // ans=0;
    // vis[3][3]=1;
    // dfs(3,3);
    
    // cout<<ans/4;
    //cout<<"509";
    //方法二
    // int flag;
	// for(i=0; i<(1<<18); i++){
	// 	flag=0;
	// 	for(j=0; j<18; j++){
	// 		x = j/6;
	// 		y = j%6;
	// 		m[x][y] = ((i>>j) & 1);//m[x][y]=!!((1<<j)&i);
	// 		m[6-x-1][6-y-1] = 1 - ((i>>j) & 1);
	// 	}
	// 	for(int i1=0; i1<6; i1++){
	// 		for(j=0; j<6; j++){
	// 			if(m[i1][j] == 0){
	// 				memset(vis, 0, sizeof(vis));
	// 				ans += bfs(i1, j);
	// 				flag=1;
	// 				break;
	// 			}
	// 		}
	// 		if(flag)
	// 			break;
	// 	}			
	// } 
	// cout<<ans/4<<endl;
    system("pause");
    return 0;
}
