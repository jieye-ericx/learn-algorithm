#include <iostream>
#include <vector>
using namespace std;
int GetNumberOfK(vector<int>, int);

int main()
{
  cout << "21321";
  vector<int> a = {1, 2, 3, 4, 5, 5, 5, 6, 7};
  cout << GetNumberOfK(a, 5);
  return 0;
}

int GetNumberOfK(vector<int> data, int k)
{
  int le = 0, ri = data.size() - 1;
  int mid = (le + ri) / 2;
  cout << mid;
  while (data[mid] != k)
  {
    if (data[mid] > k)
    {
      ri = mid;
      mid = (ri + le) / 2;
    }
    else if (data[mid] < k)
    {
      le = mid;
      mid = (ri + le) / 2;
    }
  }
  int cnt = 1;
  for (int i = mid + 1; i < data.size(); i++)
  {
    if (data[i] == k)
      cnt++;
    else
      break;
  }
  for (int i = mid - 1; i >= 0; i--)
  {
    if (data[i] == k)
      cnt++;
    else
      break;
  }
  return cnt;
}