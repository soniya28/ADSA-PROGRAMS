#include<iostream>
using namespace std;

int Mat[10][10],n,e;

struct node
{
	int data;
	node *next;
}*head[10];
 
void adj_mat(int n,int e)
{
	int v1,v2;
	for (int i=1;i<=n;i++)
	{	
		for (int j=1;j<=n;j++)
		{
		Mat[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
	cout<<"Enter the vertices :";
	cin>>v1>>v2;
	Mat[v1][v2]=1;
	Mat[v2][v1]=1;
	}	
	for (int i=1;i<=n;i++)
	{	
		for (int j=1;j<=n;j++)
		{
		cout<<Mat[i][j];
		cout<<" ";
		}
		cout<<"\n";
	}
}

struct node *create(int data)
{
	node *newnode;
	newnode=new node;
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void add_edge(int v1, int v2)
{
	node *newnode1;
	newnode1=create(v2);
	if(head[v1]->next==NULL)
	{
		head[v1]->next=newnode1;
	}
	else
	{
	node *temp=head[v1];
	while(temp->next!=NULL)
	{
	temp=temp->next;
	}
	temp->next=newnode1;
	}
}

void adj_list(int n,int e)
{	
	int v1,v2;
	for(int i=1;i<=n;i++)
	{	
		head[i]=new node;
		head[i]->data=i;
		head[i]->next=NULL;
	}
	
	for(int i=0;i<e;i++)
	{
	cout<<"Enter the vertices :";	
	cin>>v1>>v2;
	add_edge(v1,v2);
	add_edge(v2,v1);
	}
}

void display()
{
	node *temp;
	for(int i=1;i<=n;i++)
	{
	temp=head[i];
	while(temp!=NULL)
	{
	cout<<temp->data;
	cout<<"->";
	temp=temp->next;
	}
	cout<<"NULL";
	cout<<"\n";
	}
}

int main()
{
	int choice;
	cout<<"Enter the no. of vertices and edges :";
	cin>>n>>e;
	while(1)
	{
	cout<<"1.Adjacency matrix\n2.Adjancency list\n3.Exit\nEnter your choice ";
	cin>>choice;
	switch(choice)
	{
	case 1:adj_mat(n,e);
	break;
	case 2:adj_list(n,e);
		display();
	break;
	case 3:exit(1);
	break;
	default:
	cout<<"Wrong choice!!";
	}
	}	
	return 0;
}
