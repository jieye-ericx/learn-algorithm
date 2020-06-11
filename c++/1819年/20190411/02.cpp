#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
double t1,t2,m1,m2,mtime,v1,v2;
int n,m,y,t,i;
int main(){
    cin>>t;
    while(t--){
        t1=0,t2=0,m1=0,m2=0,mtime=0;
        cin>>n>>m>>y;
        v1=n/(n+m);
        v2=m/(n+m);
        for(i=1;i<=n;i++){
            cin>>m1;
            t1+=m1;
        }
        t1*=v1;
        for(i=1;i<=n;i++){
            cin>>m2;
            t2+=m2;
        }
        t2*=v2;
        if (t1>(double)y) {
            cout<<"Wait"<<endl;
            /* code */
        }else{
            i=0;

            while(t1*v1+t2*v2*i<y){
                i++;
                if(i>100) break;
            }
            if(i>99) cout<<"Go"<<endl;
            else cout<<"Wait"<<endl;
        }
        
        
    }

    system("pause");
    return 0;
}
// (r-l+1)*a[l]+(r-l)*a[l+1]+...+2*a[r-1]+1*a[r]