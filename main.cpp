//   MINI BANKING SYSTEM 
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BankingSystem 
{
	int accNum;
	string name;
	int PIN;
	float balance;
	string ph;
};

BankingSystem user[100];
int total = 0;

void create ();
void show ();
void search ();
void deposit ();
void withdraw ();
void update ();
void del ();

int main ()
{
	int choice;
	
	while (true)
	{
		cout << "\n1.Press 1 To Create Account";
		cout << "\n2.Press 2 To Show Accounts";
		cout << "\n3.Press 3 To Search Account";
		cout << "\n4.Press 4 To Deposit Money";
		cout << "\n5.Press 5 To Withdraw Money";
		cout << "\n6.Press 6 To Update Account";
		cout << "\n7.Press 7 To Delete";
		cout << "\n8.Press 8 To EXIT Program \n";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				create ();
				break;
				
			case 2:
				show ();
				break;
				
			case 3:
				search ();
				break;
				
			case 4:
				deposit ();
				break;
				
			case 5:
				withdraw ();
				break;
				
			case 6:
				update ();
				break;
				
			case 7:
				del();
				break;
				
			case 8:
				cout << "YOU HAVE SUCCESSFULLY EXIT THE PROGRAM \n";
				exit (0);
				break;
				
			default :
				cout << "INVALID CHOICE!\n";
		}
	}
}

void create ()
{
	int choice;
	
	cout << "How Many Users Wants To Create Account? \n";
	cin >> choice;
	
	if (choice<=0)
	{
		cout << "Invalid Choice !\n ";
		return;
	}
		
	for (int i=total; i<total+choice; i++)
	{
		cout << "Enter User Details " << i+1 << endl;
				
		cout << "Enter Account Number : \n";
		cin >> user[i].accNum;
				
		bool duplicate = false;
		
        for (int j = 0; j < total; j++) 
		{
			if (user[j].accNum == user[i].accNum) 
			{
				duplicate = true;
                break;
			}
		}

        if (duplicate) 
        {
        	cout << "Account Number Already Exists!\n";
            i--;
            continue;
		}
				cin.ignore();
				cout << "Enter Name : \n";
				getline (cin , user[i].name);
				
				cout << "Enter PIN For Account Protection \n";
				cin >> user[i].PIN;
				
				cout << "Enter Balance : \n";
				cin >> user[i].balance;
				
				cout << "Enter Phone Number : \n";
				cin >> user[i].ph;
	}
	
	total+=choice;
}

void show ()
{
	if (total==0)
	cout << "DATA NOT AVAILABL \n";
	
	else
	{
		for (int i=0; i<total; i++)
		{
			cout << "\nAccount Number : " << user[i].accNum;
			cout << "\nName : " << user[i].name;
			cout << "\nAccount PIN " << user[i].PIN;
			cout << "\nBalance : " << user[i].balance;
			cout << "\nPhone Number : " << user[i].ph;
		}
	}
}

void search ()
{
	int num;
	bool isFound = false;
	
	if (total==0)
	{
		cout << "NO ACCOUNT DATA TO SEARCH! \n";
		return;
	}
	
	cout << "Enter Your Account Number : ";
	cin >> num;
	
	for (int i=0; i<total; i++)
	{
		if (num==user[i].accNum)
		{
			cout << "ACCOUNT FOUND! " << endl;
			cout << "Account Number : " << user[i].accNum << endl;
			cout << "Name : " << user[i].name << endl;
			cout << "Balance : " << user[i].balance << endl;
			isFound = true;
			break;
		}
	}
	
	if(!isFound) 
	cout << "ACCOUNT NOT FOUND!";
}

