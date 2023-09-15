/*Assignment No.11 
Write a C++ code in which file contains employeee details*/
#include<iostream>
#include<fstream>
using namespace std;

struct employee
{
	int id;
	string name;
	string address;
	
	void getdata()
	{
		cout<<"\nEnter the id : ";
		cin>>id;
		cout<<"\nEnter the name : ";
		cin>>name;
		cout<<"\nEnter the address : ";
		cin>>address;
	
	}
	void putdata()
	{
		cout<<"\nEmployee id : "<<id;
		cout<<"\nEmployee name : "<<name;
		cout<<"\nAddress : "<<address;
	}

};

class file
{
	public:
		fstream fp;
		employee e;
		void create();
		void append();
		void display();
		void search();
		void update();
		void logical_del();
		void physical_del();
};

void file :: create()
{
	char ch;
	fp.open("employee.dat",ios::out);
	do
	{
		e.getdata();
		fp.write((char*)&e, sizeof(e));
		cout<<"\nDo you want to continue (Y/N) : ";
		cin>>ch;
	
	}while(ch=='Y' || ch=='y');
	fp.close();

}

void file:: append()
{
	char ch;
	fp.open("employee.dat",ios::app);
	do
	{
		e.getdata();
		fp.write((char*)&e, sizeof(e));
		cout<<"\nDo you want to continue (Y/N) : ";
		cin>>ch;
	
	}while(ch=='Y' || ch=='y');
	fp.close();

}
void file ::display()
{
	fp.open("employee.dat",ios::in);
	while(!fp.eof())
	{
		fp.read((char*)&e, sizeof(e));
		if (!fp.eof() )
		{
			cout<<"\n---------------------";
			e.putdata();
		}
		else
		{
			break;
		}
	}
	fp.close();
}

void file:: search()
{
	int r;
	cout<<"\nEnter the id to search : ";
	cin>>r;
	fp.open("employee.dat",ios::in);
	int flag=0;
	while(!fp.eof())
	{
		fp.read((char*)&e, sizeof(e));
		if (!fp.eof() && e.id==r)
		{
			flag=1;
			e.putdata();
			break;
		
		}
	
	}
	if (flag==1)
	{
		cout<<"\nId is found "<<endl;
	
	}
	else
	{
		cout<<"\nId not found "<<endl;
	}
	fp.close();

}

void file :: update()
{
	fp.open("employee.dat",ios::in|ios::out);
	
	int key;
	cout<<"\nEnter the id to update : ";
	cin>>key;		
	while(fp.read((char*)&e, sizeof(e)))
	{
		if (e.id==key)
		{
            cout<<"\nEnter the updated information";
            cout<<"\nEnter employee id : ";
            cin>>e.id;
            cout<<"\nEnter name : ";
            cin>>e.name;
            cout<<"\nEnter address : ";
            cin>>e.address;
            fp.seekp(-1*sizeof(e),ios::cur);
            fp.write((char*)&e,sizeof(e));
            break;
		}
        
	}	
	fp.close();
}
	

void file:: logical_del()
{
	int key;
	cout<<"\nEnter the id to delete : ";
	cin>>key;
	fp.open("employee.dat",ios::in|ios::out);
	while(fp.read((char*)&e, sizeof(e)))
	{
		if (e.id==key)
		{
			e.id=0;
            cout<<"\nDeleted successfully";
			//move pointer to previous record
            fp.seekp(-1*sizeof(e),ios::cur);
            fp.write((char*)&e,sizeof(e));
			
			break;
		
		}
	
	}

}
void file:: physical_del()
{
	fstream fp1;
	int key;
	cout<<"\nEnter the id to delete : ";
	cin>>key;
	fp.open("employee.dat",ios::in);
	fp1.open("student1",ios::out);
	while(fp.read((char*)&e, sizeof(e)))
	{
		if (e.id==key)
		{
			cout<<"\nDeleted successfully ";
			e.putdata();
		}
		else
		{
			fp1.write((char*)&e, sizeof(e));
		}
	}
	fp.close();
	fp1.close();
	remove("employee.dat");
	rename("student1","employee.dat");
}
int main()
{
	file f;
	int ch=0;
	while(ch<8)
	{
		cout<<"\n------------------------------------"<<endl;
		cout<<"\n**********************Sequential file*************************";
		cout<<"\n1.Insert \n2.Append \n3.Display \n4.Search \n5.Update \n6.Logical delete \n7.Physical delete \n8.Exit"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<"\nEnter the choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				f.create();
				break;
			case 2:
				f.append();
				break;
			case 3:
				f.display();
				break;
			case 4:
				f.search();
				break;
			case 5:
				f.update();
				break;
			case 6:
				f.logical_del();
				break;
			case 7:
				f.physical_del();
				break;
			default:
				cout<<"\nExiting program......";	
		}
	}
	
}
