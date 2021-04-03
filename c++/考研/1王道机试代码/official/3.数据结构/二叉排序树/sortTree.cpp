#include<stdio.h>
#include<string>
struct Node
{
	Node *lchild;
	Node *rchild;
	char c;
}Tree[50];
void PreOrder(Node *T)
{
	printf("%c",T->c);
	if(T->lchild!=NULL)
		PreOrder(T->lchild);
	if(T->rchild!=NULL)
		PreOrder(T->rchild);
}
void InOrder(Node *T)
{
	if(T->lchild!=NULL)
		InOrder(T->lchild);
	printf("%c",T->c);
	if(T->rchild!=NULL)
		InOrder(T->rchild);
}
void PostOrder(Node *T)
{
	if(T->lchild!=NULL)
		PostOrder(T->lchild);
	if(T->rchild!=NULL)
		PostOrder(T->rchild);
	printf("%c",T->c);
}
int loc;
Node *creat()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
Node *insert(Node *T,int x)
{
	if(T==NULL)
	{
		T=creat();
		T->c=x;
		return T;
	}
	else if(T->c<x)T->rchild=insert(T->rchild,x);
	else T->lchild=insert(T->rchild,x);
}
void main()
{
	int n;
	loc=0;
	Node *T=NULL;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			T=insert(T,x);
		}
		PreOrder(T);
		printf("\n");
		InOrder(T);
		printf("\n");
		PostOrder(T);
		printf("\n");
	}
}