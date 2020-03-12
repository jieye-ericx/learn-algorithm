#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[25];
int n,averlen;
bool flag;
bool vis[25];
void DFS(int num,int len,int start)//成功边数,目前长度,开始位置
{
    if(flag)
        return ;
    if(num==4)
    {
        flag=true;
        return;
    }
    if(len==averlen)
    {
        DFS(num+1,0,0);
        if(flag)
            return ;
    }
    for(int i=start;i<n;i++)
    {
        if(!vis[i]&&len+a[i]<=averlen)
        {
            vis[i]=true;
            DFS(num,len+a[i],i+1);
            vis[i]=false;
            if(flag)
                return ;
 
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0,maxlen=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            if(a[i]>maxlen)
                maxlen=a[i];
        }
        averlen=sum/4;
        if(sum%4!=0||maxlen>averlen)
        {
            cout<<"no"<<endl;
            continue;
        }
        sort(a,a+n);
        memset(vis,false,sizeof(vis));
        flag=false;
        DFS(0,0,0);
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
