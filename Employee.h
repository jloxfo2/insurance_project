/*  Employee class header file  */

#ifndef _Employee_h_
#define _Employee_h_

#include "InsurancePolicy.h"
#include <string>
#include <vector>


class Employee
{
 protected:
  string name;
  float baseSalary, totalSalary;
  float commission, commissionTotal;
  vector<InsurancePolicy *> sales;

 public:
  // constructor
  Employee(string n="", float baseSal=0);

  // virtual deconstructor
  virtual ~Employee() {}

  
  // calculates total commission for the employee - pure virtual function
  virtual void calcCommTotal() = 0;


  // add a sale to employee
  void newSale(InsurancePolicy *);


  // print all sales
  void printSales();


  // access methods
  void setName(string n) { name = n; }
  void setBaseSal(float b) { baseSalary = b; }
  void setCommission(float c) { commission = c; }
  
  string getName() { return name; }
  float getBaseSal() { return baseSalary; }
  float getCommission() { return commission; }
  float getCommTotal() { return commissionTotal; }
  float getSalTotal() { return totalSalary; }
};


#endif
