/*Assignment No.10
Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the alogrithm.*/

#include<iostream>
using namespace std;

class marks
{
	int n;
	int arr[20];
	int arr1[20];
	public:
		marks()
		{
			n=0;
			arr[0]=0;
			arr1[0]=0;
		}
		void insert(int);
		void reheap_up();
		void reheap_down();
		void min();
		void max();
		void display();
		
};

void marks:: insert(int x)
{

	int index=n;
	arr[index]=x;
	int index1=n;
	arr1[index1]=x;
	
	cout<<"\nInserted successfully";
	
	reheap_up();
	reheap_down();
	n++;

}


void marks ::reheap_up()
{
	int index=n;
	while (index>0)
	{
		int parent=(index-1)/2;
		if (arr[parent] < arr[index])
		{
			int temp=arr[parent];
			arr[parent]=arr[index];
			arr[index]=temp;
			
		}
		index=parent;
	}
}


void marks :: reheap_down()
{
	int index1=n;
	while (index1>0)
	{
		int parent1=(index1-1)/2;
		if (arr1[parent1] > arr1[index1])
		{
			int temp1=arr1[parent1];
			arr1[parent1]=arr1[index1];
			arr1[index1]=temp1;
			
		}
		index1=parent1;
	}
}
void marks :: display()
{
	cout<<"\nList of marks : "<<endl;
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}

}
void marks:: max()
{
	cout<<"\nMaximum marks : "<<arr[0];
}

void marks :: min()
{
	cout<<"\nMinimum marks : "<<arr1[0];
	 
}

int main()
{
	marks obj;
	int ch=0;
	int a;
	while(ch<5)
	{
		cout<<"\n**********************************";
		cout<<"\n1.Insert the marks \n2.Display the marks \n3.Maximum marks \n4.Minimum marks \n5.Exit"<<endl;
		cout<<"\n**********************************";
		cout<<"\nEnter the choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the marks : ";
				cin>>a;
				if (a<100 and a>=0)
				{
					obj.insert(a);
					break;
				}
				else
				{
					ch=0;
					cout<<"\nPlease enter the marks below 100"<<endl;
					break;
				}
			case 2:
				obj.display();
				break;
			case 3:
				obj.max();
				break;
			case 4:
				obj.min();
				break;
			default:
				cout<<"\nExiting....";
		}
	}
	
}