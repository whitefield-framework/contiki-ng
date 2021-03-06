/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       CC1350DK_7XD.h
 *
 *  @brief      CC2650 LaunchPad Board Specific header file.
 *
 *  The CC1350DK_7XD header file should be included in an application as
 *  follows:
 *  @code
 *  #include "CC1350DK_7XD.h"
 *  @endcode
 *
 *  ============================================================================
 */
#ifndef __CC1350DK_7XD_BOARD_H__
#define __CC1350DK_7XD_BOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "contiki-conf.h"

/* Includes */
#include <ti/drivers/PIN.h>
#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/ioc.h)

/* Externs */
extern const PIN_Config BoardGpioInitTable[];

/* Defines */
#define CC1350DK_7XD

/* Mapping of pins to board signals using general board aliases
 *      <board signal alias>        <pin mapping>   <comments>
 */

/* Analog Capable DIOs */
#define CC1350DK_7XD_DIO23_ANALOG          IOID_23
#define CC1350DK_7XD_DIO24_ANALOG          IOID_24
#define CC1350DK_7XD_DIO25_ANALOG          IOID_25
#define CC1350DK_7XD_DIO26_ANALOG          IOID_26
#define CC1350DK_7XD_DIO27_ANALOG          IOID_27
#define CC1350DK_7XD_DIO28_ANALOG          IOID_28
#define CC1350DK_7XD_DIO29_ANALOG          IOID_29
#define CC1350DK_7XD_DIO30_ANALOG          IOID_30

/* Digital IOs */
#define CC1350DK_7XD_DIO0                  IOID_0
#define CC1350DK_7XD_DIO1_RFSW             IOID_1
#define CC1350DK_7XD_DIO12                 IOID_12
#define CC1350DK_7XD_DIO15                 IOID_15
#define CC1350DK_7XD_DIO16_TDO             IOID_16
#define CC1350DK_7XD_DIO17_TDI             IOID_17
#define CC1350DK_7XD_DIO21                 IOID_21
#define CC1350DK_7XD_DIO22                 IOID_22

/* Discrete Inputs */
#define CC1350DK_7XD_PIN_KEY_SELECT        IOID_11
#define CC1350DK_7XD_PIN_KEY_UP            IOID_19
#define CC1350DK_7XD_PIN_KEY_DOWN          IOID_12
#define CC1350DK_7XD_PIN_KEY_LEFT          IOID_15
#define CC1350DK_7XD_PIN_KEY_RIGHT         IOID_18

/* GPIO */
#define CC1350DK_7XD_GPIO_LED_ON           1
#define CC1350DK_7XD_GPIO_LED_OFF          0

/* I2C */
#define CC1350DK_7XD_I2C0_SCL0             PIN_UNASSIGNED
#define CC1350DK_7XD_I2C0_SDA0             PIN_UNASSIGNED

/* I2S */
#define CC1350DK_7XD_I2S_ADO               PIN_UNASSIGNED
#define CC1350DK_7XD_I2S_ADI               PIN_UNASSIGNED
#define CC1350DK_7XD_I2S_BCLK              PIN_UNASSIGNED
#define CC1350DK_7XD_I2S_MCLK              PIN_UNASSIGNED
#define CC1350DK_7XD_I2S_WCLK              PIN_UNASSIGNED

/* LEDs */
#define CC1350DK_7XD_PIN_LED_ON            1
#define CC1350DK_7XD_PIN_LED_OFF           0
#define CC1350DK_7XD_PIN_LED1              IOID_25
#define CC1350DK_7XD_PIN_LED2              IOID_27
#define CC1350DK_7XD_PIN_LED3              IOID_7
#define CC1350DK_7XD_PIN_LED4              IOID_6

/* PWM Outputs */
#define CC1350DK_7XD_PWMPIN0               CC1350DK_7XD_PIN_LED1
#define CC1350DK_7XD_PWMPIN1               CC1350DK_7XD_PIN_LED2
#define CC1350DK_7XD_PWMPIN2               CC1350DK_7XD_PIN_LED3
#define CC1350DK_7XD_PWMPIN3               CC1350DK_7XD_PIN_LED4
#define CC1350DK_7XD_PWMPIN4               PIN_UNASSIGNED
#define CC1350DK_7XD_PWMPIN5               PIN_UNASSIGNED
#define CC1350DK_7XD_PWMPIN6               PIN_UNASSIGNED
#define CC1350DK_7XD_PWMPIN7               PIN_UNASSIGNED

