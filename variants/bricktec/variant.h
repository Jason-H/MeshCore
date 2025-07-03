/*
 * variant.h
 * Copyright (C) 2023 Seeed K.K.
 * MIT License
 */

#pragma once

#include "WVariant.h"

////////////////////////////////////////////////////////////////////////////////
// Low frequency clock source

#define VARIANT_MCK       (64000000ul)

//#define USE_LFXO      // 32.768 kHz crystal oscillator
#define USE_LFRC    // 32.768 kHz RC oscillator

////////////////////////////////////////////////////////////////////////////////
// Power

#define PIN_EXT_VCC          (21)
#define EXT_VCC              (PIN_EXT_VCC)

// Supermini/Promicro boards have no voltage dividers, so it floats.
#define BATTERY_PIN          (17)
#define ADC_RESOLUTION       12

////////////////////////////////////////////////////////////////////////////////
// Number of pins

#define PINS_COUNT           (23)
#define NUM_DIGITAL_PINS     (23)
#define NUM_ANALOG_INPUTS    (3)
#define NUM_ANALOG_OUTPUTS   (0)

////////////////////////////////////////////////////////////////////////////////
// UART pin definition

#define PIN_SERIAL1_TX       (0)
#define PIN_SERIAL1_RX       (1)

////////////////////////////////////////////////////////////////////////////////
// I2C pin definition

#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (3)
#define PIN_WIRE_SCL         (4)
//#define PIN_WIRE1_SDA        (13)
//#define PIN_WIRE1_SCL        (14)

////////////////////////////////////////////////////////////////////////////////
// SPI pin definition

#define SPI_INTERFACES_COUNT 2

#define PIN_SPI_SCK          (8)
#define PIN_SPI_MISO         (7)
#define PIN_SPI_MOSI         (6)

#define PIN_SPI_NSS          (12)

#define PIN_SPI1_SCK         (18)
#define PIN_SPI1_MISO        (19)
#define PIN_SPI1_MOSI        (20)

////////////////////////////////////////////////////////////////////////////////
// Builtin LEDs

#define PIN_LED              (22)
#define LED_PIN              PIN_LED
#define LED_BLUE             PIN_LED
#define LED_BUILTIN          PIN_LED
#define LED_STATE_ON         LOW

////////////////////////////////////////////////////////////////////////////////
// Builtin buttons

#define PIN_BUTTON1          (16)
#define BUTTON_PIN           PIN_BUTTON1

/////////////////////////////////////////////////////////////////////////////////
// LORA

