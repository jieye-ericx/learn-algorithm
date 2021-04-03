// #include <cmath>
// #include <iostream>
// #include <cstring>
// #include <string>
// #include <algorithm>
// #include <cstdio>
// #include <vector>
// #include <set>
// #include <map>
// #include <functional>
// using namespace std;

// string ADD,SUB,DIV,MOD,MUL,EQUAL,CLEAR,CHANGE,NUM;
// string nowstr;

// int main(){
//     while(cin>>n){
//         for(i=0;i<n;i++){

//         }
//     }
//     system("pause");
//     return 0;
// }

#include<iostream>
#include<cmath>
#include<string>
using namespace std;
long long DCHANGE(string s, int Ary)
{
	long long t = 0,PO = 1;
	for (int i = s.length() - 1, j = 0; i >= 0; i--, j++)
	{
		if (isdigit(s[i]))
			t += (s[i] - '0')*PO;
		else
			t += (s[i] - 'A' + 10)*PO;
 
		PO = PO * Ary;
	}
	return t;
}
string RCHANGE(long long t, int k)
{
	string num;
 
	if(t==0)num="0";
	while (t)
	{
		char c;
		if (t%k < 10)
			c = t % k + '0';
		else
			c = (t % k - 10) + 'A';
 
		num = c + num;
 
		t = t / k;
	}
	return num;
}
class Calculator
{
public:
	Calculator() { Ary=10; }
	void NUM(string s) { num = s; }
	void CHANGE(int k) {
		num = RCHANGE(DCHANGE(num, Ary), k);
		Ary = k;
	}
	//进行算术计算时先转换成十进制计算（DCHANGE)再换成对应的k（ary）进制
	void ADD(string s) {
		long long sum = DCHANGE(num, Ary) + DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void SUB(string s) {
		long long sum = DCHANGE(num, Ary) - DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void MUL(string s) {
		long long sum = DCHANGE(num, Ary) * DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void DIV(string s) {
		long long sum = DCHANGE(num, Ary) / DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void MOD(string s) {
		long long sum = DCHANGE(num, Ary) % DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void EQUAL() { cout << num << endl; }
	void CLEAR() { num.clear();}
private:
	int Ary;	//进制
	string num;
};
int main()
{
	int N;
	cin >> N;
 
	Calculator ST;
 
	int flag;
	for(int i=0;i<N;i++)
	{
		int t;
		string s,st;
		cin >> s;
		if (s == "CLEAR")
        {
            ST.CLEAR();
            flag = 0;
        }
		else if (s == "NUM")
		{
			cin >> st;
			switch(flag)
			{
            case 0:ST.NUM(st);break;
            case 1:ST.ADD(st);break;
            case 2:ST.SUB(st);break;
            case 3:ST.MUL(st);break;
            case 4:ST.DIV(st);break;
            case 5:ST.MOD(st);break;
			}
		}
		else if (s == "CHANGE")
		{
			cin >> t;
			ST.CHANGE(t);
		}
		else if (s == "ADD")
		    flag = 1;
		else if (s == "SUB")
		    flag = 2;
		else if (s == "MUL")
            flag = 3;
		else if (s == "DIV")
            flag = 4;
		else if (s == "MOD")
			flag = 5;
		else if (s == "EQUAL")
			ST.EQUAL();
	}
	system("pause");
	return 0;
}
// --------------------- 
// 作者：TOBEALISTENER 
// 来源：CSDN 
// 原文：https://blog.csdn.net/TOBEALISTENNER/article/details/80609226 
// 版权声明：本文为博主原创文章，转载请附上博文链接！
// 问题描述
// 　　模拟程序型计算器，依次输入指令，可能包含的指令有


// 　　1. 数字：'NUM X'，X为一个只包含大写字母和数字的字符串，表示一个当前进制的数
// 　　2. 运算指令：'ADD','SUB','MUL','DIV','MOD'，分别表示加减乘，除法取商，除法取余
// 　　3. 进制转换指令：'CHANGE K'，将当前进制转换为K进制(2≤K≤36)
// 　　4. 输出指令：'EQUAL'，以当前进制输出结果
// 　　5. 重置指令：'CLEAR'，清除当前数字


// 　　指令按照以下规则给出：
// 　　数字，运算指令不会连续给出，进制转换指令，输出指令，重置指令有可能连续给出
// 　　运算指令后出现的第一个数字，表示参与运算的数字。且在该运算指令和该数字中间不会出现运算指令和输出指令
// 　　重置指令后出现的第一个数字，表示基础值。且在重置指令和第一个数字中间不会出现运算指令和输出指令
// 　　进制转换指令可能出现在任何地方


// 　　运算过程中中间变量均为非负整数，且小于2^63。
// 　　以大写的'A'~'Z'表示10~35
// 输入格式
// 　　第1行：1个n，表示指令数量
// 　　第2..n+1行：每行给出一条指令。指令序列一定以'CLEAR'作为开始，并且满足指令规则
// 输出格式
// 　　依次给出每一次'EQUAL'得到的结果
// 样例输入
// 7
// CLEAR
// NUM 1024
// CHANGE 2
// ADD
// NUM 100000
// CHANGE 8
// EQUAL
// 样例输出
// 2040