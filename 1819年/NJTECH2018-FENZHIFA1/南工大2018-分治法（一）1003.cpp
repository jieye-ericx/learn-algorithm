
#include<stdio.h>

#include<iostream>

#include<algorithm>

#include<math.h>

#define xps 1e-12

using namespace std;

int main()

{

	long long l,m,n,o=1;

	while(cin>>l>>m>>n)

	{

	long long a[510],b[510],c[510],d[250010];

	for(int i=0;i<l;i++)//������������

	cin>>a[i];

	for(int i=0;i<m;i++)

	cin>>b[i];

	for(int i=0;i<n;i++)

	cin>>c[i];

	int k=0;

	for(int i=0;i<l;i++)

	for(int j=0;j<m;j++)

	d[k++]=a[i]+b[j];//ǰ��������������ӵõ�������

	sort(d,d+k);//��С��������

	int s;

	cin>>s;

	cout<<"Case "<<o++<<":"<<endl;//����ڼ�������ʵ��

	while(s--)

	{

		long long x;

		cin>>x;

		bool sign =false;

		for(int i=0;i<n;i++)//�����������������mid����ж�

		{

		int l=0,r=k-1;

		while(l<=r)

		{

			int mid=(l+r)>>1;

			if(d[mid]+c[i]==x)

			{

				sign=true;

				break;

			}

			else if(d[mid]+c[i]<x)

			{

				l=mid+1;

			}

			else

			r=mid-1;

		}

		if(sign)

		break;

		}

		if(sign)

		cout<<"YES"<<endl;

		else

		cout<<"NO"<<endl;

	}

	}

	return 0;

}
