/*(recursive functions) preorder,postorder,inorder traversal of tree*/ 
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};

struct node *create()
{
	struct node *newnode;
	newnode=new node;
	int x;
	cout<<"\nEnter the data(Enter -1 if it is NULL):";
	cin>>x;
	if(x==-1)
	{
	return 0;
	}
	newnode->data=x;
	cout<<"Enter the left node of "<<x;
	newnode->left=create();
	cout<<"Enter the right node of "<<x;
	newnode->right=create();
	return newnode;
	}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int main()
{
	struct node *root;
	root==NULL;
	root=create();
	cout<<"Inorder :";
	inorder(root);
	cout<<"\n";
	cout<<"preorder:";
	preorder(root);
	cout<<"\n";
	cout<<"postorder :";
	postorder(root);
	cout<<"\n";
	return 0;
}
