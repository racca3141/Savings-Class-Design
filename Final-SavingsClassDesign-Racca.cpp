//Emerson Racca
//12/8/2021
//Final - Savings Class Design


//As the first step in writing an application for the local Credit Union, we will design and
//implement a Savings account class that will define the data structure of the application.
//
//Design: Each savings account has a name, amount, and 5-digit integer accountNumber.
//
//Design and implement a Savings class with separation.
//Provide accessor (get and set) methods for each property as well as a display method.
//Provide data validation for the account number and amount in the appropriate methods. These values should never be negative.
//Code a deposit method that allows an instance to add money to the account.
//Code a withdrawal method that allows an instance to withdraw money from an account.
//In the main function:
//
//Part I:  Instantiate ONE instance of this class and show that the deposit and withdraw methods work.  NO UI, hard code the test values.
//
//Part II:  Instantiate a vector of Savings objects.  Ask the user how many savings accounts to create (the size of the vector). 
//Populate the vector of savings objects with randomly chosen properties.  
//In a for loop, display the properties of each object on the screen.
//
//Turn in a single source file ( .cpp ) with separation.

//

#include<iostream>
#include<cmath> //abs()
#include<cstdlib> //srand(), rand()
#include<ctime> //time()
#include<iomanip>
#include<vector>

using namespace std;

class Savings {
private:
	string name;
	double amount;
	int accountNum;
public:
	//constructors
	Savings(string nm = "John Doe", double amt = 0.0, int ac = 10000);
	//accessors
	string getName(void);
	double getAmount(void);
	int getAccountNum(void);
	void setName(string nm);
	void setAmount(double amt);
	void setAccountNum(int ac);
	//methods
	void display(void);
	void deposit(double amt);
	void withdraw(double amt);
};

int main(void) {
	cout << fixed << setprecision(2);

	cout << "Savings Class Design" << endl << endl;
	//Part 1
	cout << "Part 1:" << endl;

	cout << "\nInstantiate an object using: Savings me(\"Emerson Racca\", -314.15, -50000);" << endl;
	Savings me("Emerson Racca", -314.15, -50000);
	me.display();

	cout << "\nDeposit using: me.deposit(85.85);" << endl;
	me.deposit(85.85);
	me.display();

	cout << "\nWithdrawal using: me.withdraw(396.86);" << endl;
	me.withdraw(396.86);
	me.display();

	cout << "\nTo demonstrate what would happen if account number is not 5 digits using: me.setAccountNum(314159);" << endl;
	me.setAccountNum(314159);
	me.display();

	//part 2	
	srand((unsigned int) time(0)); //I placed these here for readability and separation.
	int qty;
	string name;
	double amt;
	int acc;

	vector<Savings> BofA;
	string fn[10] = { "Aaron", "Andy", "Beth", "Cathy", "Diana", "Ernesto", "Gavin", "Heidi", "Irene", "Jason" };
	string ln[10] = { "Kirkland", "Landy", "Mathews", "Ochoa", "Pearson", "Rutherford", "Roberts", "Smith", "Tucker", "West" };
	cout << "\n\nPart 2:" << endl << endl;

	cout << "How many accounts would you like to create? ";
	cin >> qty;
	cout << endl;

	for (int i = 0; i < qty; i++) {
		name = fn[rand() % 10] + " " + ln[rand() % 10];
		amt = (1.0 * 100 + rand() % 9900) + (1.0 * rand() / RAND_MAX); //100 minimum to 10,000 dollars
		acc = 10000 + rand() % 90000; // 10000 to 99999 for a 5-digit account number
		BofA.push_back(Savings(name, amt, acc));
	}

	for (unsigned int i = 0; i < BofA.size(); i++) {
		cout << "Index " << i << ":" << endl;
		cout << "---------------------------------" << endl;
		BofA[i].display();
		cout << endl;
	}

	return 0;
}

//Savings:
//constructors:
Savings::Savings(string nm, double amt, int ac) {
	setName(nm);
	setAmount(amt);
	setAccountNum(ac);
}

//accessors:
string Savings::getName(void) {
	return name;
}
double Savings::getAmount(void) {
	return amount;
}
int Savings::getAccountNum(void) {
	return accountNum;
}
void Savings::setName(string nm) {
	name = nm;
}
void Savings::setAmount(double amt) {
	amount = abs(amt);
}
void Savings::setAccountNum(int ac) {
	ac = abs(ac);
	if (ac < 10000 || ac > 99999) {
		//I didn't really want to put a cout here, but I felt this was necessary.
		//The default would only be assigned when the object is created.
		cout << "[Invalid account number. The account number was not changed or the default of 10000 was assigned.]" << endl;
	}
	else
		accountNum = ac;
}

//methods:
void Savings::display(void) {
	cout << "Name:           " << getName() << endl;
	cout << "Account Number: " << getAccountNum() << endl;
	cout << "Amount:         $" << getAmount() << endl;
}
void Savings::deposit(double amt) {
	setAmount(getAmount() + amt);
}
void Savings::withdraw(double amt) {
	setAmount(getAmount() - amt);
}