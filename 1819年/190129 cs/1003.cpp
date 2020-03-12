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

//1005
// int cnt=0,vis[10],a[10];
// void dfs(int n){
//     if(n==10){
//         if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]==a[7]*100+a[8]*10+a[9]){
//             cnt++;
//             //cout<<a[1]*100+a[2]*10+a[3]<<"+"<<a[4]*100+a[5]*10+a[6]<<"="<<a[7]*100+a[8]*10+a[9]<<endl;
//         }
//         return;
//     }
//     for(int i=1;i<=9;i++){
//         if(vis[i]==0){
//             vis[i]=1;
//             a[n]=i;
//             dfs(n+1);
//             vis[i]=0;
//         }
//     }
// }

//1009//收获挺多 剪枝非常必要，19！太大，如直接n>20再判断则所需时间太长
// int cnt=0,vis[23],a[24],ans[20],co;
// void dfs(int n){
//     if(n>7){
//         co=a[1]+a[2]+a[3];
//         if(co!=a[4]+a[5]+a[6]+a[7]) return;
//     }
//     if(n>12){
//         if(co!=a[1]+a[4]+a[8]) return;
//         if(co!=a[3]+a[7]+a[12]) return;
//         if(co!=a[8]+a[9]+a[10]+a[11]+a[12]) return;
//     }
//     if(n>16){
//         if(co!=a[13]+a[14]+a[15]+a[16]) return;
//         if(co!=a[2]+a[5]+a[9]+a[13]) return;
//         if(co!=a[2]+a[6]+a[11]+a[16]) return;
//     }
//     if(n>=20){
//         if(co!=a[17]+a[18]+a[19]) return;
//         if(co!=a[8]+a[13]+a[17]) return;
//         if(co!=a[4]+a[9]+a[14]+a[18]) return;
//         if(co!=a[1]+a[5]+a[10]+a[15]+a[19]) return;
//         if(co!=a[3]+a[6]+a[10]+a[14]+a[17]) return;
//         if(co!=a[7]+a[11]+a[15]+a[18]) return;
//         if(co!=a[12]+a[16]+a[19]) return;
    
//         for(int i=1;i<=19;i++){
//             ans[i]=a[i];
//             //cout<<a[i]<<" ";
//         }
//         return;
//     }
//     for(int i=1;i<=19;i++){
//         if(vis[i]==0){
//             vis[i]=1;
//             a[n]=i;
//             dfs(n+1);
//             vis[i]=0;
//         }
//     }
// }

//1011
// int vis[8],a[7];
// int b[32900][7];
// long long cnt=0,t=1;
// void dfs(int n,int s){
//     if(s>24||n>7) return;
//     if(n==7){
//         if(s==24){
//             cnt++;
//             for(int i=1;i<=6;i++){
//                 //cout<<a[i]<<" ";
//                 b[t][i]=a[i];
//             }
//             t++;
//             //cout<<endl;
//         }
//     }
//     for(int i=0;i<=8;i++){
//         a[n]=i;
//         dfs(n+1,s+i);
//     }
// }

//1019
// int a[22],vis[22];
// vector<int> p;
// void dfs(int le,int ri,int be){
//     if(le==60&&ri==60&&be==60){
//         for(int i=0;i<p.size();i++){
//             cout<<p[i]<<" ";
//         }
//         return;
//     }
//     if(le>60||ri>60||be>60) return;
//     for(int i=0;i<22;i++){
//         if(vis[i]) continue;
//         dfs(le+a[i],ri,)
//     }
// }



