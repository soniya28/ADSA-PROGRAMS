/*========================================================================================================================
problem statement:There are flight paths between cities.If there is a flight between city A and city b then there is an edge between the cities.The cost of the time that flight takes to reach city B from a or the amount of fuel used for the journey.Represent this as a graph
.The node can be represented by airport name of the city.Use adjacency list representation of the graph or use adjacency matrix representation of the graph.justify the storage representation used. 
===========================================================================================================================*/

#include<iostream>
using namespace std;
int n,e;
struct node
{
	char city;
	int distance;	
	node *next;
}*head[10];

struct node *create(char city,int data)
{
	node *newnode;
	newnode=new node;
	newnode->city=city;
	newnode->distance=data;
	newnode->next=NULL;
	return newnode;
}

void add_edge(char v1, char v2,int dis)
{
	for(int i=1;i<=n;i++)
	{
	if(head[i]->city==v1)
	{
	node *newnode1;
	newnode1=create(v2,dis);
	if(head[i]->next==NULL)
	{
		head[i]->next=newnode1;
	}
	else
	{
	node *temp=head[i];
	while(temp->next!=NULL)
	{
	temp=temp->next;
	}
	temp->next=newnode1;
	}
	}
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
	cout<<temp->city<<":";
	cout<<temp->distance;
	cout<<" -> ";
	temp=temp->next;
	}
	cout<<"NULL";
	cout<<"\n";
	}
}

int main()
{	
	char v1,v2,c;
	int dis;
	cout<<"Enter the no. of vertices and edges  ";
	cin>>n>>e;
	for(int i=1;i<=n;i++)
	{	
		
		cout<<"Enter the city name ";
		cin>>c;
		head[i]=create(c,0);
	}
		
	for(int i=0;i<e;i++)
	{
	cout<<"Enter the vertices (end points of edge) :";	
	cin>>v1>>v2;
	cout<<"Enter the distance :";
	cin>>dis;
	add_edge(v1,v2,dis);
	add_edge(v2,v1,dis);
	}
	display();
	return 0;
}

/* we use adjacency list representation as space complexity for adjancency list is O(n+2e) and list stored the information for the edges that actually exist in the graph.In adjacency matrix the most of the edges are 0 which will take lot of space.Adjacency matrix is useful for dense graph(complete graph).Adjancency list useful for rear graph which will reduce space therefore here we use adjancency list.
*/
