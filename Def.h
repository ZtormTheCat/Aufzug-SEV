/*

Author: Felix Trautwein

Namespace for Standard-Parameters. Usage:

- Preprocessor -
#include "Def.h"
using namespace Def;(optional)

- Code -
Def::<enumClass>::<Enum>
*/

#ifndef _DEF_
#define _DEF_
namespace Def
{
    const enum enumPort
    {
        PortA = 0x40020000,
        PortB = 0x40020400,
    };

    const enum enumLED
    {
        Bin0 = 0b00000000,
        Bin1,
        Bin2,
        Bin3,
        Bin4,
        Bin5,
        Bin6,
        Bin7,
    };

    const enum enumButton
    {

    };

    const enum enumMotorZustand
    {
        Still = 0,
        Rauf = 1,
        Runter = 2
    };

    const enum op_mode{
      // 0 = Debug, 1 = Release
      enable = 1
    };
};
#endif
