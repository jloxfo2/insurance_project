/*  Home class source file  */

#include "Home.h"


// constructor
Home::Home(string n, int s, float d, float c, float l)
  : InsurancePolicy(n), 
    sqft(s), dwellingCoverage(d), contentsCoverage(c), liability(l)
{}


// calculate commission
void Home::calcCommission()
{
  commission = (liability * 0.3) + \
               ((dwellingCoverage + contentsCoverage) * 0.2);
}


// print method -- used in overloaded << stream operator
void Home::print(ostream &strm) const
{
  cout << "Name of insured: " << name << endl;
  cout << "House square footage: " << sqft << endl;
  cout << "Dwelling coverage: " << dwellingCoverage << endl;
  cout << "Contents coverage: " << contentsCoverage << endl;
  cout << "Liability coverage: " << liability << endl;
  cout << "Commission: " << commission << endl;
}
