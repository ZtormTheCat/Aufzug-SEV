//ModCounter.h
#include "counter.h"

#ifndef _MODCOUNTER_
#define _MODCOUNTER_
class ModCounter : public Counter
{
private:
  int modVal;
  
public:
  ModCounter(int _modVal = 4) : modVal(_modVal) {}
  
  void Inc() {count = (count + 1)%modVal;}

};
#endif