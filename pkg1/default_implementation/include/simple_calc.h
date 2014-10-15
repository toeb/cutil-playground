#pragma once

#include <memory>
#include <calculator_interface.h>


namespace simple_calc{
  class SimpleCalculator : public calc::ICalculator{
  public:
    SimpleCalculator();
    ~SimpleCalculator();
    void clear()override;
    void add()override;
    void subtract()override;
    void number(double number)override;
    void enter()override;
  private:
    struct pimpl;
    pimpl* _self;
  };
}