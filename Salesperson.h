/*  Salesperson class header file  */

#ifndef _Salesperson_h_
#define _Salesperson_h_

#include "Employee.h"


class Salesperson : public Employee
{
 protected:

 public:
  // constructor
  Salesperson(string n="", float baseSal=0);

  // deconstructor
  ~Salesperson() {}


  // calculate total commission & total salary method
  void calcCommTotal();   // virtual function from parent
};


#endif
