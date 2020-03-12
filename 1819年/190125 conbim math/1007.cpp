#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
#define N 100
typedef long long LL;
const LL INF=(LL)1<<62;
LL ans,i,t,n,m,k;
int y;
bool prime[N];
set<int> p,pmn;
set<int>::iterator it;

//取出m和n的素因子
void isPrime(){
    memset(prime,true,sizeof(prime));
    int i,j,cnt;
    for(i=2;i<=N;i++){
        if(prime[i]){
            p.insert(i);
            for(j=i+i;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }
}
//得到m和n的素因子
void getP(int m,int n){
    for(set<int>::iterator it=p.begin();it!=p.end();it++){
        if(m && !(m%(*it)) ){//此素数是他的素因子
            pmn.insert(*it);
            while(!m%*it) m/=*it;
        }
        if(n && !(n%(*it)) ){//此素数是他的素因子
            pmn.insert(*it);
            while(!n%*it) n/=*it;
        }
        if( (!m)&&(!n) ) break;
    }
}
void dfs(LL k,LL t,LL s,LL n){
    if(k==pmn.size()){
        if(t&1) ans-=n/s;
        else ans+=n/s;
        return;
    }
    dfs(k+1,t,s,n);
    dfs(k+1,t+1,s*pmn[k],n);
}
LL bi(){
    LL l=1,r=INF,mid,ret;
    while(l<=r){
        mid=(l+r)>>1;
        ans=0;
        dfs(0,0,1,mid);
        if(ans>=k){
            ret=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ret;
}


int main(){
    y=1;
    isPrime();
    scanf("%d",&t);
    while(t--){//不加EOF会超时！！
        pmn.clear();
        //
        scanf("%lld%lld",&m,&n,&k);
        printf("Case %d: ",y++);
        getP(m,n);
        // for(it=p.begin();it!=p.end();it++){
        //     cout<<*it<<" ";
        // }cout<<"\n";
        // for(it=pmn.begin();it!=pmn.end();it++){
        //     cout<<*it<<endl;
        // }cout<<pmn.size();
        it=pmn.begin();
        cout<<*(it+3)<<endl;
        //printf("%lld",bi());
	}

    system("pause");
	return 0;
}

