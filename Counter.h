/*
    Author: Max Brehm
*/
#ifndef _COUNTER_
#define _COUNTER_

/**
* @brief Class to demonstrate a counter which can be incremented and read
*/
class Counter
{
protected:
  int count; /**< attribute to store the current counter value */

public:
  /**
  * @brief Creates a Counter-Object if no start value is given to the constructor
  * the start value is 0
  * @param v is the initial counter value
  */
  Counter(int v=0) : count(v) {}

  /**
  * @brief Increments the counter value
  */
  void Inc() {count++;};

  /**
  * @brief returns the current counter value
  * @return the counter value
  */
  int GetValue() {return count;};
};
#endif
