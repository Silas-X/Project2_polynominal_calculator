//#define DEBUG_
#include <iostream>
//#include "UI.h"
#include "calculator.h"
#include "controller.h"
using namespace CalcCore;

struct data {
  int num[1000];
  int maxOrder;
  data() : num{0}, maxOrder{0} {}
  data(int* number, int size) {
    for (int i = 0; size; i++) num[i] = number[i];
    maxOrder = size - 1;
  }
};

void print(Polynomial current) {
  for (int i = current.getMaxOrder(); i >= 0; i--) {
    if (current.at(i) == 0) continue;
    if (i > 0)
      std::cout << "+" << current.at(i) << "x^" << i;
    else
      std::cout << current.at(i);
  }
  std::cout << std::endl;
}

int main() {
  controller* Calculator = controller::init();
  Calculator->start();
  return 0;
}