int main(){
    //1001
    //int i,j;
    // 1792年1/1日 5359
    // int t=8113-5359;
    // for(i=1792;t>0;i++){
    //     if( (i%4==0&&i%100!=0) || i%400==0 ) t-=366;
    //     else t-=365;
    //     cout<<t<<" "<<i<<endl;
    // }
    // cout<<"1799-07-16";

    //1002
    //cout<<"2017-08-05";

    //1003
    // int a,b,c,d,e,t;
    // for(int i=10234;i<=99999;i++){
    //     t=i;
    //     a=t/10000,t%=10000;
    //     b=t/1000,t%=1000;
    //     c=t/100,t%=100;
    //     d=t/10,t%=10;
    //     e=t;
    //     if(a!=b&&a!=c&&a!=d&&a!=e
    //     && b!=c&&b!=d&&b!=e
    //     && c!=d&&c!=e
    //     && d!=e){

    //     }else continue;
    //     if(e==0) continue;
    //     for(int j=1;j<=9;j++){
    //         if(i*j==10000*e+1000*d+100*c+10*b+a) cout<<i;
    //     }
    // }
    
    //1004
    // double a=2,b=6,c=6,d=5;
    // int cnt=0;
    // for(int i=1;i<=9;i++){
    //     for(int j=1;j<=9;j++){
    //         if(i==j) continue;
    //         for(int x=1;x<=9;x++){
    //             for(int y=1;y<=9;y++){
    //                 if(x==y) continue;
    //                 a=(double)i,b=(double)j,c=(double)x,d=(double)y;
    //                 if( abs((a/b)*(c/d)-(a*10.0+c)/(b*10.0+d))<0.000000001 ) {//注意duble精度问题,记住要加绝对值
    //                 //if( (a/b)*(c/d)==(a*10.0+c)/(b*10.0+d)) {
    //                     cnt++;
    //                     cout<<(a/b)*(c/d)-(a*10.0+c)/(b*10.0+d)<<endl;
    //                     cout<<a<<"  "<<c<<"  "<<(a*10.0+c)<<endl
    //                         <<b<<"  "<<d<<"  "<<(b*10.0+d)<<endl<<endl;
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout<<cnt;
    // cout<<"14";

    //1005
    // dfs(1);
    // cout<<cnt;
    //1006
    // int a[55],sum=0;
    // for(int i=1;i<=49;i++){
    //     a[i]=i;
    //     sum+=i;
    // }
    // int t=sum,x;
    // for(int i=1;i<=46;i++){
    //     t=sum;
    //     t-=a[i];
    //     t-=a[i+1];
    //     t+=a[i]*a[i+1];
    //     x=t;
    //     for(int j=i+2;j<=48;j++){
    //         t=x;
    //         t-=a[j];
    //         t-=a[j+1];
    //         t+=a[j]*a[j+1];
    //         if(t==2015){
    //             cout<<i<<" "<<j<<endl;
    //         }
    //         //if(t>sum) break;
    //     }
    // }
    //cout<<"16";
    //1007
    // double a,b;
    // int c=1,d=3,t;
    // for(int i=0;i<100;i++){
    //     a=c*1.0/d*1.0;
    //     t=d;d+=c;
    //     c=t;
    // }
    //cout<<"1364/2207";
    //1008
    //cout<<"7,A,Q,2,8,3,J,4,9,5,K,6,10";
    
    //1009
    // memset(vis,0,sizeof(vis));
    // memset(a,0,sizeof(a));
    // a[1]=15;a[2]=13;vis[15]=1;vis[13]=1;
    // dfs(3);
    // for(int e=1;e<=19;e++){cout<<ans[e]<<" ";}
    //cout<<"9 6 5 2 16";
    
    //1010
    // double m;
    // for(int t=1000;t<2000;t++){
    //     m=(double)t;
    //     for(int i=1;i<=5;i++){
            
    //         m*=1.25;
    //         m-=1;
    //     }
    //     cout<<t<<" ";printf("%.5lf\n",m);
    // }
    //cout<<"3129";

    //1011
    // dfs(1,0);
    // //cout<<cnt;
    // int pp=0,a,m1[7]={0,0,0,0,8,8,8},m2[7]={0,1,1,4,5,6,7},y,c,maxt=0,cnt1=0;
    // for(int p=1;p<32662;p++){
    //     cnt1=0;
    //     for(a=1;a<7;a++){
    //         for(c=1;c<7;c++){
    //             for(y=1;y<7;y++){
    //                 if(m1[a]!=m2[c]&&m1[a]!=b[p][y]&&m2[c]!=b[p][y]){
    //                     if(b[p][y]>m1[a]&&b[p][y]>m2[c]){
    //                         cnt1++;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     if(maxt<cnt1){
    //         maxt=cnt1;
    //         pp=p;
    //     }
    // }
    // for(int u=1;u<=6;u++){
    //     cout<<b[pp][u]<<" ";
    // }

    //1012
    // for(int a=1;a<=45;a++){
    //     for(int b=a+1;b<=1000000000;b++){
    //         if(45*(a+b)==2*a*b) cout<<a<<" "<<b<<endl;
    //     }
    // }
    //cout<<"7";
    //1013
    // int a,b,c;
    // for(a=1;a*a<=1000;a++){
    //     for(b=a+1;b*b<=1000;b++){
    //         for(c=b+1;c*c<=1000;c++){
    //             if(a*a+b*b+c*c==1000){
    //                 cout<<a<<" "<<b<<" "<<c<<endl;
    //             }
    //         }
    //     }
    // }
    //cout<<"10";
    //1014
    //https://www.cnblogs.com/lemonbiscuit/p/7776008.html
    //cout<<"1170";
    //1015
    // double t=pow(2,64);
    // t=t-10;
    // printf("%.0lf",t);
    // t-=1;
//cout<<"18446744073709551615";
    //printf("%.0lf",t);
    
    //1016
    //cout<<"116";
    //1017
    // int i;
    // double c[203],mi=0,mx,my;//表示i个绳子的配对数，c[i]=c[i-1]*(2*i-1);
    // //因为第i个绳子的任一个头可以与其它2i-1个配对，剩下就是c[i-1]的情况
    // c[1]=1;
    // for(i=2;i<101;i++){
    //     c[i]=c[i-1]*(2*i-1);
    // }
    // double f[102][102];
    // f[1][1]=1;
    // for(i=2;i<101;i++){
    //     f[1][i]=0;
    //     f[i][1]=f[i-1][1]*c[i-1]*(i-1)*2/c[i];
        
    // }
    // for(i=2;i<101;i++){
    //     for(int j=2;j<101;j++){
    //         f[i][j]=(f[i-1][j]*(i-1)*2*c[i-1]+f[i-1][j-1]*c[i-1])/c[i];
            
    //     }
    // }
    // for(i=1;i<=100;i++){
    //     if(f[100][i]>mi){
    //             mi=f[100][i];
    //             mx=100,my=i;
    //         }
    // }
    // cout<<mx<<" "<<my;
    // cout<<"3";
    //1018
    // long long int a[100];
    // a[0]=1;
    // a[1]=1;
    // for(int i=2;i<20;i++){
    //     a[i]=
    // }

    //cout<<"35357670";
    //1019

    //1020
    /*
    7 
    5 8 
    7 8 8 
    9 2 7 2 
    8 1 4 9 1 
    8 1 8 8 4 1 
    7 9 6 1 4 5 4 
    5 6 5 5 6 9 5 6 
    5 5 4 7 9 3 5 5 1 
    7 5 7 9 7 4 7 3 3 1 
    4 6 4 5 5 8 8 3 2 4 3 
    1 1 3 3 1 6 6 5 5 4 4 2 
    9 9 9 2 1 9 1 9 2 9 5 7 9 
    4 3 3 7 7 9 3 6 1 3 8 8 3 7 
    3 6 8 1 5 3 9 5 8 3 8 1 8 3 3 
    8 3 2 3 3 5 5 8 5 4 2 8 6 7 6 9 
    8 1 8 1 8 4 6 2 2 1 7 9 4 2 3 3 4 
    2 8 4 2 2 9 9 2 8 3 4 9 6 3 9 4 6 9 
    7 9 7 4 9 7 6 6 2 8 9 4 1 8 1 7 2 1 6 
    9 2 8 6 4 2 7 9 5 4 1 2 5 1 7 3 9 8 3 3 
    5 2 1 6 7 9 3 2 8 9 5 5 6 6 6 2 1 8 7 9 9 
    6 7 1 8 8 7 5 3 6 5 4 7 3 4 6 7 8 1 3 2 7 4 
    2 2 6 3 5 3 4 9 2 4 5 7 6 6 3 2 7 2 4 8 5 5 4 
    7 4 4 5 8 3 3 8 1 8 6 3 2 1 6 2 6 4 6 3 8 2 9 6 
    1 2 4 1 3 3 5 3 4 9 6 3 8 6 5 9 1 5 3 2 6 8 8 5 3 
    2 2 7 9 3 3 2 8 6 9 8 4 4 9 5 8 2 6 3 4 8 4 9 3 8 8 
    7 7 7 9 7 5 2 7 9 2 5 1 9 2 6 5 3 9 3 5 7 3 5 4 2 8 9 
    7 7 6 6 8 7 5 5 8 2 4 7 7 4 7 2 6 9 2 1 8 2 9 8 5 7 3 6 
    5 9 4 5 5 7 5 5 6 3 5 3 9 5 8 9 5 4 1 2 6 1 4 3 5 3 2 4 1
    */
    // double a[32][32],t;
    // int i,j;
    // set<double> p;
    // for(i=1;i<=29;i++){
    //     for(j=1;j<=i;j++){
    //         cin>>t;
    //         a[i][j]=t*100000;
    //     }
    // }
    // for(i=1;i<=29;i++){
    //     for(j=1;j<=i;j++){
    //         a[i+1][j]+=a[i][j]/2.0;
    //         a[i+1][j+1]+=a[i][j]/2.0;
    //     }
    // }
    // for(i=1;i<=30;i++){
    //     // for(j=1;j<=i;j++){
    //         p.insert(a[30][i]);
    //     // }
    //     //cout<<endl;
    // }
    // set<double>::iterator it;
    // // for(it=p.begin();it!=p.end();it++){
    // //     cout<<*it<<endl;
    // // }
    // it=p.begin();
    // double mi=*it;
    // it=p.end(),it--;
    // double ma=*it;
    // printf("%lf",2086458231.0/mi*ma);
    //cout<<"72665192664";

    
    system("pause");
    return 0;
}