/*当输入为N时，如果Stan在能赢，则说明之前的一轮Ollie无论出多少都不能赢。
设当乘积为M且该Ollie发难（设Ollie出p）时,Stan有必赢的策略（不管Ollie出什么，Stan都出9）,
即9×M＜N,9×p×M≥N  p≥2）等价于M≥ceil（N / （2×8））    （ceil为向上取整）
下面证明如果Stan在ceil（N/18）时有必赢的策略，则
    9×ceil（N/18）＜N且18×ceil（N/18）≥N.
设N = 18×k + r （k≥1，0≤r＜18）代人上式即得。
（在10到18之间，Ollie必赢，可手工验证。）

接着验证若Stan在ceil（N/18）时必输，则Stan在N时亦必输。
只要Ollie出2，Stan即使出9也不能赢，Ollie接着出9，即赢。
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



