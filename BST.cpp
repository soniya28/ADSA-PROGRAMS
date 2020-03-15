#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};	

struct node *create(struct node *newnode,int data)
{
	newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node *insert(struct node *root,int data)
{
	if(root==NULL)
	{
	root=create(root,data);	
	}
	else if(data<=root->data)
	{
	root->left=insert(root->left,data);
	}
	else
	{
	root->right=insert(root->right,data);
	}
	return root;
}

void inorder(struct node*root)
{
	if(root==NULL)
		return ;
	else
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int min(struct node *root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL)
		return root->data;
	else if(root->left->data<=root->data)
		min(root->left);
	
}

void swap(struct node *root)
{
	if(root==NULL)
		return;
	else 
	{
	swap(root->left);
	swap(root->right);
	struct node *temp;
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	}
}

struct node *search(struct node *root,int key)
{
	if(root==NULL)
	{
	return NULL;
	}
	else
	{
	if(root->data==key)
	{
		return root;
	}
	if(key<root->data)
		return search(root->left,key);
	if(key>root->data)	
		return search(root->right,key);
	}
}


int main()
{
	struct node *root,*p;
	root=NULL;
	int arr[]={12,9,6,4,46,34};
	int key,ch,no;	
	for(int i=0;i<6;i++)
	{	
	root=insert(root,arr[i]);
	}
	while(1)
	{
	cout<<"\n1.Insert\n2.MIN ELEMENT\n3.SEARCH ELEMENT\n4.INORDER SEQUENCE\n5.SWAPPING FUNCTION\n6.EXIT\nEnter your choice:";
	cin>>ch;
	switch(ch)
	{
	case 1:cout<<"\nEnter the number:";
		cin>>no;
		root=insert(root,no);
	break;
	case 2:	
		int num;
		num=min(root);
		if(num==0)
			cout<<"Tree is empty";
		else
			cout<<"Minimum node in the BST is "<<num;
	break;
	case 3:cout<<"Enter the key:";
		cin>>key;
		p=search(root,key);
		if(p==NULL)		
			cout<<"Not found ";
		else
			cout<<"Found";
	break;
	case 4:
			inorder(root);
	break;
	case 5:
		cout<<"\nSWAPPING DONE!!";
		swap(root);
		inorder(root);
		swap(root);	
	break;
	case 6:exit(1);
	break;
	default:
	cout<<"Wrong choice!!";
	}
	}
	return 0;
}
