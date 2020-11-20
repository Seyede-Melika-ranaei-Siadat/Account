#include <iostream>

using namespace std;

class account
{
private:
	int id;
	char* family;//you can also use char* to!
	int balance;

public:
	account(int = 0, char* = "No Name", int = 0);//you must use this parentheses!
	void setaccount(int, char*, int);
	//sets:
	void setid(int);
	void setfamily(char*);
	void setbalance(int);
	//gets:
	int getid() { return(id); }
	char* getfamily() { return(family); }
	int getbalance() { return(balance); }
	//operational functions:
	void withdraw(int);
	void desposit(int);
	void print();

};

account::account(int i, char* f, int b)
{
	setaccount(i, f, b);

	//alternative solution:
	/*
	id = i;
	family = f;
	balance = b;
	*/
}

void account::setaccount(int i, char* f, int b)
{
	//although you can use yuor validate operation in this function , we prefer to use this operation in main.
	setid(i);
	setfamily(f);
	setbalance(b);

	//alternative solution:
	/*
	id = i;
	family = f;
	balance = b;
	*/
}

void account::setid(int i) { id = i; }
void account::setfamily(char* f) { strcpy(family,f); }
void account::setbalance(int b) {
	if(b>10)
		balance = b; 
	else
        cout<<"invalid parameter!"<<endl;
}

void account::withdraw(int d)
{
	//varidate operation:
	if (balance - d >= 10)
	{
		balance = balance - d;
	}
}

void account::desposit(int d)
{
	if(d>0)
		balance = balance + d;
	else
		cout<<"invalid parameter!"<<endl;
}

void account::print()
{
	cout << "id:"<<id << endl;
	cout << "family:"<<family << endl;
	cout << "balance:"<<balance<<endl;
}

const int mySize=10;
int main()
{
	int ID;
	char FAMILY[mySize];
	int BALANCE;
	int num1, num2;

	cin >> ID;
	cin >> FAMILY;
	cin >> BALANCE;


	//constructor is called:
	account a1(ID, FAMILY, BALANCE);
	cin >> num1;
	cin >> num2;
	a1.desposit(num1);
	a1.withdraw(num2);
	a1.print();	
	

	system("pause");
	return 0;
}

