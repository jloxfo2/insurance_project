/*  project 4  */

#include "InsurancePolicy.h"
#include "Auto.h"
#include "Home.h"
#include "Life.h"

#include "Employee.h"
#include "Salesperson.h"
#include "Manager.h"

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;



/******************  function declarations  ************************/
void mainMenu();

void addEmployee(vector<Salesperson> &s, vector<Manager> &m);
void addSalesperson(vector<Salesperson> &s, vector<Manager> &m);
void addManager(vector<Manager> &m);

void addInsuranceSale(vector<Salesperson> &s, vector<Manager> &m);
void addAuto(vector<Salesperson> &s, vector<Manager> &m);
void addHome(vector<Salesperson> &s, vector<Manager> &m);
void addLife(vector<Salesperson> &s, vector<Manager> &m);

void printOptions(vector<Salesperson> &s, vector<Manager> &m);
void printEmployees(vector<Salesperson> &s, vector<Manager> &m);
void printAllSales(vector<Salesperson> &s, vector<Manager> &m);
void printIndividualSales(vector<Salesperson> &s, vector<Manager> &m);
void printSalesSubordinates(vector<Salesperson> &s, vector<Manager> &m);
void printTabular(vector<Salesperson> &s, vector<Manager> &m);

void listSalespersons(vector<Salesperson> &s);
void listManagers(vector<Manager> &m);
/*******************************************************************/



main()
{
  int selection = -1;
  vector<Salesperson> saleWorkers;
  vector<Manager> managers;

  cout << "Welcome Parkland Insurance Company" << endl;


  while (selection != 4)
    {
      mainMenu();
      
      cin >> selection;
      
      if (selection == 1)
	addEmployee(saleWorkers, managers);

      else if (selection == 2)
	addInsuranceSale(saleWorkers, managers);

      else if (selection == 3)
	printOptions(saleWorkers, managers);
    }
}



void mainMenu()
{
  cout << "***************************************************" << endl;
  cout << "***************************************************" << endl;
  cout << "Main menu: " << endl;
  cout << "1. Add employee" << endl;
  cout << "2. Add sale" << endl;
  cout << "3. Print options" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter an integer to select an option: ";
}




void addEmployee(vector<Salesperson> &s, vector<Manager> &m)
{
  int selection = -1;
  
  cout << "Select the type of employee to add: " << endl;
  cout << "1. Salesperson" << endl;
  cout << "2. Manager" << endl;

  cin >> selection;   // get employee type to add from user


  if (selection == 1)
    {
      // check if a manager exists; salespersons have to work under a manager
      if (m.size() == 0)
	{
	  cout << "There aren't any managers for the salesperson to " \
	          "work under." << endl;
	  cout << "Add a manager before adding a salesperson" << endl;

	  return;
	}
      else
	// pass vector to add salesperson function
	addSalesperson(s, m);
    }
  else if (selection == 2)
    {
      // pass vector to add manager function
      addManager(m);
    }
  else
    // output if user doesn't enter 1 or 2
    cout << "That is not a valid selection" << endl;
}




void addSalesperson(vector<Salesperson> &s, vector<Manager> &m)
{
  string n;
  float b;
  int managerNum;


  // get employee name and salary from user
  cout << "Enter the salesperson's name: ";
  cin.ignore();
  getline(cin, n);
  cout << "Enter the salesperson's salary: ";
  cin >> b;

  Salesperson tmp(n, b);

  s.push_back( tmp );  // add new salesperson to salesperson vector
  
  // get the index of the new salesperson
  int subIndex = s.size() - 1;


  cout << "Select salesperson's manager:" << endl;

  // list managers, allow user to select one, and add salesperson to 
  // that manager
  listManagers(m);
  
  cin >> managerNum;
  
  // add index of last salesperson to manager's subordinate index  vector
  m[managerNum].addSubordinate(subIndex);
}



void addManager(vector<Manager> &m)
{
  string n;
  float b;
  
  // get employee name and salary from user
  cout << "Enter the manager's name: ";
  cin.ignore();
  getline(cin, n);
  cout << "Enter the manager's salary: ";
  cin >> b;

  Manager tmp(n, b);

  m.push_back( tmp );  // add new manager to manager vector
}



