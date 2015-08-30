/*  InsurancePolicy class header file  */

#ifndef _InsurancePolicy_h_
#define _InsurancePolicy_h_

#include <string>
#include <iostream>
using namespace std;


class InsurancePolicy
{
 protected:
  string name;
  float commission;

 public:
  // constructor
  InsurancePolicy(string n);

  // virtual destructor
  virtual ~InsurancePolicy() {}


  // calculates commission - pure virtual function
  virtual void calcCommission() = 0;


  // access methods
  void setName(string n) { name = n; }
  
  string getName() { return name; }
  float getCommission() { return commission; }


  // overloaded stream output operator
  friend ostream &operator<<(ostream &strm, const InsurancePolicy &a)
  {
    a.print(strm);  // child classes will overwrite this method
    return strm;
  }


  // print method -- pure virtual function to be overwritten by
  // child classes for the overloaded stream output operator
  virtual void print(ostream &strm) const = 0;
};


#endif
