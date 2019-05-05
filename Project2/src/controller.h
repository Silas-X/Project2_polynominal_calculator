#pragma once
#ifndef POLYCALC_CONTROLLER_H_
#define POLYCALC_CONTROLLER_H_
#include "calculator.h"
namespace ctl {

const int MAXSTORAGE = 26;
class controller {  // should be singleton Only one
 private:
  CalcCore::Polynomial*
      storage[MAXSTORAGE];  // store the expression mapped by "A"-"Z"
  CalcCore::Polynomial expression1, expression2, last_res;
  int numbers;
  static controller* commander;

  // CalcCore::Polynomial findPolynominal(char sym) const;
  // Singleton contructor
  controller();

 public:
  ~controller();

  // accessor
  // bool getPolynominal(char sym, CalcCore::Polynomial current) const;
  // int getTotalNumbers() const;
  bool isEmpty() const;
  void showMemory() const;

  // mutator
  bool storeIt(char sym, CalcCore::Polynomial& temp);
  bool clear();
  bool CalcUnit(CalcCore::Polynomial& (*process)());
  CalcCore::Polynomial& addition();
  CalcCore::Polynomial& substraction();
  CalcCore::Polynomial& multiplication();
  CalcCore::Polynomial& derivation();
  CalcCore::Polynomial& evaluation();
  CalcCore::Polynomial& setExpression(CalcCore::Polynomial& expression);

  // singleton creator;
  static controller* init();
};

}  // namespace ctl

#endif  // POLYCALC_CONTROLLER_H_