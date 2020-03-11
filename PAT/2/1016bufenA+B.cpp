#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int A, B, DA, DB,na=0,nb=0;
int main() {
    while (cin>>A>>DA>>B>>DB)
    {
      while (A>0)
      {
        if(A%10==DA)
          na=na*10+1;
        A /= 10;
      }
      while (B > 0)
      {
        if (B % 10 == DB)
          nb=nb*10+1;
        B /= 10;
      }
      cout << (na * DA + nb * DB)<<endl;

    }
    
    return 0;
}
