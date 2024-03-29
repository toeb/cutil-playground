
#include <simple_calc.h>
using namespace simple_calc;
enum class CurrentOperation{
  none,
  add,
  subtract
};

struct SimpleCalculator::pimpl{
  double accu;
  double number;
  CurrentOperation op;
};



SimpleCalculator::SimpleCalculator():_self(new pimpl){}
SimpleCalculator::~SimpleCalculator(){ delete _self; }

void SimpleCalculator::enter(){
  _self->accu = 0.0;
  _self->op = CurrentOperation::none;
}
void SimpleCalculator::clear(){
  _self->op = CurrentOperation::none;
  _self->number = 0.0;
  _self->accu = 0.0;
}
void SimpleCalculator::add(){
  _self->op = CurrentOperation::add;
}
void SimpleCalculator::subtract(){
  _self->op = CurrentOperation::subtract;

}
void SimpleCalculator::number(double number){
  _self->number = number;
}


