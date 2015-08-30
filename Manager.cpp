/*  Manager class source file   */

#include "Manager.h"


// constructor
Manager::Manager(string n, float baseSal)
  : Employee(n, baseSal),
    subCommission(0)
{}



// calculate total commission and salary  earned -- from parent class
void Manager::calcCommTotal()
{
  commissionTotal = commission + (commission * 0.3) + (subCommission * 0.05);
 
  totalSalary = baseSalary + commissionTotal;
}



// add subordinate index to vector
void Manager::addSubordinate(int index)
{
  subordinates.push_back(index);
}



// list the sales of subordinates reporting to this manager
void Manager::printSubSales(vector<Salesperson> &s)
{
  cout << "Insurance policies sold by " << name << "'s subordinates: " << endl;

  for (int i=0; i < subordinates.size(); i++)
    {
      // print sales for each subordinate indexed by the manager's vector
      s[ subordinates[i] ].printSales();
    }
}
