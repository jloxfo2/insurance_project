/*  Life class header file  */

#ifndef _Life_h_
#define _Life_h_

#include "InsurancePolicy.h"


class Life : public InsurancePolicy
{
 protected:
  int age;
  string dependent;
  float termLife;

 public:
  // constructor
  Life(string n="", int a=0, string d="", float t=0);

  // deconstructor
  ~Life() {}


  // calculate commission
  void calcCommission();


  // access methods
  void setAge(int a) { age = a; }
  void setDependent(string d) { dependent = d; }
  void setTermLife(float t) { termLife = t; }

  int getAge() { return age; }
  string getDependent() { return dependent; }
  float getTermLife() { return termLife; }


  // print method -- used in overloaded stream << operator
  void print(ostream &strm) const;
};


#endif
