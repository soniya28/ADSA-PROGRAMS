/*=================================================================================
problem statement:Consider telephone book database of N clients .Make use of a hash 
table implemetation to quickly look up clients telephone number.
===================================================================================*/
#include<iostream>
#include<string>
#define max 200
using namespace std;
string name[max];
long int mob_no[max];
int Temp[max];

void insert(string x,long int mob)
{
	int loc=0,j=0;
	char c=x[j];
	loc=c%max;
	for(int i=0;i<max;i++)
	{
		if(Temp[loc]==0)
		{
			name[loc]=x;
			mob_no[loc]=mob;
			Temp[loc]=1;
			break;
		}
		loc=(loc+1)%max;
	}	
}

void search(string value)
{
	int flag=0;
	for(int i=0;i<max;i++)
	{
		if(name[i]==value&&Temp[i]==1)
		{
		flag=1;
		cout<<name[i]<<"-"<<mob_no[i];
		}
	}
	if(flag==0)
		cout<<"Telephone number is not present!!";
}

void display()
{
	for(int i=0;i<max;i++)
	{
		if(Temp[i]==1)
		{
		cout<<i<<"-"<<name[i]<<":"<<mob_no[i];
		cout<<"\n";
		}
	}
}

int main()
{	
	int choice;
	for(int i=0;i<max;i++)
		Temp[i]=0;
	for(int i=0;i<max;i++)
	{
		mob_no[i]=0;
	}	
	while(1)
	{
	cout<<"\n1.Insert\n2.Display\n3.Search\n4.Exit\n Enter your choice ";
	cin>>choice;
	switch(choice)
	{
	case 1:
	int n;
	long int mob;
	char name1[10];
	cout<<"Enter the no. of contacts added to the telephone directory:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cout<<"Enter the name :";
	cin>>name1;
	cout<<"Enter the mobile number :";
	cin>>mob;
	insert(name1,mob);
	}
	break;
	case 2:
	display();
	break;
	case 3:
	char val[10];
	cout<<"\nEnter the name to be search :";
	cin>>val;
	search(val);
	break;
	case 4:
	exit(1);
	break;
	default:
	cout<<"Wrong choice!!";
	}
	}
	return 0;
}
