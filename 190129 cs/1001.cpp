#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
//1009
// int cnt=0;
// void dfs(int N,int shop,int flow){
//     if(N==0&&shop==5&&flow==10) {
//         cnt++;
//         return;
//     }
//     if(N==0||(flow>=10&&shop>=5)) return;
    
//     for(int i=0;i<2;i++){
//         if(!(i&1)&&flow<10){
//             dfs(N-1,shop,flow+1);
//         }else if(shop<5){
//             dfs(N*2,shop+1,flow);
//         }
//     }
//     return;
// }
//1021
// int a[120]={-1},book[20]={0},sum=0;          //book数组是用来标记1-13哪个数已经被用过了，用过则记为1，否则记为0；
// void dfs(int x)
// {
//     if(x>3&&a[1]+a[2]!=a[3])           //如果前三个数已经被取出来但不符合题设条件，则返回重找
//         return;
//     if(x>6&&a[4]-a[5]!=a[6])           //若前三个数满足第一条，看4-6个数是否满足第二个条件
//         return;
//     if(x>9&&a[7]*a[8]!=a[9])             //同上
//         return;
//     if(x>12&&a[10]/a[11]==a[12])        //如果所有条件均满足，则让sum++
//     {
//         sum++;
//         return;
//     }

//     for(int i=1;i<14;i++)                     //将1-13放入每一个格子中
//     {
//         if(book[i]==0)                     //若该数字没被用过则可以用，进入下一步
//         {
//             a[x]=i;
//             book[i]=1;
//             dfs(x+1);
//             book[i]=0;
//         }
//     }
//     return;
// }

//自己写的/
// int a[14],vis[14],sum;
// void dfs(int de){

//     if(de>3) if(a[1]+a[2]!=a[3]) return;
//     if(de>6) if(a[4]-a[5]!=a[6]) return;
//     if(de>9) if(a[7]*a[8]!=a[9]) return;
//     if(de>=12) {
//         double d=(double)a[10],b=(double)a[11],c=(double)a[12];
//         //if( abs(d/b-c)>0.00001) return;//人类除法的情况
//         //if(a[10]/a[11]!=a[12]) return;//计算机除法
//         else {
//             sum++;
//             return;
//         }
//     }

//     for(int i=1;i<=13;i++){
//         if(vis[i]==0){
//             a[de+1]=i;
//             vis[i]=1;
//             dfs(de+1);
//             vis[i]=0;
//         }
//     }
    
// }
//1022
// int cnt=0;
// void dfs(int N,int flow){
//     if(N==39&& !(flow&1) ) {
//         cnt++;
//         return;
//     }
//     if(N>39) return;
    
//     // for(int i=0;i<2;i++){
//     //     if(!(i&1)&&flow<10){
//     //         dfs(N-1,shop,flow+1);
//     //     }else if(shop<5){
//     //         dfs(N*2,shop+1,flow);
//     //     }
//     // }

//     dfs(N+1,flow+1);
//     dfs(N+2,flow+1);
//     return;
// }


