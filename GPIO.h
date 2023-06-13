/*
    Author: Tim Göhringer
*/
#include <stdint.h>
#include <stdio.h>
#include "Def.h"

#ifndef _GPIO_
#define _GPIO_

/**
* @brief Class to directly control the GPIO Ports and Pins
*/
class GPIO
{
  private:
    volatile uint32_t* GPIOx_MODER;    /**< GPIOx mode register */
    volatile uint32_t* GPIOx_OTYPER;   /**< GPIOx output type register */
    volatile uint32_t* GPIOx_OSPEEDR;  /**< GPIOx output speed register */
    volatile uint32_t* GPIOx_PUPDR;    /**< GPIOx pull-up/pull-down register */
    volatile uint32_t* GPIOx_IDR;      /**< GPIOx Input Data Register */
    volatile uint32_t* GPIOx_ODR;      /**< GPIOx Output Data Register */
    volatile uint32_t* GPIOx_BSRRL;    /**< GPIOx bit set/reset low register */
    volatile uint32_t* GPIOx_BSRRH;    /**< GPIOx bit set/reset high register */
    volatile uint32_t* RCC_AHB1ENR;    /**< GPIOx Clock enable register */
public:
  /**
  *   @param GPIOx_BASE The Base Adress of the GPIO Port
  */
  GPIO(uint32_t GPIOx_BASE)
    : GPIOx_MODER((volatile uint32_t*) GPIOx_BASE),
      GPIOx_OTYPER(GPIOx_MODER + 1),
      GPIOx_OSPEEDR(GPIOx_MODER + 2),
      GPIOx_PUPDR(GPIOx_MODER + 3),
      GPIOx_IDR(GPIOx_MODER + 4),
      GPIOx_ODR(GPIOx_MODER + 5),
      GPIOx_BSRRL((volatile uint32_t*) (GPIOx_BASE + 0x18)),
      GPIOx_BSRRH((volatile uint32_t*) (GPIOx_BASE + 0x1A)),
      RCC_AHB1ENR((volatile uint32_t*) 0x40023830)
  {
    // Calculate which CLock should be activated
    uint32_t registerByte = (GPIOx_BASE & 0xFF00) >> 8;
    int registerNumber = (registerByte) / 0x04;
    // Activate the corresponding Bit
    *RCC_AHB1ENR |= (0x01 << registerNumber);
  }

  /**
  * @brief Configurates a Pin on the GPIO-Port by the given configuration values
  * @param pin The pin to be configured
  * @param mode 0 for Input, 1 for Output
  * @param outputType 0 for Push-Pull, 1 for Open-Drain
  * @param speed 0 for low speed
  * @param pull 0 no Pull-Up/Pull-down, 1 for Pull-Up, 2 for Pull-Down
  */
   void configurePin(uint8_t pin, uint8_t mode, uint8_t outputType, uint8_t speed, uint8_t pull) {
        // Calculate register offset for the specified pin
        uint32_t offset = pin * 2;

        // Configure pin mode
        *GPIOx_MODER &= ~(0x03 << offset);    // Clear mode bits
        *GPIOx_MODER |= (mode << offset);     // Set mode bits

        // Configure output type
        *GPIOx_OTYPER &= ~(0x01 << pin);      // Clear output type bit
        *GPIOx_OTYPER |= (outputType << pin); // Set output type bit

        // Configure output speed
        *GPIOx_OSPEEDR &= ~(0x03 << offset);  // Clear speed bits
        *GPIOx_OSPEEDR |= (speed << offset);  // Set speed bits

        // Configure pull-up/pull-down
        *GPIOx_PUPDR &= ~(0x03 << offset);    // Clear pull bits
        *GPIOx_PUPDR |= (pull << offset);     // Set pull bits
    }

    /**
    * @brief Sets each pin of the port to either input or output
    * Other Settings are: Push-Pull, 2MHz low speed, no Pull-Up/Pull-Down
    * @param mask The mask to set the individual pins, 0 for input, 1 for Output
    */
    void configurePort(uint16_t mask){
      if (GPIOx_MODER == (volatile uint32_t*)Def::enumPort::PortA){
        for (int i = 0; i < 16; ++i) {
          int bit = (mask >> i) & 1;
          if(i == 13 or i == 14){
            configurePin(i, 2, 0, 0, 0);
          }
          else{
            configurePin(i, bit, 0, 0, 0);
          }
        }
      }
      else{
        for (int i = 0; i < 16; ++i) {
          int bit = (mask >> i) & 1;
          configurePin(i, bit, 0, 0, 0);
        }
      }
    }

    /**
    * @brief Sets the desired Output Pin to High
    * @param pin The Pin to be set
    */
   void setPin(uint16_t pin) {
        *GPIOx_BSRRL |= (0x01 << pin);  // Set pin
    }

    /**
    * @brief Sets the desired output Pin to low
    * @param pin The Pin to be reset
    */
    void resetPin(uint16_t pin) {
        *GPIOx_BSRRH |= (0x01 << pin);  // Reset pin
    }

    /**
    * @brief Toggles the desired Output Pin
    * @param pin The Pin to be toggled
    */
    void togglePin(uint16_t pin) {
      *GPIOx_ODR ^= (0x01 << pin);
    }

    /**
    * @brief Sets multiple Output Pins at once, depending on the mask
    * @param mask Mask to select which Pins to set
    */
    void setPort(uint16_t mask){
      *GPIOx_ODR = mask;
    }

    /**
    * @brief Get the states of all inputs of a specific port
    * @return The currently active inputs
    */
    uint16_t getPort(){

      return *GPIOx_IDR & 0xFFFF;
    }
};
#endif