/* SPI Board */
#define CC1350DK_7XD_SPI0_MISO             IOID_8
#define CC1350DK_7XD_SPI0_MOSI             IOID_9
#define CC1350DK_7XD_SPI0_CLK              IOID_10
#define CC1350DK_7XD_SPI0_CSN              PIN_UNASSIGNED
#define CC1350DK_7XD_SPI1_MISO             PIN_UNASSIGNED
#define CC1350DK_7XD_SPI1_MOSI             PIN_UNASSIGNED
#define CC1350DK_7XD_SPI1_CLK              PIN_UNASSIGNED
#define CC1350DK_7XD_SPI1_CSN              PIN_UNASSIGNED

/* UART Board */
#define CC1350DK_7XD_UART_RX               IOID_2
#define CC1350DK_7XD_UART_TX               IOID_3
#define CC1350DK_7XD_UART_CTS              IOID_22
#define CC1350DK_7XD_UART_RTS              IOID_21

/* SD Card */
#define CC1350DK_7XD_SPI_SDCARD_CS         IOID_30
#define CC1350DK_7XD_SDCARD_CS_ON          0
#define CC1350DK_7XD_SDCARD_CS_OFF         1

/* Ambient Light Sensor */
#define CC1350DK_7XD_ALS_OUT               IOID_23
#define CC1350DK_7XD_ALS_PWR               IOID_26

/* Accelerometer */
#define CC1350DK_7XD_ACC_PWR               IOID_20
#define CC1350DK_7XD_ACC_CS                IOID_24

/*!
 *  @brief  Initialize the general board specific settings
 *
 *  This function initializes the general board specific settings.
 */
void CC1350DK_7XD_initGeneral(void);

/*!
 *  @brief  Turn off the external flash on LaunchPads
 *
 */
void CC1350DK_7XD_shutDownExtFlash(void);

/*!
 *  @brief  Wake up the external flash present on the board files
 *
 *  This function toggles the chip select for the amount of time needed
 *  to wake the chip up.
 */
void CC1350DK_7XD_wakeUpExtFlash(void);

/*!
 *  @def    CC1350DK_7XD_ADCBufName
 *  @brief  Enum of ADCBufs
 */
typedef enum CC1350DK_7XD_ADCBufName {
    CC1350DK_7XD_ADCBUF0 = 0,

    CC1350DK_7XD_ADCBUFCOUNT
} CC1350DK_7XD_ADCBufName;

/*!
 *  @def    CC1350DK_7XD_ADCBuf0ChannelName
 *  @brief  Enum of ADCBuf channels
 */
typedef enum CC1350DK_7XD_ADCBuf0ChannelName {
    CC1350DK_7XD_ADCBUF0CHANNELADCALS = 0,
    CC1350DK_7XD_ADCBUF0CHANNELVDDS,
    CC1350DK_7XD_ADCBUF0CHANNELDCOUPL,
    CC1350DK_7XD_ADCBUF0CHANNELVSS,

    CC1350DK_7XD_ADCBUF0CHANNELCOUNT
} CC1350DK_7XD_ADCBuf0ChannelName;

/*!
 *  @def    CC1350DK_7XD_ADCName
 *  @brief  Enum of ADCs
 */
typedef enum CC1350DK_7XD_ADCName {
    CC1350DK_7XD_ADCALS = 0,
    CC1350DK_7XD_ADCDCOUPL,
    CC1350DK_7XD_ADCVSS,
    CC1350DK_7XD_ADCVDDS,

    CC1350DK_7XD_ADCCOUNT
} CC1350DK_7XD_ADCName;

/*!
 *  @def    CC1350DK_7XD_CryptoName
 *  @brief  Enum of Crypto names
 */
typedef enum CC1350DK_7XD_CryptoName {
    CC1350DK_7XD_CRYPTO0 = 0,

    CC1350DK_7XD_CRYPTOCOUNT
} CC1350DK_7XD_CryptoName;

/*!
 *  @def    CC1350DK_7XD_AESCCMName
 *  @brief  Enum of AESCCM names
 */
