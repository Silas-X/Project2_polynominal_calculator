#include "UI.h"
#include <iostream>
#include <string>

namespace UI {
UserInterface::UserInterface(ctl::controller*& _butler)
    : opt{0}, callMenu{0}, opt_str{""} {
  this->butler = _butler;
}
UserInterface::~UserInterface() {}

bool UserInterface::setCallMenu(int opt) {
  callMenu = opt;
  return true;
}

int UserInterface::getOption() const { return opt; }
int UserInterface::getNext() const { return callMenu; }

void UserInterface::dispatch() {
  bool exitFlag = false;
  while (!exitFlag) {
    switch (callMenu) {
      case -1:
        sayGoodbye();
        exitFlag = true;
        break;
      case 0:
        welcomePage();
        break;
      case 1:
        mainMenu();
        break;
      default:
        std::cout << "CATASTROPHY" << std::endl;
        callMenu = -1;
        break;
    }
  }
  return;
}

bool UserInterface::setOption() {
  bool valid = false;
  std::cout << "Please choose option" << std::endl;
  while (!valid) {
    std::getline(std::cin, opt_str);
    if (opt_str.size() == 1 && isdigit(opt_str[0])) {
      valid = true;
      opt = opt_str[0] - 48;
      return true;
    }
    std::cout << "Invalid, please re-enter " << std::endl;
  }
  return false;
}

void UserInterface::welcomePage() {
  using std::cout;
  using std::endl;
  cout << "\t------------------------------------------------------------------"
          "---\t"
       << endl;
  cout << "\t|Welcome To the polynomial calculator\t|" << endl;
  cout << "\t|This is intended for Programming Courses Homework II\t|" << endl;
  cout << "\t|Author: Silas XU\t|" << endl;
  cout << "\t|If there is any problem while using, please fell free to contact"
          "with me.\t|"
       << endl;
  cout << "\t|Start Program?(1 to start,o to exit)\t|" << endl;
  cout << "\t------------------------------------------------------------------"
          "---\t"
       << endl;
  bool exitFlag = false;
  while (!exitFlag) {
    setOption();
    switch (getOption()) {
      case 0:
        sayGoodbye();
        exitFlag = true;
        callMenu = -1;
        break;
      case 1:
        callMenu = 1;
        exitFlag = true;
        break;
      default:
        std::cout << "Invalid Input" << std::endl;
        break;
    }
    system("PAUSE");
  }
  return;
}
void UserInterface::sayGoodbye() {
  std::cout << "Goodbye" << std::endl;
  return;
}
void UserInterface::mainMenu() {
  bool exitFlag = false;
  std::cout << "Still in progress, goodbye" << std::endl;
  while (!exitFlag) {
    std::cout << "[1]\t Show Memory" << std::endl;
    std::cout << "[2]\t add new Expression" << std::endl;
    std::cout << "[3]\t calculate Expression" << std::endl;
    std::cout << "[0]\t return to upper menu" << std::endl;
    setOption();
    switch (getOption()) {
      case 0:
        exitFlag = true;
        std::cout << "Return to Upper Menu" << std::endl;
        break;
      case 1:
        butler->showMemory();
        // std::cout << "==================" <<std::endl;
        break;
      case 2: {
        std::cout << "Please input the symbol and expression" << std::endl;
        std::cout << "Format: sym expression" << std::endl;
        CalcCore::Polynomial temp;
        char sym;
        std::cin >> sym;
        std::cin >> temp;
        butler->storeIt(sym, temp);
        break;
      }
      default:
        std ::cout << "Invalid Input" << std::endl;
        break;
    }
    system("PAUSE");
  }
  callMenu = 0;
}
}  // namespace UI