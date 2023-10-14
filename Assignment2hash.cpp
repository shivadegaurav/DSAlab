/*Assignment No.2
Consider telephone  book datatbase of N clients. Make use of a hash table implementation to quickly look up client's telephone number. Make use of two collision handling technique and compare them using number of comparisions required to find a set of telephone numbers.
*/

#include <iostream>
using namespace std;
#define size 10
struct phonebook
{
	long long  mobile_no;
    string name;
};

class hashing1
{
    int n;
    phonebook arr[size];

public:
    hashing1()
    {
        cout << "\nEnter the size of phonebook : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            arr[i].mobile_no = -1;
            arr[i].name = "   ";
        }
    }
    int hash(long long);
    void insert();
    void search();
    void del();
    void display();
    
};
int hashing1 ::hash(long long key)
{
    return key % n;
}
void hashing1 ::insert()
{
    long long key, index;
    string name1;
    int cnt = 1;
    cout << "\nEnter the name : ";
    cin >> name1;
    cout << "\nEnter the mobile number : ";
    cin >> key;
    index = hash(key);
    if (arr[index].mobile_no == -1)
    {
        arr[index].mobile_no = key;
        arr[index].name = name1;
        cout<<"\nInserted successfully"<<endl;;

    }
    else if (arr[index].mobile_no != -1)
    {
        for (int i = (index + 1) % n; i < n; i = (i + 1) % n)
        {
            if (arr[i].mobile_no == -1)
            {
                arr[i].mobile_no = key;
                arr[i].name = name1;
                cout<<"\nInserted successfully"<<endl;;
                break;
            }
            else if (arr[i].mobile_no != -1)
            {
                
                cnt = cnt + 1;
                if (cnt >= n)
                {
                    cout << "\n----------------------------" << endl;
                    cout << "\nHash table is overflow " << endl;
                    cout << "----------------------------" << endl;
                    break;
                }
            }
        }
    }
    cout<<"-----------------------------------"<<endl;
}

void hashing1 ::search()
{
    long long key;
    int cnt=0;
    cout << "\nEnter the mobile number which you want to search : ";
    cin >> key;
    int index = hash(key);
    int flag = 0;
    if (arr[index].mobile_no == key)
    {
        cnt=cnt+1;
        cout << "\nMobile number is found in phonebook ";
    }
    else
    {
        for (int i = (index + 1) % n; i < n; i = (i + 1) % n)
        {
            if (arr[i].mobile_no == key)
            {
                cnt=cnt+1;
                flag = 1;
                break;
            }
            else
            {
                cnt=cnt+1;
            }
            if(i == index-1){
                cout << "\nMobile number is not found ";
                break;
            }
        }
        if (flag == 1)
        {
            cout << "\nMobile number is found ";
        }
    }
    cout<<"\nComparision required are : "<<cnt;
}
void hashing1 ::del()
{
    long long key;
    cout << "\nEnter the mobile number which you want to delete : ";
    cin >> key;
    int index = hash(key);
    if (arr[index].mobile_no == key)
    {
        arr[index].mobile_no = -1;
        arr[index].name = "NULL";
        cout << "\nMobile number deleted" << endl;
    }
    else 
    {
        for (int i = (index + 1) % n; i < n; i = (i + 1) % n)
        {
            if (arr[i].mobile_no == key)
            {
                arr[i].mobile_no = -1;
                arr[i].name = "NULL";
                cout << "\nMobile number deleted" << endl;
                break;
            }
            if (i=index-1)
            {
                cout<<"\nMobile number is not found "<<endl;
                break;
            }
        }
    }
}
void hashing1 ::display()
{
    cout << "\nIndex\t\tName\t\tMobile no" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t\t" << arr[i].name << "\t\t" << arr[i].mobile_no << endl;
    }
}
class hashing2
{
    int n;
    phonebook arr[size];

public:
    hashing2()
    {
        cout << "\nEnter the size of phonebook : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            arr[i].mobile_no = -1;
            arr[i].name = "   ";
        }
    }
    int hash(long long);
    void insert2();
    void search2();
    void del2();
    void display();
};
int hashing2:: hash(long long key)
{
    return key%n;
}
void hashing2 ::insert2()
{
    long long key, index, index2;
    string name1;
    int i = 0;
    int cnt = 1;
    cout << "\nEnter the name : ";
    cin >> name1;
    cout << "\nEnter the mobile number : ";
    cin >> key;

    index = hash(key);
    if (arr[index].mobile_no == -1)
    {
        arr[index].mobile_no = key;
        arr[index].name = name1;
        cout<<"\nInserted successfully"<<endl;
    }
    else if (arr[index].mobile_no != -1)
    {
        for (int i = 0; i < n; i++)
        {
            index2 = (index + (i * i)) % n;
            if (arr[index2].mobile_no == -1)
            {
                arr[index2].mobile_no = key;
                arr[index2].name = name1;
                cout<<"\nInserted successfully"<<endl;
                break;
            }
            else if (arr[i].mobile_no != -1)
            {
                cnt = cnt + 1;
                if (cnt >= n)
                {
                    cout << "\n----------------------------" << endl;
                    cout << "\nHash table is overflow " << endl;
                    cout << "----------------------------" << endl;
                    break;
                }
            }
        }
    }
    cout<<"-----------------------------------"<<endl;
}

