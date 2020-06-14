// #include<iostream>
// #include<cstdio>
// #include<cmath>
// #include<algorithm>
// #include<cstring>
// #include<set>
// #include<vector>
// using namespace std;
// int b[4]={2,0,5,0};
// int t,i,flag,j;
// char a;
// int main(){
//     cin>>t;
//     cin.get();
//     while(t--){
//         flag=1;
//         i=0;
//         j=0;
//         while(scanf("%c",&a)){
//             if((a-'0')!=b[i]&&a!=10){
//                 flag=0;
//             }
//             if (a==10) {
//                 if(i!=0) flag=0;

//                 if(flag&&j) printf("Yes\n");
//                 else printf("No\n");
//                 break;
//             }
//             i=(i+1)%4;
//             j=1;
//         }
//     }
//     // system("pause");
//     return 0;
// }

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
int t,ret,flag,j;
char a;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        flag=4;
        ret=1;
        cin>>s;
        for(int i=0;i<s.length();i++){
            a=s[i];
            if(a=='2'&&flag==4) 
                flag=1;
            else if (a=='0'&&flag==1) 
                flag=2;
            else if (a=='5'&&flag==2) 
                flag=3;
            else if (a=='0'&&flag==3) 
                flag=4;
            else {
                ret=0;
                break;
            }
        }
        cout<<((ret==1&&flag==4)?"Yes":"No")<<endl;
    }
    // system("pause");
    return 0;
}