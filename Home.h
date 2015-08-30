/*  Home class header file  */

#ifndef _Home_h_
#define _Home _h_

#include "InsurancePolicy.h"


class Home : public InsurancePolicy
{
 protected:
  int sqft;
  float dwellingCoverage, contentsCoverage, liability;

 public:
  // constructor
  Home(string n="", int s=0, float d=0, float c=0, float l=0);

  // deconstructor
  ~Home() {}


  // calculate commission
  void calcCommission();


  // access methods
  void setSqft(int s) { sqft = s; }
  void setDwelling(float d) { dwellingCoverage = d; }
  void setContents(float c) { contentsCoverage = c; }
  void setLiability(float l) { liability = l; }

  int getSqft() { return sqft; }
  float getDwelling() { return dwellingCoverage; }
  float getContents() { return contentsCoverage; }
  float getLiability() { return liability; }


  // print method -- used in overloaded stream << operator
  void print(ostream &strm) const;
};


#endif
