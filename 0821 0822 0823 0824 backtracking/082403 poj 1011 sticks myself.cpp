//Description POJ1011
//乔治拿来一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过50个长度单位。
//然后他又想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。
//请你设计一个程序，帮助乔治计算木棒的可能最小长度。每一节木棍的长度都用大于零的整数表示。
//Input
//输入包含多组数据，每组数据包括两行。第一行是一个不超过64的整数，表示砍断之后共有多少节木棍。
//第二行是截断以后，所得到的各节木棍的长度。在最后一组数据之后，是一个零。
//Output
//为每组数据，分别输出原始木棒的可能最小长度，每组数据占一行。
//Sample Input 
//9 
//5 2 1 5 2 1 5 2 1 
//4 
//1 2 3 4 
//0
//Sample Output 
//6 
//5
/////加入greater<int>（）后顺序为由大到小
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
#define N 70
int sticks[N],vis[N];//一个存木棍，一个标记是否使用
int n,i,len,num,sum;//len是合并后每根木棍的长度，num是合并后的木棍数目

int dfs(int cur,int k,int cnt){//cur是正在合并的木棍的长度，k是木棍的下标，cnt是合并好的木棍数
    if(cnt==num) return 1;//完成要求的情况
    if(cur==len) return dfs(0,0,cnt+1);//合并好一根木棍的情况
    int i,pre=0;//i为木棍下标，pre保存重复木棍
    for(i=k;i<n;i++){
        if(!vis[i] && sticks[i]+cur<=len && sticks[i]!=pre){
        /*
        这里要解释的是sticks[i]!=pre，假设有几根木棍是5 5 5 2，这时，若确定第一根已经不满足条件了，
        后面两根长度为5的木棍也没有必要去试了，所以跳过就好了。
        这里可能会有小伙伴理解为这样会导致不能正确的加入两根相同的木棍（我最初就这样想的。。），
        比如5 2 5 1 1，会理解为最后一个1加不上了。其实当第一个1符合条件的情况下，函数会再次调用，
        所以新调用的函数了pre又是0了，所以这个条件完美排除了第一根就不符合条件的情况，
        并没有影响重复长度木棍第一根符合要求的情况。
        */
        vis[i]=1;
        pre=sticks[i];
        if(dfs(sticks[i]+cur,i+1,cnt)) break;
        /*
        这里dfs的返回值若为1，说明已经完成题目要求了（前面只有cnt==num才返回1），所以可以跳出循环，
        这会影响后面if语句的判断，若是跳出的，说明找到了，若不是跳出，正常结束循环，说明没有找到。
        */
        vis[i]=0;
        if(!k) return 0;
        /*
        这个剪枝也很巧妙，它是考虑了，当我每合并一个新木棍时，第一根木棍是很特殊的，
        我们每次从前往后挑选木棍时，总是选没用过且长度符合要求的，这也就意味着，
        当我们选中了第一根木棍时，它的长度是符合要求的，这一根是一定要用的
        （无论对于哪个合成的木棍，这根都会是作为第一根用，这里大家好好琢磨一下），
        所以若前面的if语句没执行，就会执行这一句，而且满足k==0，
        说明后面的木棍都没法和这第一根木棍组成新木棍了，所以可以直接退出了.
        */
        }
    }
    if(i==n) return 0;
    else return 1;
}
int main(){
    while(scanf("%d",&n)!=EOF,n){
        sum=0;//总长度
        for(i=0;i<n;i++){
            scanf("%d",&sticks[i]);
            sum+=sticks[i];
        }
        sort(sticks,sticks+n,greater<int>());
        //注意要从大到小排序，因为合并后木棍的长度一定大于原来最长的
        for(len=sticks[0];len<=sum/2;len++){//剪枝，从最大的长度开始枚举，这里大于sum/2归并为了合成一根木棍的情况
            if(sum%len==0){
                num=sum/len;
                memset(vis,0,sizeof(vis));
                if(dfs(0,0,0)){break;}
            }
        }
        if(len>sum/2){//一根木棍的情况
            printf("%d\n",sum);
        }else{
            printf("%d\n",len);
        }
    }
    
    //system("pause");
    return 0;
}
