#include "counter.h"

#ifndef _MODCOUNTER_
#define _MODCOUNTER_

/**
* @brief Class to demonstrate a modulo counter which inheritates from the Counter-Class
*/
class ModCounter : public Counter
{
  private:
    int modVal; /**< the number which is used to module divide the count value */

  public:
    /**
    * @brief Creates a ModCounter-Object if no start modVal is given to the constructor
    * the start value is 4
    * @param v is the value by which the count is modulo divided at increment
    */
    ModCounter(int _modVal = 4) : modVal(_modVal) {}

    /**
    * @brief Increments the counter value and modulo divides it by modVal
    */
    void Inc() {count = (count + 1)%modVal;}

};
#endif