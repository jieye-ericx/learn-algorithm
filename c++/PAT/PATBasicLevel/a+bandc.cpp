#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
long long int T, a, b, c;
int main() {
	cin >> T;
	for (int i = 1; i <= T;i++)
	{
		cin >> a >> b >> c;
		if(a+b>c){
			cout << "Case #" << i << ": true\n";
		}else{
			cout << "Case #" << i << ": false\n";
		}
	}
	return 0;
}
