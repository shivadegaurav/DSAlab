/*Assignment No.8
Flight code using adjacency list */

#include<iostream>
using namespace std;
#define max 10

class node
{
    public:
    	int vertex;
    	string name;
    	int distance;
    	node*next;
};

class Flight
{
	int size;
	node*head[max];
	public:
		Flight(int n)
		{
			size=n;
			for(int i=0;i<size;i++)
			{
				head[i]=new node;
				head[i]->distance=0;
				head[i]->next=NULL;
				//cout<<head[i]<<endl;
			}	
		}
		void read();
		void display();
		void add_link();
		void check_link();
		
};

void Flight :: read()
{
	
	for(int i=0;i<size;i++)
	{
		cout<<"Enter name of City for "<<i<<" vertex :";
		cin>>head[i]->name;
		head[i]->vertex=i;
	}
}

void Flight :: display()
{
	
	for(int i=0;i<size;i++)
    {
    	node*trav=head[i];
    	while(trav!=NULL)
    	{
    		cout<<trav->name <<" ( "<<trav->distance<<" ) -> ";
    		trav=trav->next;
		}
    	cout<<"\n";
    }
}

void Flight :: add_link()
{
	string source,destination;
	int distance,pos_source=-1,pos_destination=-1;
	cout<<"\nEnter Source:";
	cin>>source;
	cout<<"\nEnter Destination:";
	cin>>destination;
	
	for(int i=0;i<size;i++)
	{
		if( head[i]->name == source )
			pos_source=i;
		
		if( head[i]->name == destination )
			pos_destination=i;
	}
	
	if(pos_source!=-1 && pos_destination!=-1)
	{
		cout<<"\nEnter distance between source and destination:";
		cin>>distance;
		node *trav = head[pos_source];
		while(trav->next!=NULL)
		{
			trav=trav->next;//cout<<"\nTraversing.............\n";
		}
		node*temp=new node;
		
		temp->vertex = pos_destination;
		temp->name = head[pos_destination]->name;
		temp->distance = distance;
		temp->next=NULL;
		
		trav->next=temp;
		//cout<<"\ntemp:"<<temp<<endl<<"trav:"<<trav<<endl<<"trav->next:"<<trav->next;
	}
	else
		cout<<"\nEnter Accurate data";	
}

void Flight :: check_link()
{
	int pos_source=-1,pos_destination=-1,flag=0;
	string source,destination;
	
	cout<<"\nEnter Source:";
	cin>>source;
	cout<<"\nEnter Destination:";
	cin>>destination;
	
	for(int i=0;i<size;i++)
	{
		if( head[i]->name == source )
			pos_source=i;
		
		if( head[i]->name == destination )
			pos_destination=i;
	}
	
	if(pos_source!=-1 && pos_destination!=-1)
	{
		node*trav=head[pos_source];
		while(trav!=NULL)
		{
			if(trav->name == destination)
			{
				flag=1;break;
			}
			trav=trav->next;
		}
		if(flag==1)
			cout<<"\nLink Present Between Source and Destination \nDistance between them is:"<<trav->distance<<endl;
		else
			cout<<"\nLink not presnet\n";
	}
	else
		cout<<"\nEnter Accurate data";
}

int main()
{
	int n,ch=0;
	int index;
	string name;

	
	cout<<"Enter number of cities : ";
	cin>>n;

	Flight obj(n);
	
	while(ch!=5)
	{
		cout<<"\n*****************MENU*****************\n";
		cout<<"1.Enter label for vertices\n2.Display Linked list\n3.Add Link\n4.Check Link\n5.Exit"<<endl;
		cout<<"\nEnter your choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				obj.read();
				break;
			case 2:
				obj.display();
				break;
			case 3:
				obj.add_link();
				break;
			case 4:
				obj.check_link();
				break;
				
		}
	}
}
