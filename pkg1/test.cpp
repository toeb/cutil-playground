#include <iostream>
#include <calculator_interface.h>
#include <simple_calc.h>


int main(){
  std::cout << "test successful" << std::endl;
  calc::ICalculator * calc = new simple_calc::SimpleCalculator();
  return 0;
}