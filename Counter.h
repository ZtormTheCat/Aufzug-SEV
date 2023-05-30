//Counter.h

#ifndef _COUNTER_
#define _COUNTER_
class Counter
{
protected:
  int count;
    
public:
  Counter(int v=0) : count(v) {}
  
  void Inc() {count++;};
  int GetValue() {return count;};
};
#endif