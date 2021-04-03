#include<stdio.h>
#include<string>
struct Node
{
	Node *lchild;
	Node *rchild;
	int c;
}Tree[110];
int loc;
Node *creat()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
Node *Insert(Node *T,int x)
{
	if(T==NULL)
	{
		T=creat();
		T->c=x;
		return T;
	}
	else if(x<T->c)T->lchild=Insert(T->lchild,x);
	else if(x>T->c)T->rchild=Insert(T->rchild,x);
	return T;
}
int size1,size2;
char str1[25],str2[25];
int *size;
char *str;
void preOrder(Node *T)
{
	str[(*size)++]=T->c+'0';
	if(T->lchild!=NULL)preOrder(T->lchild);
	if(T->rchild!=NULL)preOrder(T->rchild);
}
void inOrder(Node *T)
{
	if(T->lchild!=NULL)inOrder(T->lchild);
	str[(*size)++]=T->c+'0';
	if(T->rchild!=NULL)inOrder(T->rchild);
}
void main()
{
	int n;
	char tmp[25];
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		loc=0;
		scanf("%s",&tmp);
		Node *T=NULL;
		for(int i=0;tmp[i]!=0;i++)
		{
			T=Insert(T,tmp[i]-'0');
		}
		size1=0;
		size=&size1;
		str=str1;
		preOrder(T);
		inOrder(T);
		str1[size1]=0;
		while(n--!=0)
		{
			scanf("%s",&tmp);
			{
				Node *T2=NULL;
				for(i=0;tmp[i]!=0;i++)
				{
					T2=Insert(T2,tmp[i]-'0');
				}
				size2=0;
				size=&size2;
				str=str2;
				preOrder(T2);
				inOrder(T2);
				str2[size2]=0;
			}
			puts(strcmp(str1,str2)==0?"NO":"YES");
		}
	}
}