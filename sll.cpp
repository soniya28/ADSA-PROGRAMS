/*To implement the singly linked list*/
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
}*first=NULL;

struct node *create()
{
	int x;
	struct node*temp;
	temp=new node;
	cout<<"Enter the data:";
	cin>>x;
	temp->data=x;
	temp->next=NULL;
	return temp;
}

void start()
{
	struct node*temp;
	temp=first;
	if(temp==NULL)
	{
		first=create();	
	}
	else
	{
		struct node*sec;
		sec=create();
		sec->next=first;
		first=sec;
	}
}

void last()
{
	struct node*temp;
	temp=first;
	if(temp==NULL)
	{
		first=create();	
	}
	else
	{
		struct node *sec;
		sec=create();
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=sec;
	}
}

void mid()
{
	int  n;
	struct node*temp;
	temp=first;
	if(temp==NULL)
	{
		first=create();	
	}
	else
	{
		struct node *sec;
		sec=create();
		cout<<"Enter the position:";
		cin>>n;
		struct node *prev;
		for(int i=1;i<n;i++||temp!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=sec;
		sec->next=temp;
	}
}

void delet()
{
	struct node *temp;
	temp=first;
	if(first==NULL)
	{
		cout<<"List is empty!!";
	}
	else
	{	
		first=first->next;
		delete temp;
	}
}

void del()
{
	struct node *temp;
	temp=first;
	struct node *prev;
	prev=temp;
	if(first==NULL)
	{
		cout<<"List is empty!!";
	}
	else
	{
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	delete temp;
	}

}

void delm()
{
	struct node *temp;
	temp=first;
	int n,flag=0;
	struct node *prev;
	if(first==NULL)
	{
		cout<<"List is empty!!";
	}
	else
	{
	cout<<"Enter the element:";
	cin>>n;
	while(temp!=NULL)
	{
	if(temp->data==n)
	{
		flag=1;
		prev->next=temp->next;
		delete temp;
	}
	prev=temp;
	temp=temp->next;
	}
	}
	if(flag==0)
		cout<<"Element not found!!";
}

void display()
{
	struct node*temp;
	temp=first;
	while(temp!=NULL)
	{
		cout<<temp->data;
		cout<<" ";
		temp=temp->next;
	}	

}
int main()
{
	int ch;
	cout<<"Singly linked list operation\n";
	while(1)
	
	{
	cout<<"1.Insert at first\n2.Insert at last\n3.Insert at middle\n4.Delete at first\n5.Delete at last\n6.Delete at middle\n7.exit\n8.Display\nEnter your choice:";	
	cin>>ch;
	switch(ch)
	{
	case 1:start();
	break;
	case 2:last();
	break;
	case 3:mid();
	break;
	case 4:delet();
	break;
	case 5:del();
	break;
	case 6:delm();
	break;
	case 7:
	return 0;
	break;
	case 8:display();
	break;
	default:
	cout<<"Wrong choice!!";
	} 
	}
	return 0; 
}

