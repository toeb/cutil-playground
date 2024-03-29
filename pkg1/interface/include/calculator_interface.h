#pragma once
#include <string>

#include "interface_export.h"

namespace calc{
  INTERFACE_EXPORT class ICalculator{
  public:
    virtual void clear()=0;
    virtual void add()=0;
    virtual void subtract()=0;
    virtual void number(double number)=0;
    virtual void enter()=0;
  protected:
    void print(const std::string & val);
  };
}
