/*
0808 高精度运算
两种解决方案：数字数组 数字链表
1.——————————————————————————————————
#define MAXDIGITS 100;
#define PLUS 1
#define MINUS -1
typedef struct{
char digits[MAXDIGITS];
int signbit;//1正-1负 
int lastdigit;//记录位数 
}bignum;
*/ 
#include <windows.h>
#include <iostream>
#include <ostream> 
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define MAXDIGITS 100
#define PLUS 1
#define MINUS -1
class bignum{
		char digits[MAXDIGITS];
		int signbit;//1正-1负 
		int lastdigit;//记录位数 
	public:
		bignum();
		bignum(int k); 
		bignum(char *s);
		bignum operator +( bignum &a);
		bignum operator -( bignum &a);
		friend int compare(const bignum &,const bignum &);
		friend ostream & operator<<(ostream &cout,bignum &bn);
		void digit_left_move(int d){
			int i;
			for(i=lastdigit;i>=0;i--)
			digits[i+d]=digits[i];
			for(i=0;i<d;i++)
				digits[i]='0';
		}

		void zero_justfy(){
			int i;
			for(i=lastdigit;i>=0;i--){
				if(digits[i]=='0')
					lastdigit --;
				else 
					break;
			}
		}
		
};
bignum bignum::operator -( bignum &a){
	bignum c;int i,v;
	if(signbit==MINUS || a.signbit == MINUS){
		a.signbit = -1 * a.signbit;
		c=*this+a;
		a.signbit = -1 * a.signbit;
		} else {
			if(compare(*this,a)==PLUS){
				c=a-*this;
				c.signbit=MINUS;
				return c;
			}
			c.lastdigit=max(lastdigit,a.lastdigit);
			c.signbit=PLUS;
			int borrow=0;
			for(i=0;i<c.lastdigit;i++){
				v=digits[i]-a.digits[i]-borrow;
				if(v<0){
					v+=10;
					borrow=1;
				} else{
					borrow=0;
				}
				c.digits[i]=v+'0';
			}
		}
		c.zero_justfy();
		return c;
}
bignum bignum::operator +( bignum &a){
	bignum c;
	int i,t,carry=0;
	if(signbit==a.signbit){
		c.signbit=signbit;
		c.lastdigit=max(lastdigit,a.lastdigit)+1;
		for(i=0;i<c.lastdigit;i++){
			t = digits[i] - '0' + a.digits[i] - '0' + carry;
			c.digits[i]=t%10+'0';
			carry=t/10;
		}
		c.zero_justfy(); 
		return c;
	} else{
		if(signbit==MINUS){
			signbit=PLUS;
			//c=a-*this;
			signbit=MINUS;
		} else{
			a.signbit=PLUS;
		//	c=*this-a;
			a.signbit=MINUS;
		}
	}
	
}

int compare(const bignum &a,const bignum &b){
	if( (a.signbit==-1) && (b.signbit==1) ) return 1;
	if( (a.signbit==1) && (b.signbit==-1) ) return 1;
	
	if( b.lastdigit>a.lastdigit ) return -1*a.signbit;
}

bignum::bignum(){
	lastdigit=0;
	digits[0]='0';
	signbit=1;
	for(int i=0;i<MAXDIGITS;i++)
		digits[i]='0';
}

bignum::bignum(int k){
	bignum();
	lastdigit=-1;
	while(k!=0){
		digits[++lastdigit]=k%10+'0';
		k/=10;
	}
} 


bignum::bignum(char *s){
	bignum();
	int i;
	if(s[0]=='-'){
		signbit=-1;
		lastdigit=strlen(s)-2;
		i=1;
	}
	else{
		signbit=1;
		lastdigit=strlen(s)-1;
		i=0; 
	} 
	lastdigit=strlen(s)-1;
	for(;i<=lastdigit;i++){
		digits[i]=s[lastdigit-i];
	}
} 

ostream & operator<<(ostream &cout,bignum &bn){
	int i;			
	if(bn.signbit==MINUS) cout<<"-";
	for(i=bn.lastdigit;i>=0;i--){
		cout<<bn.digits[i];
	}
}

int main(){
	//system("color 70");
	ios::sync_with_stdio(false);
	bignum bn0("123");
	cout<<bn0<<endl;
	bignum bn1(123);
	cout<<bn1<<endl;
	
	bignum bn2=bn0+bn1;
	bignum bn3=bn0-bn1;
	
	cout<<bn2<<endl<<bn3<<endl;
	return 0;
}


