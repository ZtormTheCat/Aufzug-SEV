#include <stdint.h>
#include <stdio.h>

class GPIO
{
  private:
    volatile uint32_t* GPIOx_MODER;    // GPIOx mode register
    volatile uint32_t* GPIOx_OTYPER;   // GPIOx output type register
    volatile uint32_t* GPIOx_OSPEEDR;  // GPIOx output speed register
    volatile uint32_t* GPIOx_PUPDR;    // GPIOx pull-up/pull-down register
    volatile uint32_t* GPIOx_IDR;      // GPIOx Input Data Register
    volatile uint32_t* GPIOx_ODR;      // GPIOx Output Data Register
    volatile uint32_t* GPIOx_BSRRL;    // GPIOx bit set/reset low register
    volatile uint32_t* GPIOx_BSRRH;    // GPIOx bit set/reset high register
    volatile uint32_t* RCC_AHB1ENR;    // GPIOx Clock enable register
public:
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
    *RCC_AHB1ENR |= (0x01 << 0);
  }

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

    void configurePort(uint16_t mask){
      uint32_t expanded = 0;
      // Insert a 0 before every bit to easily set every GPIO Pin to either Out- or input
      for (int i = 0; i < 16; ++i) {
        expanded <<= 2;
        expanded |= mask & 0b1;
        mask >>= 1;
    }
    *GPIOx_MODER = 0xFFFFFFFF;
    *GPIOx_OTYPER = 0x00000000;
    *GPIOx_OSPEEDR = 0x00000000;
    *GPIOx_PUPDR = 0x00000000;
    }

   void setPin(uint8_t pin) {
        *GPIOx_BSRRL |= (0x01 << pin);  // Set pin
    }

    void resetPin(uint8_t pin) {
        *GPIOx_BSRRH |= (0x01 << pin);  // Reset pin
    }

    void togglePin(uint8_t pin) {
      *GPIOx_ODR ^= (0x01 << pin);
    }

    //
    void setPort(uint16_t mask){
      *GPIOx_ODR = mask;
    }

    uint16_t getPort(){
      return *GPIOx_IDR & 0xFFFF;
    }
};