void deposit ()
{
	int num , pin , money;
	bool isFound = false;
	
	if (total==0)
	cout << "ACCOUNT DATA NOT AVAILABLE TO DEPOSIT MONEY!";
	
	else
	{
		cout << "Enter Your Account Number To Deposit Money \n";
		cin >> num;
		
		cout << "ENTER YOUR PIN \n";
		cin >> pin;
		
		for (int i=0; i<total; i++)
		{
			if (num==user[i].accNum && pin==user[i].PIN)
			{
				cout << "Enter Amount \n";
				cin >> money;
				
				if (money>0)
				{
					user[i].balance+=money;
					cout << "Amount Deposited Successfully \n";
				}
				else 
				{
					cout << "Invalid Amount\n";
				}
				
            	isFound = true;
            	break;
        	}
		}
		
	if(!isFound) 
	cout << "INCORRECT ACCOUNT OR PIN\n";
	}
}

void withdraw ()
{
	
	if (total==0)
	{
		cout << "ACCOUNT DATA NOT AVAILABLE TO WITHDRAW MONEY";
		return;
	}
	
	int num , pin , money;
	bool isFound = false;
	
	cout << "Enter Your Account Number To Withdraw Money \n";
	cin >> num;
		
	cout << "ENTER YOUR PIN \n";
	cin >> pin;
		
	for (int i=0; i<total; i++)
	{
		if (num==user[i].accNum && pin==user[i].PIN)
		{
			cout << "Enter Amount \n";
			cin >> money;
				
			if (money<=0)
			cout << "Invalid Amount \n";
			
			else if (money > user[i].balance)
	        cout << "Insufficient Balance\n";
				
			else
			{
				user[i].balance-=money;
				cout << "Amount Withdraw Successfully \n";
			}
				
			isFound = true;
			break;
		}
	}
	
	if (!isFound)
    cout << "Invalid Account or PIN\n";
}

void update ()
{
	
	if (total==0)
	{
		cout << "DATA NOT AVAILABLE TO UPDATE \n";
		return;
	}
	
	int num;
	bool isFound = false;
	
	cout << "Enter Account Number To Update Data \n";
	cin >> num;
	for (int i=0; i<total; i++)
	{
		if (num==user[i].accNum)
		{
			cout << "PREVIOUS DATA \n";
			cout << "Account Number : \n" << user[i].accNum << endl;
			cout << "Name : \n" << user[i].name << endl;
			cout << "Account PIN \n" << user[i].PIN << endl;
			cout << "Balance : \n" << user[i].balance << endl;
			cout << "Enter Phone Number : \n" << user[i].ph << endl;
				
			cout << "ENTER NEW DATA \n";
				
			cout << "Enter New Account Number : \n";
			cin >> user[i].accNum;
				
			cin.ignore();
			cout << "Enter New Name : \n";
			getline (cin , user[i].name);
				
			cout << "Enter New PIN \n";
			cin >> user[i].PIN;
				
			cout << "Enter New Balance : \n";
			cin >> user[i].balance;
				
			cout << "Enter New Phone Number : \n";
			cin >> user[i].ph;
				
			cout << "Account Updated\n";
	        isFound = true;
	        break;
		}
			
	}
	
	if (!isFound)
	cout << "Acount Not Found\n";
}

void del ()
{
	
	if (total==0)
	{
		cout << "DATA NOT AVAIALABLE TO DELETE";
		return;
	}
	
	int choice;
	
	cout << "\n1.Press 1 To Delete All Data ";
	cout << "\n2.Press 2 To Delete Specific Account Data" << endl;
	cin >> choice;
		
	if (choice==1)
	{
		total=0;
		cout << "ALL DATA DELETED SUCCESSFULLY \n";
		return;
	}
		
	int num;
	bool isFound = false;
	
	cout << "Enter Your Account Number For Deletion \n";
	cin >> num;
		
	for (int i=0; i<total; i++)
	{
		if (user[i].accNum==num)
		{
			for (int j=i; j<total-1; j++)
		{
			user[j].accNum = user[j+1].accNum;
			user[j].name =user[j+1].name;
			user[j].PIN =user[j+1].PIN;
			user[j].balance =user[j+1].balance;
			user[j].ph =user[j+1].ph;
		}
					
			total--;
			cout << "Account Deleted Successfully\n";
            isFound = true;
            break;
		}
	}
	
	if (!isFound)
    cout << "Account Not Found\n";
}
