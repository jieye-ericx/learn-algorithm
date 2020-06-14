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
#define SWAP(x,y,t) ((t) = (x),(x) = (y),(y) = (t))

int iszstr(char *str,char *zstr)
{
    char *p1=str,*p2=NULL,*pSave=NULL,flag;
    while(*p1)
    {
        if(*p1==zstr[0] && strlen(p1)>=strlen(zstr))
        {
            pSave=p1;
            p2=&zstr[0];
            flag=1;
            while(*p2)
            {
                if(*p1!=*p2)
                {
                    flag=0;
                    break;
                }
                p1++;
                p2++;
            }
            if(flag==1)
            {
                return pSave-&str[0];
            }
            else
                p1=pSave;
        }
        p1++;
    }
    return -1;
}
void reverse(char *a, char *b){
    int t = 0;
    /*比较的是下标，不是字符数据的值*/
    while (a < b){
        SWAP(*a, *b, t);
        a++;
        b--;
    }
}


bool nextPermutation(char list[]){
    char *pEnd = list + strlen(list)-1;
    if (list == pEnd)
        return false;
    
    char *p, *q, *pFind;
    p = pEnd;
    while (p != list) {
        q = p;
        --p;
        if (*p < *q){
            pFind = pEnd;
            while (*pFind <= *p)
                --pFind;
            int t = 0;
         SWAP(*pFind, *p, t);
            reverse(q, pEnd);
            return true;
        }
    }
    reverse(p, pEnd);
    return false;
}

int qSortCmp(const void *pa, const void *pb){
    return *(char*)pa - *(char*)pb;
}
int n,num,i,k,j;
char a[1024*1024],list1[8];
int main(){
    ios::sync_with_stdio(false);
    num=0;
    //
    int u=1;
    while(cin>>a>>n){
        for(i=0;i<n;i++){
            cin>>list1;
            qsort(list1, strlen(list1), sizeof(list1[0]),qSortCmp);
            do{
                if(iszstr(a,list1)>=0) num++;
                // cout<<a<<endl;
                // cout<<u++<<endl;
                // printf("\t%s\n",list1);
            } while (nextPermutation(list1));
        }
        cout<<num<<endl;
    }
    system("pause");
    return 0;
}
