/*Preorder,postorder,inorder traversal of binary tree using stack*/
#include<iostream>
using namespace std;
int top=-1;

struct node 
{
	int data;
	node *left,*right;
}*arr[20];

struct node *create()
{
	struct node *newnode;
	newnode=new node;
	int x;
	cout<<"Enter the data:";
	cin>>x;
	if(x==-1)
		return NULL;
	newnode->data=x;
	cout<<"Enter the left node of "<<x<<"\n";
	newnode->left=create();
	cout<<"Enter the right node of "<<x<<"\n";
	newnode->right=create();
	return newnode;
}

void push(node *temp)
{
	arr[++top]=temp;
}

struct node *pop()
{
	return arr[top--];
}

int isempty()
{
	if(top==-1)
		return 1;
	return 0;
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		while(1)
		{
		if(root!=NULL)
		{
			cout<<root->data<<" ";
			push(root);
			root=root->left;
		}
		else
		{
			if(isempty())
			{
				break;
			}
			root=pop();
			root=root->right;
		}
		}		
	}

}

void postorder(struct node *root)
{
struct node*current;
current=root;
struct node *temp;
while(current!=NULL||!isempty())
{
	if(current!=NULL)
	{
		push(current);
		current=current->left;
	}
	else
	{
		temp=arr[top]->right;
		if(temp==NULL)
		{
		temp=pop();
		cout<<temp->data;
		while(!isempty()&&temp==arr[top]->right)
		{
		temp=pop();
		cout<<temp->data<<" ";
		}	
		}
		else
		{
		current=temp;
		}

	}
}
}

void inorder(struct node*root)
{
	while(1)
	{
	if(root!=NULL)
	{
	push(root);
	root=root->left;
	} 
	else
	{
	if(isempty())
	{
	break;
	}
	root=pop();
	cout<<root->data<<" ";
	root=root->right;
	}
	}
	
}
int main()
{
	struct node *root;
	root=create();	
	cout<<"Inorder Traversal sequence:\n";
	inorder(root);	
	cout<<"preorder Traversal sequence:\n";
	preorder(root);
	cout<<"postorder Traversal sequence:\n";
	postorder(root);
	return 0;
}
