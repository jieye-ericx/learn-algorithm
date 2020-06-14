#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
struct student
{
  int id, ds, cs,lev;
};

student stus[100004];

bool tmp(student s1,student s2){
  if(s1.lev!=s2.lev)
    return s1.lev < s2.lev;
  if((s1.cs+s1.ds)!=(s2.cs+s2.ds))
    return (s1.cs + s1.ds) > (s2.cs + s2.ds);
  if(s1.ds!=s2.ds)
    return s1.ds > s2.ds;
  return s1.id < s2.id;
}
int nid, nds, ncs;
int main()
{
  int N, L, H,cnt=0;
  while (cin >> N >> L >> H)
  {
    for (int i = 0; i < N; i++)
    {
      cin >> nid >> nds >> ncs;
      if (nds >= H && ncs >= H)
      {
        stus[cnt].cs = ncs;
        stus[cnt].ds = nds;
        stus[cnt].id = nid;
        stus[cnt].lev = 1;
        cnt++;
      }
      else if (nds >= H &&ncs>=L)
      { //得胜才
        stus[cnt].cs = ncs;
        stus[cnt].ds = nds;
        stus[cnt].id = nid;
        stus[cnt].lev = 2;
        cnt++;
      }
      else if (nds >= ncs && ncs >= L)
      { //才德兼亡”但尚有“德胜才”
        stus[cnt].cs = ncs;
        stus[cnt].ds = nds;
        stus[cnt].id = nid;
        stus[cnt].lev = 3;
        cnt++;
      }
      else if (nds >= L && ncs >= L)
      {
        stus[cnt].cs = ncs;
        stus[cnt].ds = nds;
        stus[cnt].id = nid;
        stus[cnt].lev = 4;
        cnt++;
      }
      else
      {
      }
    }
    stus[cnt].lev = 100;
    stus[cnt + 1].lev = 100;
    // cnt--;
    sort(stus, stus + cnt, tmp);
      cout << cnt << "\n";
    for (int i = 0; i < cnt;i++){
      cout << stus[i].id << " " << stus[i].ds << " " << stus[i].cs << "\n";
    }
  }

  return 0;
}
