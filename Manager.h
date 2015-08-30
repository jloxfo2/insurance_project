/*  Manager class header file  */

#ifndef _Manager_h_
#define _Manager_h_

#include "Employee.h"
#include "Salesperson.h"

class Manager : public Employee
{
 protected:
  vector<int> subordinates;
  float subCommission;

 public:
  // constructor
  Manager(string n="", float baseSal=0);

  // deconstructor
  ~Manager() {}

  
  // calculate total commission & total salary method
  void calcCommTotal();   // virtual function from parent


  // add subordinate and calculate subordinate commission sum
  void addSubordinate( /* Employee * */  int index);


  void setSubCommission(float s) { subCommission = s; }

  
  // list the sales of subordinates reporting to this manager
  void printSubSales(vector<Salesperson> &s);
};


#endif
