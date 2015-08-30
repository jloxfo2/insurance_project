/*  Life class source file  */

#include "Life.h"


// constructor
Life::Life(string n, int a, string d, float t)
  : InsurancePolicy(n),
    age(a), dependent(d), termLife(t)
{}


// calculate commission
void Life::calcCommission()
{
  commission = termLife * 0.20;
}


// print method -- used in overloaded << stream operator
void Life::print(ostream &strm) const
{
  cout << "Name of insured: " << name << endl;
  cout << "Age of insured: " << age << endl;
  cout << "Name of dependent: " << dependent << endl;
  cout << "Amount of term life: " << termLife << endl;
  cout << "Commission: " << commission << endl;
}
