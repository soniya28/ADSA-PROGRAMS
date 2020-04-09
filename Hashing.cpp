/*================================================================================================
Problem statement:Implement all the functions of a dictionary(ADT) using hashing.
*Data: set of (key,value) pairs,keys are  mapped to values.keys must be comparable, keys must be unique.
*Standard operations:Insert(key,value),Find(key),Delete(key) .
================================================================================================*/

#include<iostream>
#define max 10
using namespace std;
int hash_tab[max],Temp[max];

void insert(int n,int x)
{
	int loc=0;
	loc=x%max;
	for(int i=0;i<max;i++)
	{
		if(Temp[loc]==0)
		{
			hash_tab[loc]=x;
			Temp[loc]=1;
			break;
		}
		loc=(loc+1)%max;
	}	
}

void search(int value)
{
	int flag=0;
	for(int i=0;i<max;i++)
	{
		if(hash_tab[i]==value&&Temp[i]==1)
		{
		flag=1;
		cout<<"Element is found !! at location "<<i;
		}
	}
	if(flag==0)
		cout<<"Element is not present!!";
}

void display()
{
	for(int i=0;i<max;i++)
	{
		cout<<i<<"-"<<hash_tab[i];
		cout<<"\n";
	}
}

void del(int value)
{
	int flag=0;
	for(int i=0;i<max;i++)
	{
		if(hash_tab[i]==value&&Temp[i]==1)
		{
		hash_tab[i]=0;
		Temp[i]=0;
		flag=1;
		}
	}
	if(flag==0)
		cout<<"Element is not present!!";
}

int main()
{	
	int choice;
	for(int i=0;i<max;i++)
		Temp[i]=0;
	for(int i=0;i<max;i++)
		hash_tab[i]=0;
	while(1)
	{
	cout<<"\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit\n Enter your choice ";
	cin>>choice;
	switch(choice)
	{
	case 1:
	int n,x;
	cout<<"Enter the no. of key-value pair :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cout<<"Enter the value :";
	cin>>x;
	insert(n,x);
	}
	break;
	case 2:
	display();
	break;
	case 3:
	int val;
	cout<<"\nEnter the value to be search :";
	cin>>val;
	search(val);
	break;
	case 4:
	int val1;
	cout<<"\nEnter the value to be deleted :";
	cin>>val1;
	del(val1);
	break;
	case 5:
	exit(1);
	break;
	default:
	cout<<"Wrong choice!!";
	}
	}
	return 0;
}
