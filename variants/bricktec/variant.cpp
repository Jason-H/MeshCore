#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

// use https://github.com/pdcook/nRFMicro-Arduino-Core numbering convention
// Note that peripherals are mapped differently in variant.h
const uint32_t g_ADigitalPinMap[] = {
  6, 8, 17, 20, 22, 24, 32, 11, 36, 38, // d0-d9
  9, 10, 43, 45, 47, 2, 29, 31, // d10-17
  33, 34, 37, // d18-20
  13, 15 // d21-22 (ext power, led)
};

void initVariant()
{
}

