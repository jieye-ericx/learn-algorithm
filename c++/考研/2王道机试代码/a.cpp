void init()
{
  for (int i = 0; i < 1002; i++)
  {
    father[i] = i;
    hei[i] = 0;
  }
}
int fa(int x)
{
  if (x != father[x])
  {
    father[x] = fa(father[x]);
  }
  return father[x];
}
void uni(int x, int y)
{
  x = fa(x);
  y = fa(y);
  if (x != y)
  {
    if (hei[x] < hei[y])
    {
      father[x] = y;
    }
    else if (hei[x] > hei[y])
    {
      father[y] = x;
    }
    else
    {
      father[x] = y;
      hei[y]++;
    }
  }