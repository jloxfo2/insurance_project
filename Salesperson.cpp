/*  Salesperson class source file  */

#include "Salesperson.h"


// constructor
Salesperson::Salesperson(string n, float baseSal)
  : Employee(n, baseSal)
{}



// calculates total commission & total salary earned -- from parent class
void Salesperson::calcCommTotal()
{
  commissionTotal = commission + (commission * 0.05);

  totalSalary = baseSalary + commissionTotal;  
}