typedef enum CC1350DK_7XD_AESCCMName {
    CC1350DK_7XD_AESCCM0 = 0,

    CC1350DK_7XD_AESCCMCOUNT
} CC1350DK_7XD_AESCCMName;

/*!
 *  @def    CC1350DK_7XD_AESGCMName
 *  @brief  Enum of AESGCM names
 */
typedef enum CC1350DK_7XD_AESGCMName {
    CC1350DK_7XD_AESGCM0 = 0,

    CC1350DK_7XD_AESGCMCOUNT
} CC1350DK_7XD_AESGCMName;

/*!
 *  @def    CC1350DK_7XD_AESCBCName
 *  @brief  Enum of AESCBC names
 */
typedef enum CC1350DK_7XD_AESCBCName {
    CC1350DK_7XD_AESCBC0 = 0,

    CC1350DK_7XD_AESCBCCOUNT
} CC1350DK_7XD_AESCBCName;

/*!
 *  @def    CC1350DK_7XD_AESCTRName
 *  @brief  Enum of AESCTR names
 */
typedef enum CC1350DK_7XD_AESCTRName {
    CC1350DK_7XD_AESCTR0 = 0,

    CC1350DK_7XD_AESCTRCOUNT
} CC1350DK_7XD_AESCTRName;

/*!
 *  @def    CC1350DK_7XD_AESECBName
 *  @brief  Enum of AESECB names
 */
typedef enum CC1350DK_7XD_AESECBName {
    CC1350DK_7XD_AESECB0 = 0,

    CC1350DK_7XD_AESECBCOUNT
} CC1350DK_7XD_AESECBName;

/*!
 *  @def    CC1350DK_7XD_AESCTRDRBGName
 *  @brief  Enum of AESCTRDRBG names
 */
typedef enum CC1350DK_7XD_AESCTRDRBGName {
    CC1350DK_7XD_AESCTRDRBG0 = 0,

    CC1350DK_7XD_AESCTRDRBGCOUNT
} CC1350DK_7XD_AESCTRDRBGName;

/*!
 *  @def    CC1350DK_7XD_TRNGName
 *  @brief  Enum of TRNG names
 */
typedef enum CC1350DK_7XD_TRNGName {
    CC1350DK_7XD_TRNG0 = 0,

    CC1350DK_7XD_TRNGCOUNT
} CC1350DK_7XD_TRNGName;

/*!
 *  @def    CC1350DK_7XD_GPIOName
 *  @brief  Enum of GPIO names
 */
typedef enum CC1350DK_7XD_GPIOName {
    CC1350DK_7XD_GPIO_KEY_SELECT = 0,
    CC1350DK_7XD_GPIO_KEY_UP,
    CC1350DK_7XD_GPIO_KEY_DOWN,
    CC1350DK_7XD_GPIO_KEY_LEFT,
    CC1350DK_7XD_GPIO_KEY_RIGHT,
    CC1350DK_7XD_SPI_MASTER_READY,
    CC1350DK_7XD_SPI_SLAVE_READY,
    CC1350DK_7XD_GPIO_LED1,
    CC1350DK_7XD_GPIO_LED2,
    CC1350DK_7XD_GPIO_LED3,
    CC1350DK_7XD_GPIO_LED4,
    CC1350DK_7XD_SDSPI_CS,
    CC1350DK_7XD_GPIO_ACC_CS,

    CC1350DK_7XD_GPIOCOUNT
} CC1350DK_7XD_GPIOName;

/*!
 *  @def    CC1350DK_7XD_GPTimerName
 *  @brief  Enum of GPTimer parts
 */
typedef enum CC1350DK_7XD_GPTimerName {
    CC1350DK_7XD_GPTIMER0A = 0,
    CC1350DK_7XD_GPTIMER0B,
    CC1350DK_7XD_GPTIMER1A,
    CC1350DK_7XD_GPTIMER1B,
    CC1350DK_7XD_GPTIMER2A,
    CC1350DK_7XD_GPTIMER2B,
    CC1350DK_7XD_GPTIMER3A,
    CC1350DK_7XD_GPTIMER3B,

    CC1350DK_7XD_GPTIMERPARTSCOUNT
} CC1350DK_7XD_GPTimerName;

