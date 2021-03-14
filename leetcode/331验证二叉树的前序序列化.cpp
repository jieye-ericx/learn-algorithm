#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main()
{

    return 0;
}
bool isValidSerialization(string preorder)
{
    int a, slot = 1;
    for (int i = 0; i < preorder.length(); i++)
    {
        if (preorder[i] == ',')
            continue;
        if (preorder[i] == '#')
            slot--;
        else
        {
            while (preorder[i] != ',') //结点值不一定是个位数
            {
                i++;
            }
            slot++;
            // slots = slots - 1 + 2
        }
        if (slot <= 0)
        {
            return i == preorder.length() - 1;
        }
    }
    return slot == 0;
}