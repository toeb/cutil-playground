#include <calculator_interface.h>


class imp : public calc::ICalculator{
public:
  void clear()override{}
  void add()override{}
  void subtract()override{}
  void number(double number)override{}
  void enter()override{ print("muu"); }
};
int main(){
  imp i;
  i.enter();
}