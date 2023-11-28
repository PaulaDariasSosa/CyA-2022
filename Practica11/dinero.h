#include <list>

#ifndef DINERO_H_
#define DINERO_H_

class dinero {
 public:
   dinero(float valor);
   float get_valor() {return valor_;} 
 private:
  float valor_;
};


#endif