/*!
 *  @def    CC1350DK_7XD_GPTimers
 *  @brief  Enum of GPTimers
 */
typedef enum CC1350DK_7XD_GPTimers {
    CC1350DK_7XD_GPTIMER0 = 0,
    CC1350DK_7XD_GPTIMER1,
    CC1350DK_7XD_GPTIMER2,
    CC1350DK_7XD_GPTIMER3,

    CC1350DK_7XD_GPTIMERCOUNT
} CC1350DK_7XD_GPTimers;

/*!
 *  @def    CC1350DK_7XD_I2CName
 *  @brief  Enum of I2C names
 */
typedef enum CC1350DK_7XD_I2CName {
#if TI_I2C_CONF_I2C0_ENABLE
    CC1350DK_7XD_I2C0 = 0,
#endif

    CC1350DK_7XD_I2CCOUNT
} CC1350DK_7XD_I2CName;

/*!
 *  @def    CC1350DK_7XD_I2SName
 *  @brief  Enum of I2S names
 */
typedef enum CC1350DK_7XD_I2SName {
    CC1350DK_7XD_I2S0 = 0,

    CC1350DK_7XD_I2SCOUNT
} CC1350DK_7XD_I2SName;

/*!
 *  @def    CC1350DK_7XD_NVSName
 *  @brief  Enum of NVS names
 */
typedef enum CC1350DK_7XD_NVSName {
#if TI_NVS_CONF_NVS_INTERNAL_ENABLE
    CC1350DK_7XD_NVSCC26XX0 = 0,
#endif

    CC1350DK_7XD_NVSCOUNT
} CC1350DK_7XD_NVSName;

/*!
 *  @def    CC1350DK_7XD_PWMName
 *  @brief  Enum of PWM outputs
 */
typedef enum CC1350DK_7XD_PWMName {
    CC1350DK_7XD_PWM0 = 0,
    CC1350DK_7XD_PWM1,
    CC1350DK_7XD_PWM2,
    CC1350DK_7XD_PWM3,
    CC1350DK_7XD_PWM4,
    CC1350DK_7XD_PWM5,
    CC1350DK_7XD_PWM6,
    CC1350DK_7XD_PWM7,

    CC1350DK_7XD_PWMCOUNT
} CC1350DK_7XD_PWMName;

/*!
 *  @def    CC1350DK_7XD_SDName
 *  @brief  Enum of SD names
 */
typedef enum CC1350DK_7XD_SDName {
    CC1350DK_7XD_SDSPI0 = 0,

    CC1350DK_7XD_SDCOUNT
} CC1350DK_7XD_SDName;

/*!
 *  @def    CC1350DK_7XD_SPIName
 *  @brief  Enum of SPI names
 */
typedef enum CC1350DK_7XD_SPIName {
#if TI_SPI_CONF_SPI0_ENABLE
    CC1350DK_7XD_SPI0 = 0,
#endif
#if TI_SPI_CONF_SPI1_ENABLE
    CC1350DK_7XD_SPI1,
#endif

    CC1350DK_7XD_SPICOUNT
} CC1350DK_7XD_SPIName;

/*!
 *  @def    CC1350DK_7XD_UARTName
 *  @brief  Enum of UARTs
 */
typedef enum CC1350DK_7XD_UARTName {
#if TI_UART_CONF_UART0_ENABLE
    CC1350DK_7XD_UART0 = 0,
#endif

    CC1350DK_7XD_UARTCOUNT
} CC1350DK_7XD_UARTName;

/*!
 *  @def    CC1350DK_7XD_UDMAName
 *  @brief  Enum of DMA buffers
 */
typedef enum CC1350DK_7XD_UDMAName {
    CC1350DK_7XD_UDMA0 = 0,

    CC1350DK_7XD_UDMACOUNT
} CC1350DK_7XD_UDMAName;

/*!
 *  @def    CC1350DK_7XD_WatchdogName
 *  @brief  Enum of Watchdogs
 */
typedef enum CC1350DK_7XD_WatchdogName {
    CC1350DK_7XD_WATCHDOG0 = 0,

    CC1350DK_7XD_WATCHDOGCOUNT
} CC1350DK_7XD_WatchdogName;

#ifdef __cplusplus
}
#endif

#endif /* __CC1350DK_7XD_BOARD_H__ */
