/*������ΪNʱ�����Stan����Ӯ����˵��֮ǰ��һ��Ollie���۳����ٶ�����Ӯ��
�赱�˻�ΪM�Ҹ�Ollie���ѣ���Ollie��p��ʱ,Stan�б�Ӯ�Ĳ��ԣ�����Ollie��ʲô��Stan����9��,
��9��M��N,9��p��M��N  p��2���ȼ���M��ceil��N / ��2��8����    ��ceilΪ����ȡ����
����֤�����Stan��ceil��N/18��ʱ�б�Ӯ�Ĳ��ԣ���
    9��ceil��N/18����N��18��ceil��N/18����N.
��N = 18��k + r ��k��1��0��r��18��������ʽ���á�
����10��18֮�䣬Ollie��Ӯ�����ֹ���֤����

������֤��Stan��ceil��N/18��ʱ���䣬��Stan��Nʱ����䡣
ֻҪOllie��2��Stan��ʹ��9Ҳ����Ӯ��Ollie���ų�9����Ӯ��
*/
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define sd1(a) scanf("%d",&a)
#define slld1(a) scanf("%lld",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pd1(a) printf("%d\n",a)
#define plld1(a) printf("%lld\n",a)

long long n;

int judge(long long n){
	if(n<=2&&n<=9) return 1;
	if(n<2) return 0;
	if(n>9) return  judge(ceil(n/18.0));
}
int main(){
	//ios::sync_with_stdio(false);
	
	while(slld1(n)!=EOF){
		
		if(judge(n)) printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");


		

		
	}
	return 0;
}
# include <iostream>
# include <cmath>
using namespace std;

int StanWin(unsigned long int n)
{
    if (2<=n&&n<=9)
    {
        return 1;
    }
    if (n<2)
    {
        return 0;
    }
    if(n>9)
    {
        return StanWin(ceil(n/18.0));
    }
}

int main()
{
//    freopen("fjnu_1550.in","r",stdin);
    unsigned long int n;
    while (cin>>n)
    {
        if (StanWin(n))
            cout<<"Stan wins."<<endl;
        else
            cout<<"Ollie wins."<<endl;
    }
    return 0;
}