void addInsuranceSale(vector<Salesperson> &s, vector<Manager> &m)
{
  int selection = -1;


  // check if there are any employees to make a sale
  if( (s.size() == 0) && (m.size() == 0))
    {
      cout << "There are currently no employees to make a sale" << endl;
      return;
    }


  cout << "Select the type of insurance sale:" << endl;
  cout << "1. Auto" << endl;
  cout << "2. Home" << endl;
  cout << "3. Life" << endl;

  cin >> selection;

  if (selection == 1)
    addAuto(s, m);
  else if (selection == 2)
    addHome(s, m);
  else if (selection == 3)
    addLife(s, m);
  else
    // output if user doesn't enter 1, 2, or 3
    cout << "That is not a valid selection" << endl;
}


// add auto insurance policy to an employee's sales
void addAuto(vector<Salesperson> &s, vector<Manager> &m)
{
  string n, a, v;
  float l, c;

  // get policy info from user
  cout << "Enter insured's name: ";
  cin.ignore();
  getline(cin, n);
  cout << "Enter vehicle make and model: ";
  getline(cin, a);
  cout << "Enter VIN number: ";
  getline(cin, v);
  cout << "Enter amount of liability: ";
  cin >> l;
  cout << "Enter amount of collision coverage: ";
  cin >> c;


  
  // asks user which employee made the sale so they can receive commission
  cout << "Which type of employee made the sale: " << endl;
  cout << "1. Salesperson" << endl;
  cout << "2. Manager" << endl;
  
  int i, select;

  cin >> i;  // get employee type from user

  if (i == 1)
    {
      // add policy to a salesperson
      cout << "Enter the employee's respective number:" << endl;
      
      listSalespersons(s);  // list Salespersons
      cin >> select;

      s[select].newSale( new Auto(n, a, v, l ,c) );  // add policy sale to 
			                             // selected employee

      s[select].calcCommTotal();  // calculate employees commission & salary

      return;
    }
  else if (i == 2)
    {
      // add policy to a manager
      cout << "Enter the employee's respective number:" << endl;
      
      listManagers(m);  // list managers
      cin >> select;

      m[select].newSale( new Auto(n, a, v, l, c) );  // add policy sale to 
                                                     //  selected employee

      m[select].calcCommTotal();  // calculate employees commission & salary

      return;
    }
}



// add home insurance policy to an employee's sales
void addHome(vector<Salesperson> &s, vector<Manager> &m)
{
  string n;
  int sq;
  float d, c, l;

  // get policy info from user
  cout << "Enter insured's name: ";
  cin.ignore();
  getline(cin, n);
  cout << "Enter house square footage: ";
  cin >> sq;
  cout << "Enter dwelling coverage: ";
  cin >> d;
  cout << "Enter contents coverage: ";
  cin >> c;
  cout << "Enter liability coverage: ";
  cin >> l;



  // asks user which employee made the sale so they can receive commission
  cout << "Which type of employee made the sale: " << endl;
  cout << "1. Salesperson" << endl;
  cout << "2. Manager" << endl;

  int i, select;

  cin >> i;  // get employee type from user

  if (i == 1)
    {
      // add policy to a salesperson
      cout << "Enter the employee's respective number:" << endl;

      listSalespersons(s);  // list Salespersons
      cin >> select;

      s[select].newSale( new Home(n, sq, d, c ,l) );  // add policy sale to
                                                     // selected employee

      s[select].calcCommTotal();  // calculate employees commission & salary

      return;
    }
  else if (i == 2)
    {
      // add policy to a manager
      cout << "Enter the employee's respective number:" << endl;

      listManagers(m);  // list managers
      cin >> select;

      m[select].newSale( new Home(n, sq, d, c, l) );  // add policy sale to
                                                     //  selected employee

      m[select].calcCommTotal();  // calculate employees commission & salary

      return;
    }
}



// add life insurance policy to an employee's sales
void addLife(vector<Salesperson> &s, vector<Manager> &m)
{
  string n, d;
  int a;
  float t;

  // get policy info from user
  cout << "Enter insured's name: ";
  cin.ignore();
  getline(cin, n);
  cout << "Enter dependent's name: ";
  getline(cin, d);
  cout << "Enter insured's age: ";
  cin >> a;
  cout << "Enter term life coverage: ";
  cin >> t;



  // asks user which employee made the sale so they can receive commission
  cout << "Which type of employee made the sale: " << endl;
  cout << "1. Salesperson" << endl;
  cout << "2. Manager" << endl;

  int i, select;

  cin >> i;  // get employee type from user

  if (i == 1)
    {
      // add policy to a salesperson
      cout << "Enter the employee's respective number:" << endl;

      listSalespersons(s);  // list Salespersons
      cin >> select;

      s[select].newSale( new Life(n, a, d, t) );     // add policy sale to
                                                     // selected employee

      s[select].calcCommTotal();  // calculate employees commission & salary

      return;
    }
  else if (i == 2)
    {
      // add policy to a manager
      cout << "Enter the employee's respective number:" << endl;

      listManagers(m);  // list managers
      cin >> select;

      m[select].newSale( new Life(n, a, d, t) );     // add policy sale to
                                                     //  selected employee

      m[select].calcCommTotal();  // calculate employees commission & salary

      return;
    }
}



