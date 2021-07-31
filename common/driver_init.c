/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hpl_spi_base.h>
#include <hpl_usart_base.h>

struct can_async_descriptor CAN_Node0;
struct can_async_descriptor CAN_Node1;

struct spi_m_sync_descriptor SPI_0;

struct i2c_m_sync_desc I2C_AT24MAC;

struct usart_sync_descriptor TARGET_IO;

struct mac_async_descriptor MACIF;

void SPI_0_PORT_init(void)
{

	gpio_set_pin_function(SPI0_MISO_PD20, MUX_PD20B_SPI0_MISO);

	gpio_set_pin_function(SPI0_MOSI_PD21, MUX_PD21B_SPI0_MOSI);

	gpio_set_pin_function(SPI0_SPCK_PD22, MUX_PD22B_SPI0_SPCK);
}

void SPI_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_SPI0);
}

void SPI_0_init(void)
{
	SPI_0_CLOCK_init();
	spi_m_sync_set_func_ptr(&SPI_0, _spi_get_spi_m_sync());
	spi_m_sync_init(&SPI_0, SPI0);
	SPI_0_PORT_init();
}

void I2C_AT24MAC_PORT_init(void)
{

	gpio_set_pin_function(TWI0_SCK_PA4, MUX_PA4A_TWIHS0_TWCK0);

	gpio_set_pin_function(TWI0_SDA_PA3, MUX_PA3A_TWIHS0_TWD0);
}

void I2C_AT24MAC_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_TWIHS0);
}

void I2C_AT24MAC_init(void)
{
	I2C_AT24MAC_CLOCK_init();

	i2c_m_sync_init(&I2C_AT24MAC, TWIHS0);

	I2C_AT24MAC_PORT_init();
}

void TARGET_IO_PORT_init(void)
{

	gpio_set_pin_function(USART1_RX_PA21, MUX_PA21A_USART1_RXD1);

	gpio_set_pin_function(USART1_TX_PB4, MUX_PB4D_USART1_TXD1);
}

void TARGET_IO_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_USART1);
}

void TARGET_IO_init(void)
{
	TARGET_IO_CLOCK_init();
	TARGET_IO_PORT_init();
	usart_sync_init(&TARGET_IO, USART1, _usart_get_usart_sync());
}

void MACIF_PORT_init(void)
{

	gpio_set_pin_function(MAC_GMDC_PD8, MUX_PD8A_GMAC_GMDC);

	gpio_set_pin_function(MAC_GMDIO_PD9, MUX_PD9A_GMAC_GMDIO);

	gpio_set_pin_function(MAC_GRX0_PD5, MUX_PD5A_GMAC_GRX0);

	gpio_set_pin_function(MAC_GRX1_PD6, MUX_PD6A_GMAC_GRX1);

	gpio_set_pin_function(MAC_GRXDV_PD4, MUX_PD4A_GMAC_GRXDV);

	gpio_set_pin_function(MAC_GRXER_PD7, MUX_PD7A_GMAC_GRXER);

	gpio_set_pin_function(MAC_GTX0_PD2, MUX_PD2A_GMAC_GTX0);

	gpio_set_pin_function(MAC_GTX1_PD3, MUX_PD3A_GMAC_GTX1);

	gpio_set_pin_function(MAC_GTXCK_PD0, MUX_PD0A_GMAC_GTXCK);

	gpio_set_pin_function(MAC_GTXEN_PD1, MUX_PD1A_GMAC_GTXEN);
}

void MACIF_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_GMAC);
}

void MACIF_init(void)
{
	MACIF_CLOCK_init();
	mac_async_init(&MACIF, GMAC);
	MACIF_PORT_init();
}

/**
 * \brief MCAN Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void CAN_Node0_CLOCK_init()
{
	_pmc_enable_periph_clock(ID_MCAN0);
}

/**
 * \brief MCAN pinmux initialization function
 *
 * Set each required pin to MCAN functionality
 */
void CAN_Node0_PORT_init(void)
{

	gpio_set_pin_function(CAN0_RX_PB3, MUX_PB3A_MCAN0_CANRX0);

	gpio_set_pin_function(CAN0_TX_PB2, MUX_PB2A_MCAN0_CANTX0);
}
/**
 * \brief CAN initialization function
 *
 * Enables CAN peripheral, clocks and initializes CAN driver
 */
void CAN_Node0_init(void)
{
	CAN_Node0_CLOCK_init();
	CAN_Node0_PORT_init();
	can_async_init(&CAN_Node0, MCAN0);
}

/**
 * \brief MCAN Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void CAN_Node1_CLOCK_init()
{
	_pmc_enable_periph_clock(ID_MCAN1);
}

/**
 * \brief MCAN pinmux initialization function
 *
 * Set each required pin to MCAN functionality
 */
void CAN_Node1_PORT_init(void)
{

	gpio_set_pin_function(CAN1_RX_PC12, MUX_PC12C_MCAN1_CANRX1);

	gpio_set_pin_function(CAN1_TX_PC14, MUX_PC14C_MCAN1_CANTX1);
}
/**
 * \brief CAN initialization function
 *
 * Enables CAN peripheral, clocks and initializes CAN driver
 */
void CAN_Node1_init(void)
{
	CAN_Node1_CLOCK_init();
	CAN_Node1_PORT_init();
	can_async_init(&CAN_Node1, MCAN1);
}

void system_init(void)
{
	init_mcu();

	_pmc_enable_periph_clock(ID_PIOC);

	/* Disable Watchdog */
	hri_wdt_set_MR_WDDIS_bit(WDT);

	/* GPIO on PC18 */

	// Set pin direction to input
	gpio_set_pin_direction(PHY_IRQ_PC18, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PHY_IRQ_PC18,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PHY_IRQ_PC18, GPIO_PIN_FUNCTION_OFF);

	/* SPI0 Chip Selection on PD25 */

	gpio_set_pin_level(SPI0_CS_PD25,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(SPI0_CS_PD25, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(SPI0_CS_PD25, GPIO_PIN_FUNCTION_OFF);

	SPI_0_init();

	I2C_AT24MAC_init();

	TARGET_IO_init();

	MACIF_init();
	CAN_Node0_init();
	CAN_Node1_init();
}
