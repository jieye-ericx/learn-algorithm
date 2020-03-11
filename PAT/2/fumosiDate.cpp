#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
string s1, s2, s3, s4;
string day;
int hour, minute;
char sss[]= {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'};
int main()
{
    while (cin >> s1 >> s2 >> s3 >> s4)
    {
        bool flag = false;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == s2[i] && (!flag))
            {
                if (s1[i] == 'A' || s1[i] == 'B' || s1[i] == 'C' || s1[i] == 'D' || s1[i] == 'E' || s1[i] == 'F' || s1[i] == 'G')
                {
                    flag = true;
                    if (s1[i] == 'A')
                    {
                        day = "MON";
                    }
                    if (s1[i] == 'B')
                    {
                        day = "TUE";
                    }
                    if (s1[i] == 'C')
                    {
                        day = "WEN";
                    }
                    if (s1[i] == 'D')
                    {
                        day = "THU";
                    }
                    if (s1[i] == 'E')
                    {
                        day = "FRI";
                    }
                    if (s1[i] == 'F')
                    {
                        day = "SAT";
                    }
                    if (s1[i] == 'G')
                    {
                        day = "SUN";
                    }
                }
            }
            else if (s1[i] == s2[i] && (flag))
            {
                int j;
                for (j = 0; j < 24; j++)
                {
                    if (sss[j] == s1[i])
                    {
                        break;
                    }
                }
                hour = j;
                break;
            }
        }
        for (int i = 0; i < s3.length(); i++)
        {
            if (s3[i] == s4[i])
            {
                if (s3[i] < (char)65 || s3[i] > (char)122)
                {
                    continue;
                }
                if (s3[i] > (char)90 && s3[i] < (char)97)
                {
                    continue;
                }
                minute = i;
                break;
            }
        }
        cout << day << " ";
        if (hour < 10)
            cout << "0" << hour;
        else
        {
            cout << hour;
        }
        cout << ":";
        if (minute < 10)
            cout << "0" << minute;
        else
            cout << minute;
        cout << endl;
    }

    return 0;
}