int main(){
    // 1
    //cout<<"寒假愉快"; /*注意，输出的最后不要有回车*/
    
    //1002
    //cout<<"10";

    //1004
    // int cnt=0,x,x1,x2;//儿子x-27
    // for(int i=28;i<=99;i++){
    //     x1=i/10;x2=i%10;
    //     if(10*x2+x1==i-27) {cout<<i<<endl;cnt++;}

    // }
    //cout<<"7";

    //1005
    // int sum=0;
    // for(int i=0;i<100;i++){
    //     sum=0;
    //     for(int j=i;j<100;j++){
    //         sum+=j;
    //         if(sum==236) {
    //             cout<<i;
    //             break;}
    //     }
    // }
    //cout<<"26";

    //1006
    // int a,b,c,d,e,t1,t2,t3,t4,cnt=0;
    // for(a=1;a<10;a++){
    //     for(b=1;b<10;b++){
    //         for(c=1;c<10;c++){
    //             for(d=1;d<10;d++){
    //                 for(e=1;e<10;e++){
    //                     if(a!=b&&a!=c&&a!=d&&a!=e && b!=c&&b!=d&&b!=e && c!=d&&c!=e && d!=e){}
    //                     else continue;
    //                     t1=a*10+b,t2=c*100+d*10+e,t3=a*100+d*10+b,t4=c*10+e;
    //                     if(t1*t2==t3*t4) cnt++;

    //                 }
    //             }
    //         }
    //     }
        
    // }
    //cout<<"142";

    //1007
    //cout<<"35";

    //1008
//     int a,b,c,d,e,f,g;
//     int t1,t2;
//     //1000a+101b+d=9000e+900f+90c;
//    for(a=1;a<10;a++){
//         for(b=1;b<10;b++){
//             for(c=1;c<10;c++){
//                 for(d=1;d<10;d++){
//                     for(e=1;e<10;e++){
//                         for(f=1;f<10;f++){
//                             if(a!=b&&a!=c&&a!=d&&a!=e && b!=c&&b!=d&&b!=e && c!=d&&c!=e && d!=e && f!=a&&f!=b&&f!=c&&f!=d&&f!=e){}
//                             else continue;
//                             t1=a*1000+101*b+d,t2=9000*e+f*900+90*c;
//                             if(t1==t1) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;

//                         }
                        
//                     }
//                 }
//             }
//         }
//     }
    //cout<<"1024";

    //1009
    // int N=2;
    // dfs(2,0,0);
    // cout<<cnt;
    //cout<<"14";
    //1010 cout<<"q";
    //1011 
    //cout<<"2852";

    //1012
    //cout<<"142857";

    //1013 
    //cout<<"2342A3A4";

    //1015
    // int cnt=0;
    // long long int b,c=10;
    // for(long long int i=0;i<10000;i++){
    //     b=i*i*i;
    //     if(i>=c) c*=10;
    //     if(b%c==i) {
    //         cnt++;
    //         cout<<i<<endl;
    //     }
    // }
    // cout<<cnt;
    //cout<<"36";

    //1016
    // long long int sum=0;
    // for(int i=1;i<101;i++){
    //     sum+=i*(i+1)/2;
    // }
    // cout<<sum;
    //cout<<"171700";

    //1017
    // cout<<"69";

    //1018
    // int cnt=0,flag=0,b,c;
    // for(int i=10000;i<100000;i++){
    //     b=i;
    //     flag=0;
    //     while(b!=0){
    //         c=b%10;
    //         b/=10;
    //         if(c==4){
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag) continue;
    //     cnt++;
    // }
    // cout<<cnt;
    //cout<<"52488";

    //1019
    // int a,b,c,d,cnt=0,t;
    // for(a=0;a<21;a++){
    //     for(b=0;b<41;b++){
    //         for(c=0;c<51;c++){
    //             if(a+b+c>50) continue;
    //             t=a*100+b*50+c*10+(50-a-b-c)*5;
    //             if(t==2000) {cnt++;
    //                 cout<<a<<" "<<b<<" "<<c<<" "<<50-a-b-c<<endl;
    //             }
                
    //         }
    //     }
    // }
    // cout<<cnt;
    //cout<<"50";

    //1020
    //cout<<"1025";
    //1021
    //dfs(1);
    //cout<<"64";//此为人类除法，答案是gous计算机除法
    //cout<<sum;
    //自己写的测试代码
        // sum=0;
        // dfs(0);
        // cout<<sum;

    //1022
    // int a[40];
    // a[1]=1;a[2]=2;
    // for(int i=3;i<40;i++){
    //     a[i]=a[i-1]+a[i-2];
    //     //cout<<a[i]<<endl;
    // }
    // cout<<a[39];///错误写法，主要是由于规定了左右脚
    // dfs(0,0);
    // cout<<cnt;
    //cout<<"51167078";



    //1023
    // long long int X=10,Y=90;
    // int time0=0,time1=0,flag=0;
    // while(time0<10){
    //     time1=5;
    //     time0+=1;
    //     while(time1<=60){
    //         if(time1==5) Y-=X;
    //         if(time1==15) Y-=X;
    //         if(time1==25) Y-=X;
    //         if(time1==35) Y-=X;
    //         if(time1==45) Y-=X;
    //         if(time1==55) Y-=X;
    //         if(time1%20==0) Y*=2;
    //         if(time1%30==0) X*=2;
    //         if(Y<=0) {
    //             flag=1;
    //             break;
    //         }
    //         time1+=5;
    //     }
    //     if(flag) break;
    // }
    //cout<<"0"<<endl<<"94371840";
    

    system("pause");
    return 0;
}
