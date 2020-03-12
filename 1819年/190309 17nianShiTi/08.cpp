#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
//07//此方法未去重！！！！！！！！！！

// int i,year,mon,day,cnt;
// struct node
// {
//     int y,m,d;
// } p[10];
// bool tem(node n1,node n2){
//     if(n1.y!=n2.y) return n1.y<n2.y;
//     if(n1.m!=n2.m) return n1.m<n2.m;
//     return n1.d<n2.d;
// }

// void check(int year,int mon,int day){
//     int pyear;
//     if(mon>12||mon<1||day>31||day<1) return;
//     for(int i=0;i<2;i++){
//         pyear=year+1900+i*100;
//         if(pyear<=2059&&pyear>=1960){
//             if(pyear%400==0||(pyear%4==0&&pyear%100!=0)){
//                 if(mon==2&&day>29) continue;
//             }else if(mon==2&&day>28) continue;
//             else if(mon==4||mon==6||mon==9||mon==11){
//                 if(day>30) continue;
//             }
//             p[cnt].y=pyear,p[cnt].m=mon,p[cnt].d=day;
//             cnt++;
//         }
//     }
// }
//第二种用set的方法
// int i,year,mon,day,cnt;
// struct node{
//     int y,m,d;

//     bool operator==(node &n){
//         return (y==n.y&&m==n.m&&d==n.d);
//     }
    
//     bool operator<(node &n2){
//         if(y!=n2.y) return y<n2.y;
//         if(m!=n2.m) return m<n2.m;
//         return d<n2.d;
//     }
//     bool operator>(node &n2){
//         if(y!=n2.y) return y>n2.y;
//         if(m!=n2.m) return m>n2.m;
//         return d>n2.d;
//     }
// };
// bool tmp(node n1,node n2){
//         if(n1.y!=n2.y) return n1.y<n2.y;
//         if(n1.m!=n2.m) return n1.m<n2.m;
//         return n1.d<n2.d;
//     }
// set<node> p;
// vector<node> pp;
// bool node::operator<(node n1,node n2){
//         if(n1.y!=n2.y) return n1.y<n2.y;
//         if(n1.m!=n2.m) return n1.m<n2.m;
//         return n1.d<n2.d;
//     }
// bool node::operator>(node n1,node n2){
//         if(n1.y!=n2.y) return n1.y>n2.y;
//         if(n1.m!=n2.m) return n1.m>n2.m;
//         return n1.d>n2.d;
//     }

// void check(int year,int mon,int day){
//     int pyear;
//     node n;
//     if(mon>12||mon<1||day>31||day<1) return;
//     for(int i=0;i<2;i++){
//         pyear=year+1900+i*100;
//         if(pyear<=2059&&pyear>=1960){
//             if(pyear%400==0||(pyear%4==0&&pyear%100!=0)){
//                 if(mon==2&&day>29) continue;
//             }else if(mon==2&&day>28) continue;

//             if(mon==4||mon==6||mon==9||mon==11){
//                 if(day>30) continue;
//             }
//             n.y=pyear,n.m=mon,n.d=day;
//             // pp.push_back(n);
//             p.insert(n);
//         }
//     }
// }


// 08

// int gcd(int a,int b){
//     if(b == 0) return a;
//     return gcd(b,a%b);
// }
// int arr[110],n;
// const int N = 10010;
// bool bk[N];
    
//09
// int n,k,i,j,w,h,mid,Left,Right;
// struct ch{
//     int wi,hi;
// } chs[100004];
// bool tmp(ch c1,ch c2){
//     if(c1.wi!=c2.wi)
//         return c1.wi<c2.wi;
//     return c1.hi<c2.hi;
// }
// int num(int p){
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=(chs[i].hi/p)*(chs[i].wi/p);
//         if(sum>k) break;
//     }
//     return sum;
// }

int main(){
    //07
    // while(scanf("%d/%d/%d",&year,&mon,&day)!=EOF){
    //     memset(p,0,sizeof(p));
    //     cnt=0;
    //     check(year,mon,day);
    //     check(day,year,mon);
    //     check(day,mon,year);
    //     sort(p,p+cnt,tem);
    //     ly=p[0].y,lm=p[0].m,ld=p[0].d;
    //     printf("%d-",p[0].y);
    //     if(p[0].m<10) printf("0%d-",p[0].m);
    //     else printf("%d-",p[0].m);
    //     if(p[0].d<10) printf("0%d\n",p[0].d);
    //     else printf("%d\n",p[0].d);
    //     for(i=1;i<cnt;i++){
    //         if(p[i].y==ly&&p[i].m==lm&&p[i].d==ld){
    //             continue;
    //         }
    //         ly=p[i].y,lm=p[i].m,ld=p[i].d;
    //         printf("%d-",p[i].y);
    //         if(p[i].m<10) printf("0%d-",p[i].m);
    //         else printf("%d-",p[i].m);
    //         if(p[i].d<10) printf("0%d\n",p[i].d);
    //         else printf("%d\n",p[i].d);
    //     }
    // }
    //第二种用set的方法
    // while(scanf("%d/%d/%d",&year,&mon,&day)!=EOF){
        //memset(pp,0,sizeof(pp));
        // cnt=0;
        // check(year,mon,day);
        // check(day,year,mon);
        // check(day,mon,year);
        //sort(pp.begin(),pp.end());
        //int tt=unique(pp.begin(),pp.end())-pp.begin();
        // for(i=1;i<tt;i++){
        //     printf("%d-%02d-%02d\n",pp[i].y,pp[i].m,pp[i].d);
        // }
    // }

    //08
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++)
        scanf("%d",&arr[i]);
    int g = arr[0];
    for(int i = 1 ; i < n ; i ++)
        g = gcd(g,arr[i]);
    if(g != 1)
    {
        printf("INF\n");
    }else{
        bk[0] = true;
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j + arr[i] < N ; j ++)
                if(bk[j]) bk[j+arr[i]]= true;
        }
        int count = 0;
        for(int i = N-1 ; i >= 0 ; i --){
            if(bk[i] == false) count++;
        }
        printf("%d\n",count);
    }
    return 0;
    //09
    
/*
10 10
4 7
8 6
4 6
7 3
10 2
3 8
1 10
4 7
1 7
3 7

10 10
10 10
10 10
10 10
10 10
10 10
10 10
10 10
10 10
10 10
*/
//     cin>>n>>k;
//         for(i=0;i<n;i++){
//             cin>>w>>h;
//             chs[i].wi=max(w,h);
//             chs[i].hi=min(w,h);
//         }
//         Left=1,Right=100000;
//         while(Left<Right-1){
//             mid=(Left+Right)>>1;
//             j=num(mid);
//             if(j>=k){
//                 Left=mid;
//             }else if(j<k){
//                 Right=mid;
//             }
//         }
//         cout<<Left<<endl;
    
//     system("pause");
//     return 0;
// }
//10
const int N=100004;
int n,k,t,cnt[N],sum[N];
    while(cin >> n >> k)
        {
            memset(sum, 0, sizeof(sum));
            memset(cnt, 0, sizeof(cnt));
            ll ans = 0;
            for(int i = 1; i <= n; i++)
            {
                ll t;
                scanf("%lld", &t);
                sum[i] = (sum[i-1]+t)%k;
                ans += cnt[sum[i]];
                cnt[sum[i]]++;
            }
            printf("%lld\n", ans+cnt[0]);
        }

    system("pause");
    return 0;
}