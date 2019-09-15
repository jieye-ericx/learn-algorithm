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
string s[N];

bool cmp(string s1,string s2){
    return s1.size()<s2.size();
}
int len,i,n,j,len,t,flag,flag1;
string ss;
int main(){
    
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++) cin>>s[i];
        sort(s,s+n,cmp);
        for(len=s[0].size();len>0;len--){
            if(flag) break;
            for(i=0;i<s[0].size();i++){//表示起点
                if(i+len>s[0].size()) break;
                ss=s[0].substr(i,len);
                for(j=1;j<n;j++){
                    if(s[i].find(ss,0)==string::npos){
                        reverse(ss.begin(),ss.end());
                        if(s[i].find(ss,0)==string::npos){
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(!flag){
                cout<<len<<endl;
                break;
            }
        }
        if(!flag1) cout<<"0"<<endl;
    }
}