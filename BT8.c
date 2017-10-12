#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{
 struct node *lchild;
 int data;
 struct node *rchild;
};

struct node *create()
{
 struct node *ptr;
 int val;
 printf("\nENTER DATA : ");
 scanf("%d",&val);
 
 if(val==-1)
  return NULL;
 
 
 ptr=(struct node *)malloc(sizeof(struct node));

 ptr->data=val;
 
 printf("\nLEFT CHILD OF %d:-",val);
 ptr->lchild=create();
 printf("\nRIGHT CHILD OF %d:-",val);
 ptr->rchild=create();
 
 return ptr;
}

void inorder(struct node *root)
{
 struct node *stack[100];
int top=-1,val;
struct node *curr=root;

printf("\nENTER NUMBER : ");
scanf("%d",&val);

while(curr!=NULL || top!=-1)
{

	if(curr!=NULL)
	{

	if(curr->data==val)
	{
		if(curr->lchild==NULL && curr->rchild==NULL)
		count=0;
		else if(curr->lchild!=NULL && curr->rchild==NULL)
		count=1;
		else if(curr->lchild==NULL && curr->rchild!=NULL)
		count=1;
		else
		count=2;
				
	}
	
		top++;
		stack[top]=curr;
		curr=curr->lchild;
	}
	else
	{
		curr=stack[top];
		printf(" %d ",curr->data);
		top--;
		curr=curr->rchild;
	}
	
}
}

main()
{
 struct node *root;
 printf("\nCREATE BINARY TREE...\n");
 root=create();
 printf("\nINORDER  ITERATIVE: \n");
 inorder(root);
  printf("\n DEGREE: %d",count);
}
