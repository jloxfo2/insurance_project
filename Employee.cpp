/*  Employee class source file  */

#include "Employee.h"


// constructor
Employee::Employee(string n, float baseSal)
  : name(n), baseSalary(baseSal), totalSalary(0), commission(0), \
    commissionTotal(0)
{}



// add a sale to an employee ands sum the new commission
void Employee::newSale(InsurancePolicy *a)
{
  a->calcCommission();  // calculate only the commission for the new policy

  sales.push_back(a);   // add new policy to the employee's sales


  // sums commission made by the employee from each policy
  float tmp;

  for (int i=0; i < sales.size(); i++)
    {
      tmp += sales[i]->getCommission();
    }
  
  commission = tmp;
}



// print policy info for each policy sold by employee
void Employee::printSales()
{
  for (int c=0; c < sales.size(); c++)
    {
      cout << "***************************************************" << endl;
      cout << *sales[c];
      cout << "***************************************************" << endl;
    }
}
