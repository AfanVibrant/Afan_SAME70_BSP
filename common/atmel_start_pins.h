/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAME70 has 4 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3

#define PWM2_TC0A0_PA0 GPIO(GPIO_PORTA, 0)
#define PWM2_TC0B0_PA1 GPIO(GPIO_PORTA, 1)
#define PWM0_CHH1_PA2 GPIO(GPIO_PORTA, 2)
#define TWI0_SDA_PA3 GPIO(GPIO_PORTA, 3)
#define TWI0_SCK_PA4 GPIO(GPIO_PORTA, 4)
#define PWM1_CHL3_PA5 GPIO(GPIO_PORTA, 5)
#define PWM1_CHH3_PA8 GPIO(GPIO_PORTA, 8)
#define PWM1_CHL0_PA11 GPIO(GPIO_PORTA, 11)
#define PWM1_CHH0_PA12 GPIO(GPIO_PORTA, 12)
#define PWM1_CHL1_PA13 GPIO(GPIO_PORTA, 13)
#define PWM1_CHH1_PA14 GPIO(GPIO_PORTA, 14)
#define PWM2_TC0A1_PA15 GPIO(GPIO_PORTA, 15)
#define PWM2_TC0B1_PA16 GPIO(GPIO_PORTA, 16)
#define ADC0_CH06_PA17 GPIO(GPIO_PORTA, 17)
#define ADC0_CH07_PA18 GPIO(GPIO_PORTA, 18)
#define ADC0_CH08_PA19 GPIO(GPIO_PORTA, 19)
#define ADC0_CH09_PA20 GPIO(GPIO_PORTA, 20)
#define USART1_RX_PA21 GPIO(GPIO_PORTA, 21)
#define PWM1_CHL2_PA23 GPIO(GPIO_PORTA, 23)
#define PWM2_TC0A2_PA26 GPIO(GPIO_PORTA, 26)
#define PWM2_TC0B2_PA27 GPIO(GPIO_PORTA, 27)
#define PWM0_CHL2_PA30 GPIO(GPIO_PORTA, 30)
#define PWM1_CHH2_PA31 GPIO(GPIO_PORTA, 31)
#define ADC0_CH10_PB0 GPIO(GPIO_PORTB, 0)
#define ADC1_CH00_PB1 GPIO(GPIO_PORTB, 1)
#define CAN0_TX_PB2 GPIO(GPIO_PORTB, 2)
#define CAN0_RX_PB3 GPIO(GPIO_PORTB, 3)
#define USART1_TX_PB4 GPIO(GPIO_PORTB, 4)
#define PWM0_CHL0_PB5 GPIO(GPIO_PORTB, 5)
#define ADC1_CH09_PC0 GPIO(GPIO_PORTC, 0)
#define PWM0_CHL1_PC1 GPIO(GPIO_PORTC, 1)
#define PWM0_CHL3_PC3 GPIO(GPIO_PORTC, 3)
#define PWM4_TC2A6_PC5 GPIO(GPIO_PORTC, 5)
#define PWM4_TC2B6_PC6 GPIO(GPIO_PORTC, 6)
#define PWM4_TC2A7_PC8 GPIO(GPIO_PORTC, 8)
#define PWM4_TC2B7_PC9 GPIO(GPIO_PORTC, 9)
#define PHY_RESET_PIN GPIO(GPIO_PORTC, 10)
#define PWM4_TC2A8_PC11 GPIO(GPIO_PORTC, 11)
#define CAN1_RX_PC12 GPIO(GPIO_PORTC, 12)
#define ADC1_CH01_PC13 GPIO(GPIO_PORTC, 13)
#define CAN1_TX_PC14 GPIO(GPIO_PORTC, 14)
#define ADC1_CH02_PC15 GPIO(GPIO_PORTC, 15)
#define PHY_IRQ_PC18 GPIO(GPIO_PORTC, 18)
#define PWM0_CHH2_PC19 GPIO(GPIO_PORTC, 19)
#define ESC_SYNC0_PC20 GPIO(GPIO_PORTC, 20)
#define PWM0_CHH3_PC21 GPIO(GPIO_PORTC, 21)
#define ESC_SYNC1_PC22 GPIO(GPIO_PORTC, 22)
#define PWM3_TC1A3_PC23 GPIO(GPIO_PORTC, 23)
#define PWM3_TC1B3_PC24 GPIO(GPIO_PORTC, 24)
#define PWM3_TC1A4_PC26 GPIO(GPIO_PORTC, 26)
#define ADC1_CH08_PC27 GPIO(GPIO_PORTC, 27)
#define PWM3_TC1A5_PC29 GPIO(GPIO_PORTC, 29)
#define ADC1_CH05_PC30 GPIO(GPIO_PORTC, 30)
#define ADC1_CH06_PC31 GPIO(GPIO_PORTC, 31)
#define MAC_GTXCK_PD0 GPIO(GPIO_PORTD, 0)
#define MAC_GTXEN_PD1 GPIO(GPIO_PORTD, 1)
#define MAC_GTX0_PD2 GPIO(GPIO_PORTD, 2)
#define MAC_GTX1_PD3 GPIO(GPIO_PORTD, 3)
#define MAC_GRXDV_PD4 GPIO(GPIO_PORTD, 4)
#define MAC_GRX0_PD5 GPIO(GPIO_PORTD, 5)
#define MAC_GRX1_PD6 GPIO(GPIO_PORTD, 6)
#define MAC_GRXER_PD7 GPIO(GPIO_PORTD, 7)
#define MAC_GMDC_PD8 GPIO(GPIO_PORTD, 8)
#define MAC_GMDIO_PD9 GPIO(GPIO_PORTD, 9)
#define PWM0_CHH0_PD11 GPIO(GPIO_PORTD, 11)
#define CAN_RUN_LED GPIO(GPIO_PORTD, 12)
#define SPI0_CS_PD25 GPIO(GPIO_PORTD, 25)
#define WILC_INT_PD28 GPIO(GPIO_PORTD, 28)
#define WILC_RST_PD26 GPIO(GPIO_PORTD, 26)
#define WILC_ENB_PC13 GPIO(GPIO_PORTC, 13)
#define WILC_WKUP_PB2 GPIO(GPIO_PORTB, 2)
#define CAN_ERR_LED GPIO(GPIO_PORTD, 14)
#define SPI0_MISO_PD20 GPIO(GPIO_PORTD, 20)
#define SPI0_MOSI_PD21 GPIO(GPIO_PORTD, 21)
#define SPI0_SPCK_PD22 GPIO(GPIO_PORTD, 22)
#define ADC0_CH00_PD30 GPIO(GPIO_PORTD, 30)
#define ADC1_CH11_PE0 GPIO(GPIO_PORTE, 0)
#define PWM5_TC3B9_PE1 GPIO(GPIO_PORTE, 1)
#define PWM5_TC3A10_PE3 GPIO(GPIO_PORTE, 3)
#define ADC0_CH04_PE4 GPIO(GPIO_PORTE, 4)
#define ADC0_CH03_PE3 GPIO(GPIO_PORTE, 5)

#endif // ATMEL_START_PINS_H_INCLUDED
