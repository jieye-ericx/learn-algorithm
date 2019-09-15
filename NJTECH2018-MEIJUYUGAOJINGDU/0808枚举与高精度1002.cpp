#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long

using namespace std;

int main(){

    LL n;

    char st[20],anwser[10],b[10];

    while(~scanf("%lld %s",&n,st))

    {

        if(n==0&&(strcmp(st,"END")==0))

            break;

        memset(anwser,0,sizeof(anwser));     

        memset(b,0,sizeof(b));

        int len=strlen(st);

        LL ii,jj,kk,pp,qq;

        bool flag=true;

        for(int i=0;i<len;i++)

        {

            ii=st[i]-'A'+1;

            for(int j=0;j<len;j++)

            {

                if(j==i)

                    continue;

                jj=(st[j]-'A'+1)*(st[j]-'A'+1);

                for(int k=0;k<len;k++)

                {

                    if(k==i||k==j)

                        continue;

                    kk=(st[k]-'A'+1)*(st[k]-'A'+1)*(st[k]-'A'+1);

                    for(int p=0;p<len;p++)

                    {

                        if(p==i||p==j||p==k)

                            continue;

                        pp=(st[p]-'A'+1)*(st[p]-'A'+1)*(st[p]-'A'+1)*(st[p]-'A'+1);

                        for(int q=0;q<len;q++)

                        {

                            if(q==i||q==j||q==k||q==p)

                                continue;

                            qq=(st[q]-'A'+1)*(st[q]-'A'+1)*(st[q]-'A'+1)*(st[q]-'A'+1)*(st[q]-'A'+1);

                            LL sum;

                            sum=ii-jj+kk-pp+qq;

                            if(sum==n)

                            {

                                b[0]=st[i];

                                b[1]=st[j];

                                b[2]=st[k];

                                b[3]=st[p];

                                b[4]=st[q];

                                if(flag)

                                {

                                    strcpy(anwser,b);

                                    flag=false;

                                }

                                else

                                {

                                    if(strcmp(anwser,b)<0)

                                    {

                                        strcpy(anwser,b);

                                    }

                                }

                            }

 

                        }

                    }

                }

            }

        }

        if(flag)

        printf("no solution\n");

        else

            printf("%s\n",anwser);

    }

 

    return 0;

}