void hashing2 ::search2()
{
    long long key, index2;
    int cnt=0;
    cout << "\nEnter the mobile number which you want to search : ";
    cin >> key;
    int index = hash(key);
    int flag = 0;
    if (arr[index].mobile_no == key)
    {
        cnt=cnt+1;
        cout << "\nMobile number is found in phonebook ";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            index2 = (index + (i * i)) % n;
            if (arr[index2].mobile_no == key)
            {
                cnt=cnt+1;
                flag = 1;
                break;
            }
            else
            {
                cnt=cnt+1;
            }
        }
        if (flag == 1)
        {
            cout << "\nMobile number is found ";
        }
        else
        {
            cout << "\nMobile number is not found ";
        }
    }
    cout<<"\nComparisions required are : "<<cnt;
}
void hashing2 ::del2()
{
    long long key;
    cout << "\nEnter the mobile number which you want to delete : ";
    cin >> key;
    int index2;
    int index = hash(key);
    if (arr[index].mobile_no == key)
    {
        arr[index].mobile_no = -1;
        arr[index].name = "NULL";
        cout << "\nMobile number deleted" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            index2 = (index + (i * i)) % n;
            if (arr[index2].mobile_no == key)
            {
                arr[index2].mobile_no = -1;
                arr[index2].name = "NULL";
                cout << "\nMobile number deleted" << endl;
                break;
            }
            
        }
    }
}
void hashing2 ::display()
{
    cout << "\nIndex\t\tName\t\tMobile no" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\n"<<i << "\t\t" << arr[i].name << "\t\t" << arr[i].mobile_no ;
    }
}
int main()
{
    int ch = 0, ch1 = 0,ch2=0;
    label1:
    cout<<"\n***********************PHONEBOOK***********************";
    cout << "\n1.Linear Probing \n2.Quadratic Probing \n3.Exit " << endl;
    cout<<"\n*******************************************************";
    cout << "\nEnter the choice : ";
    cin >> ch;
    if (ch==1)
    {
        hashing1 obj1;
        cout<<"-----------------------------------------";
        cout << "\n*******Linear Probing*******";
        
        while (ch1 < 5)
        {
            cout << "\n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit" << endl;
            cout<<"-----------------------------------------";
            cout << "\nEnter the choice : ";
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                obj1.insert();
                break;
            case 2:
                obj1.display();
                break;
            case 3:
                obj1.search();
                break;
            case 4:
                obj1.del();
                break;
            default:
                ch=0;
                goto label1;
                cout << "\nExiting linear probing.......";
            }
        }
    }
    else if(ch == 2){
        hashing2 obj2;
        cout<<"\n-----------------------------------------";
        cout << "\n*******Quadratic Probing*******";
        
        while (ch2 < 5)
        {
            cout << "\n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit" << endl;
            cout<<"\n-----------------------------------------";
            cout << "\nEnter the choice : ";
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                obj2.insert2();
                break;
            case 2:
                obj2.display();
                break;
            case 3:
                obj2.search2();
                break;
            case 4:
                obj2.del2();
                break;
            default:
                ch=0;
                goto label1;
                cout << "\nExiting.......";
            }
        }
    }
    else{
        cout<<"\nInvalid Choice...";
        char ans;
        cout<<"\nIf you want to re-enter choice (Y/N): ";
        cin>>ans;
        if(ans == 'y'||ans =='Y'){
            ch = 0;
            goto label1;
        }
        else{
            cout<<"Exiting..."<<endl;
        }
    }
}