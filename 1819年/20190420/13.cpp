#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
string str, substr;
int n;
int check(){
    int i=0,j=0;
    while(j!=substr.length()-1){    
        if(str[i]==substr[j]){
                i++,j++;
        }else{
            i++;
            if(i==str.length()-1) return 0;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> str ;
    cin>>n;
    while(n--){
        vector<int> next;
        cin>>substr;
        if(check()) cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
    }
    
    return 0;
}