void printOptions(vector<Salesperson> &s, vector<Manager> &m)
{
  int selection = -1;

  cout << "***************************************************" << endl;
  cout << "Print options: " << endl;
  cout << "1. List of employees only" << endl;
  cout << "2. List of all sales only" << endl;
  cout << "3. List of all sales made by an individual employee" << endl;
  cout << "4. List of all sales made by employees reporting to ";
  cout << "an individual manager" << endl;
  cout << "5. List of all sales in tabular format" << endl;

  cin >> selection;
  
  // get user selection and branch to appropriate function
  if (selection == 1)
    printEmployees(s, m);
  else if (selection == 2)
    printAllSales(s, m); 
  else if (selection == 3)
    printIndividualSales(s, m);
  else if (selection == 4)
    printSalesSubordinates(s, m);
  else if (selection == 5)
    printTabular(s, m);
  else
    cout << "That is not a valid selection" << endl;
}



void printEmployees(vector<Salesperson> &s, vector<Manager> &m)
{
  cout << "Salespersons:" << endl;
  listSalespersons(s);

  cout << "Managers:" << endl;
  listManagers(m);
}



void printAllSales(vector<Salesperson> &s, vector<Manager> &m)
{
  cout << "***************************************************" << endl;
  cout << "All policy sales:" << endl;

  // print policy sales for each salesperson
  for (int i=0; i < s.size(); i++)
    s[i].printSales();

  // print policy sales for each manager
  for (int k=0; k < m.size(); k++)
    m[k].printSales();
}



void printIndividualSales(vector<Salesperson> &s, vector<Manager> &m)
{
  int j, k;

  cout << "Select employee type to print:" << endl;
  cout << "1. Salesperson" << endl;
  cout << "2. Manager" << endl;
  
  cin >> j;

  // select employee and print their sales
  if (j == 1)
    {
      cout << "Select the employee to print:" << endl;
      listSalespersons(s);

      cin >> k;

      s[k].printSales();  // print sales of selected employee
    }
  else if (j == 2)
    {
      cout << "Select the employee to print:" << endl;
      listManagers(m);

      cin >> k;

      m[k].printSales();  // print sales of selected employee
    }
}



void printSalesSubordinates(vector<Salesperson> &s, vector<Manager> &m)
{
  int i;

  cout << "Select manager to have their subordinates printed:" << endl;
  listManagers(m);

  cin >> i;

  m[i].printSubSales(s);  // prints subordinate sales
}



void printTabular(vector<Salesperson> &s, vector<Manager> &m)
{
  cout << setw(12) << left << "Name:" << setw(16) << left \
       << "Commission:" << setw(10) << left << "Salary" << endl;


  // print salesperson info in tabular format
  for (int i=0; i < s.size(); i++)
    {
      s[i].calcCommTotal();  // make sure commission/salary are up to date

      cout << setw(16) << left << s[i].getName();
      cout << setw(16) << left << s[i].getCommission();
      cout << setw(10) << left << s[i].getSalTotal() << endl;
    }

  // print manager info in tabular format
  for (int k=0; k < m.size(); k ++)
    {
      m[k].calcCommTotal();  // make sure commission/salary are up to date
      
      cout << setw(16) << left << m[k].getName();
      cout << setw(16) << left << m[k].getCommission();
      cout << setw(10) << left << m[k].getSalTotal() << endl;

    }
}



/*****  these function just list Salespersons and Managers  *********/
/*******************************************************************/

void listSalespersons(vector<Salesperson> &s)
{
  for (int i=0; i < s.size(); i++)
    {
      cout << i << ". " << s[i].getName() << endl;
    }
}


void listManagers(vector<Manager> &m)
{
  for (int i=0; i < m.size(); i++)
    {
      cout << i << ". " << m[i].getName() << endl;
    }
}
