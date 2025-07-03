#pragma once

#include "wiring_analog.h"
#include <MeshCore.h>
#include <Arduino.h>
#include <cstdint>

#define P_LORA_NSS 12 //P1.11
#define P_LORA_DIO_1 15 //P0.02
#define P_LORA_RESET 14 //P1.15
#define P_LORA_BUSY  13 //P1.13
#define P_LORA_MISO  7 //P0.11
#define P_LORA_SCLK  8 //P1.04
#define P_LORA_MOSI  6 //P1.00
#define P_LORA_RF_SW 11 //P0.10
#define SX126X_POWER_EN PIN_EXT_VCC
#define SX126X_TXEN RADIOLIB_NC
#define SX126X_DIO2_AS_RF_SWITCH  true
#define SX126X_DIO3_TCXO_VOLTAGE   1.8

class BricktecBoard : public mesh::MainBoard {
protected:
  uint8_t startup_reason;

public:

  void begin();
  uint16_t getBattMilliVolts() override {
    // The promicro has unpopulated voltage dividers, so we must read the
    // voltage directly from internal power supply pins using VDDHDIV5 and VDD

    // Unfortunately, analogReadVDDHDIV5() is not available because PlatformIO
    // has not yet updated the version of Adafruit_nRF52_Arduino to 1.7.0

    // The VDD is downstream from an LDO voltage regulator should always be
    // between 3.3V to about 1.8V, where the chip will brown out reset.

    // adc range is 0 to 3.6V with 4096 - 1 as max
    analogReadResolution(12);
    uint32_t vddAnalogReading = analogReadVDD();
    float divisor = 4095.0/3600.0;
    uint16_t millivolts = vddAnalogReading / divisor;

    // Treat anything above about 3.25V as 100%
    if (vddAnalogReading >= 3250) {
      return 4200;
    }
    else {
      return vddAnalogReading / divisor ;
    }
  }
  bool startOTAUpdate(const char* id, char reply[]) override;

  uint8_t getStartupReason() const override {
    return startup_reason;
  }

  const char* getManufacturerName() const override {
    return "Bricktec DIY";
  }

  void reboot() override {
    NVIC_SystemReset();
  }
};
