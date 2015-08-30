/*  Auto class header file  */

#ifndef _Auto_h_
#define _Auto_h_

#include "InsurancePolicy.h"


class Auto : public InsurancePolicy
{
 protected:
  string autoMakeModel, vin;
  float liability, collision;

 public:
  // constructor
  Auto(string n="", string a="", string v="", float l=0, float c=0);

  // deconstuctor
  ~Auto() {}


  // calculate auto commission
  void calcCommission();


  // access methods
  void setMakeModel(string a) { autoMakeModel = a; }
  void setVIN(string a) { vin = a; }
  void setLiability(float a) { liability = a; }
  void setCollision(float a) { collision = a; }
  
  string getMakeModel() { return autoMakeModel; }
  string getVIN() { return vin; }
  float getLiability() { return liability; }
  float getCollision() { return collision; }


  // print method -- used in overloaded stream << operator
  void print(ostream &strm) const;
};


#endif
