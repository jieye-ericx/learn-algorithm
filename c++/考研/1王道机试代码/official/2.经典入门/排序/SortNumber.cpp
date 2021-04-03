#include <stdio.h>
void main()
{
	int buf[100];
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &buf[i]);
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n - j - 1; k++)
			{
				if (buf[k] > buf[k + 1])
				{
					int tmp = buf[k];
					buf[k] = buf[k + 1];
					buf[k + 1] = tmp;
				}
			}
		}
		for (int m = 0; m < n; m++)
		{
			printf("%d ", buf[m]);
		}
		printf("\n");
	}
}