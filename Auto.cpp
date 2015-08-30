/*  Auto class source file  */

#include "Auto.h"


// constructor
Auto::Auto(string n, string a, string v, float l, float c)
  : InsurancePolicy(n),
    autoMakeModel(a), vin(v), liability(l), collision(c)
{}


// calculate Auto commission
void Auto::calcCommission()
{
  commission = (liability + collision) * 0.30;
}


// print method -- used in overloaded << stream operator
void Auto::print(ostream &strm) const
{
  cout << "Name of insured: " << name << endl;
  cout << "Make and Model: " << autoMakeModel << endl;
  cout << "VIN: " << vin << endl;
  cout << "Liability coverage: " << liability << endl;
  cout << "Collision coverage: " << collision << endl;
  cout << "Commission: " << commission << endl;
}
