/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example of using ADC0 to generate waveform.
 */
void ADC0_example(void)
{
	uint8_t buffer_ch0[2];
	uint8_t buffer_ch1[2];
	uint8_t buffer_ch3[2];
	uint8_t buffer_ch4[2];
	uint8_t buffer_ch7[2];
	uint8_t buffer_ch8[2];
	uint8_t buffer_ch9[2];
	uint8_t buffer_ch10[2];

	adc_sync_enable_channel(&ADC0, CONF_ADC0_CHANNEL_0);
	adc_sync_enable_channel(&ADC0, CONF_ADC0_CHANNEL_1);
	adc_sync_enable_channel(&ADC0, CONF_ADC0_CHANNEL_3);
	adc_sync_enable_channel(&ADC0, CONF_ADC0_CHANNEL_4);
	adc_sync_enable_channel(&ADC0, CONF_ADC0_CHANNEL_7);
	adc_sync_enable_channel(&ADC0, CONF_ADC0_CHANNEL_8);
	adc_sync_enable_channel(&ADC0, CONF_ADC0_CHANNEL_9);
	adc_sync_enable_channel(&ADC0, CONF_ADC0_CHANNEL_10);

	while (1) {
		adc_sync_read_channel(&ADC0, CONF_ADC0_CHANNEL_0, buffer_ch0, 2);
		adc_sync_read_channel(&ADC0, CONF_ADC0_CHANNEL_1, buffer_ch1, 2);
		adc_sync_read_channel(&ADC0, CONF_ADC0_CHANNEL_3, buffer_ch3, 2);
		adc_sync_read_channel(&ADC0, CONF_ADC0_CHANNEL_4, buffer_ch4, 2);
		adc_sync_read_channel(&ADC0, CONF_ADC0_CHANNEL_7, buffer_ch7, 2);
		adc_sync_read_channel(&ADC0, CONF_ADC0_CHANNEL_8, buffer_ch8, 2);
		adc_sync_read_channel(&ADC0, CONF_ADC0_CHANNEL_9, buffer_ch9, 2);
		adc_sync_read_channel(&ADC0, CONF_ADC0_CHANNEL_10, buffer_ch10, 2);
	}
}

/**
 * Example of using ADC1 to generate waveform.
 */
void ADC1_example(void)
{
	uint8_t buffer_ch0[2];
	uint8_t buffer_ch1[2];
	uint8_t buffer_ch2[2];
	uint8_t buffer_ch5[2];
	uint8_t buffer_ch6[2];
	uint8_t buffer_ch8[2];
	uint8_t buffer_ch9[2];
	uint8_t buffer_ch11[2];

	adc_sync_enable_channel(&ADC1, CONF_ADC1_CHANNEL_0);
	adc_sync_enable_channel(&ADC1, CONF_ADC1_CHANNEL_1);
	adc_sync_enable_channel(&ADC1, CONF_ADC1_CHANNEL_2);
	adc_sync_enable_channel(&ADC1, CONF_ADC1_CHANNEL_5);
	adc_sync_enable_channel(&ADC1, CONF_ADC1_CHANNEL_6);
	adc_sync_enable_channel(&ADC1, CONF_ADC1_CHANNEL_8);
	adc_sync_enable_channel(&ADC1, CONF_ADC1_CHANNEL_9);
	adc_sync_enable_channel(&ADC1, CONF_ADC1_CHANNEL_11);

	while (1) {
		adc_sync_read_channel(&ADC1, CONF_ADC1_CHANNEL_0, buffer_ch0, 2);
		adc_sync_read_channel(&ADC1, CONF_ADC1_CHANNEL_1, buffer_ch1, 2);
		adc_sync_read_channel(&ADC1, CONF_ADC1_CHANNEL_2, buffer_ch2, 2);
		adc_sync_read_channel(&ADC1, CONF_ADC1_CHANNEL_5, buffer_ch5, 2);
		adc_sync_read_channel(&ADC1, CONF_ADC1_CHANNEL_6, buffer_ch6, 2);
		adc_sync_read_channel(&ADC1, CONF_ADC1_CHANNEL_8, buffer_ch8, 2);
		adc_sync_read_channel(&ADC1, CONF_ADC1_CHANNEL_9, buffer_ch9, 2);
		adc_sync_read_channel(&ADC1, CONF_ADC1_CHANNEL_11, buffer_ch11, 2);
	}
}

static uint8_t src_data[IFLASH_PAGE_SIZE];
static uint8_t chk_data[IFLASH_PAGE_SIZE];

/**
 * Example of using FLASH to read and write buffer.
 */
void FLASH_example(void)
{
	uint32_t page_size;
	uint16_t i;

	/* Init source data */
	page_size = flash_get_page_size(&FLASH);

	for (i = 0; i < page_size; i++) {
		src_data[i] = i;
	}

	/* Write data to flash */
	flash_write(&FLASH, 0x3200, src_data, page_size);

	/* Read data from flash */
	flash_read(&FLASH, 0x3200, chk_data, page_size);
}

static void button_on_PC18_pressed(void)
{
}
static void button_on_PC20_pressed(void)
{
}
static void button_on_PC22_pressed(void)
{
}

/**
 * Example of using EXT_IRQ
 */
void EXT_IRQ_example(void)
{
	ext_irq_register(PIO_PC18_IDX, button_on_PC18_pressed);
	ext_irq_register(PIO_PC20_IDX, button_on_PC20_pressed);
	ext_irq_register(PIO_PC22_IDX, button_on_PC22_pressed);
}

static void period_cb_PWM_0(const struct pwm_descriptor *const descr)
{
	/* period interrupt */
}
/**
 * Example of using PWM_0.
 */
void PWM_0_example(void)
{
	pwm_register_callback(&PWM_0, PWM_PERIOD_CB, period_cb_PWM_0);
	pwm_enable(&PWM_0);
}

static void period_cb_PWM_1(const struct pwm_descriptor *const descr)
{
	/* period interrupt */
}
/**
 * Example of using PWM_1.
 */
void PWM_1_example(void)
{
	pwm_register_callback(&PWM_1, PWM_PERIOD_CB, period_cb_PWM_1);
	pwm_enable(&PWM_1);
}

/**
 * Example of using CALENDAR.
 */
static struct calendar_alarm alarm;

static void alarm_cb(struct calendar_descriptor *const descr)
{
	/* alarm expired */
}

void CALENDAR_example(void)
{
	struct calendar_date date;
	struct calendar_time time;

	calendar_enable(&CALENDAR);

	date.year  = 2000;
	date.month = 12;
	date.day   = 31;

	time.hour = 12;
	time.min  = 59;
	time.sec  = 59;

	calendar_set_date(&CALENDAR, &date);
	calendar_set_time(&CALENDAR, &time);

	alarm.cal_alarm.datetime.time.sec = 4;
	alarm.cal_alarm.option            = CALENDAR_ALARM_MATCH_SEC;
	alarm.cal_alarm.mode              = REPEAT;

	calendar_set_alarm(&CALENDAR, &alarm, alarm_cb);
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_SPI_0[12] = "Hello World!";

static void tx_complete_cb_SPI_0(struct _dma_resource *resource)
{
	/* Transfer completed */
}

void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_m_dma_get_io_descriptor(&SPI_0, &io);

	spi_m_dma_register_callback(&SPI_0, SPI_M_DMA_CB_TX_DONE, (spi_m_dma_cb_t)tx_complete_cb_SPI_0);
	spi_m_dma_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
}

/**
 * Example of using PWM_TC0.
 */
void PWM_TC0_example(void)
{
	pwm_set_parameters(&PWM_TC0, 10000, 5000);
	pwm_enable(&PWM_TC0);
}

/**
 * Example of using PWM_TC1.
 */
void PWM_TC1_example(void)
{
	pwm_set_parameters(&PWM_TC1, 10000, 5000);
	pwm_enable(&PWM_TC1);
}

/**
 * Example of using PWM_TC2.
 */
void PWM_TC2_example(void)
{
	pwm_set_parameters(&PWM_TC2, 10000, 5000);
	pwm_enable(&PWM_TC2);
}

/**
 * Example of using PWM_TC3.
 */
void PWM_TC3_example(void)
{
	pwm_set_parameters(&PWM_TC3, 10000, 5000);
	pwm_enable(&PWM_TC3);
}

void I2C_AT24MAC_example(void)
{
	struct io_descriptor *I2C_AT24MAC_io;

	i2c_m_sync_get_io_descriptor(&I2C_AT24MAC, &I2C_AT24MAC_io);
	i2c_m_sync_enable(&I2C_AT24MAC);
	i2c_m_sync_set_slaveaddr(&I2C_AT24MAC, 0x12, I2C_M_SEVEN);
	io_write(I2C_AT24MAC_io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using TARGET_IO to write "Hello World" using the IO abstraction.
 */
void TARGET_IO_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&TARGET_IO, &io);
	usart_sync_enable(&TARGET_IO);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using WDT0.
 */
void WDT0_example(void)
{
	/**
	 * ATSAME70Q20B do not support wdt_set_timeout_period()
	 * and wdt_enable(), the watch dog will start counting once
	 * wdt_init() been called.
	 * The application should call wdt_feed(&WDT0) at
	 * regular intervals before the timer underflow.
	 */
	wdt_feed(&WDT0);
}

void MACIF_example(void)
{
	mac_async_enable(&MACIF);
	mac_async_write(&MACIF, (uint8_t *)"Hello World!", 12);
}

void CAN_Node0_tx_callback(struct can_async_descriptor *const descr)
{
	(void)descr;
}
void CAN_Node0_rx_callback(struct can_async_descriptor *const descr)
{
	struct can_message msg;
	uint8_t            data[64];
	msg.data = data;
	can_async_read(descr, &msg);
	return;
}

/**
 * Example of using CAN_Node0 to Encrypt/Decrypt datas.
 */
void CAN_Node0_example(void)
{
	struct can_message msg;
	struct can_filter  filter;
	uint8_t            send_data[4];
	send_data[0] = 0x00;
	send_data[1] = 0x01;
	send_data[2] = 0x02;
	send_data[3] = 0x03;

	msg.id   = 0x45A;
	msg.type = CAN_TYPE_DATA;
	msg.data = send_data;
	msg.len  = 4;
	msg.fmt  = CAN_FMT_STDID;
	can_async_register_callback(&CAN_Node0, CAN_ASYNC_TX_CB, (FUNC_PTR)CAN_Node0_tx_callback);
	can_async_enable(&CAN_Node0);
	/**
	 * CAN_Node0_tx_callback callback should be invoked after call
	 * can_async_write, and remote device should recieve message with ID=0x45A
	 */
	can_async_write(&CAN_Node0, &msg);

	msg.id  = 0x100000A5;
	msg.fmt = CAN_FMT_EXTID;
	/**
	 * remote device should recieve message with ID=0x100000A5
	 */
	can_async_write(&CAN_Node0, &msg);

	/**
	 * CAN_Node0_rx_callback callback should be invoked after call
	 * can_async_set_filter and remote device send CAN Message with the same
	 * content as the filter.
	 */
	can_async_register_callback(&CAN_Node0, CAN_ASYNC_RX_CB, (FUNC_PTR)CAN_Node0_rx_callback);
	filter.id   = 0x469;
	filter.mask = 0;
	can_async_set_filter(&CAN_Node0, 0, CAN_FMT_STDID, &filter);

	filter.id   = 0x10000096;
	filter.mask = 0;
	can_async_set_filter(&CAN_Node0, 1, CAN_FMT_EXTID, &filter);
}

void CAN_Node1_tx_callback(struct can_async_descriptor *const descr)
{
	(void)descr;
}
void CAN_Node1_rx_callback(struct can_async_descriptor *const descr)
{
	struct can_message msg;
	uint8_t            data[64];
	msg.data = data;
	can_async_read(descr, &msg);
	return;
}

/**
 * Example of using CAN_Node1 to Encrypt/Decrypt datas.
 */
void CAN_Node1_example(void)
{
	struct can_message msg;
	struct can_filter  filter;
	uint8_t            send_data[4];
	send_data[0] = 0x00;
	send_data[1] = 0x01;
	send_data[2] = 0x02;
	send_data[3] = 0x03;

	msg.id   = 0x45A;
	msg.type = CAN_TYPE_DATA;
	msg.data = send_data;
	msg.len  = 4;
	msg.fmt  = CAN_FMT_STDID;
	can_async_register_callback(&CAN_Node1, CAN_ASYNC_TX_CB, (FUNC_PTR)CAN_Node1_tx_callback);
	can_async_enable(&CAN_Node1);
	/**
	 * CAN_Node1_tx_callback callback should be invoked after call
	 * can_async_write, and remote device should recieve message with ID=0x45A
	 */
	can_async_write(&CAN_Node1, &msg);

	msg.id  = 0x100000A5;
	msg.fmt = CAN_FMT_EXTID;
	/**
	 * remote device should recieve message with ID=0x100000A5
	 */
	can_async_write(&CAN_Node1, &msg);

	/**
	 * CAN_Node1_rx_callback callback should be invoked after call
	 * can_async_set_filter and remote device send CAN Message with the same
	 * content as the filter.
	 */
	can_async_register_callback(&CAN_Node1, CAN_ASYNC_RX_CB, (FUNC_PTR)CAN_Node1_rx_callback);
	filter.id   = 0x469;
	filter.mask = 0;
	can_async_set_filter(&CAN_Node1, 0, CAN_FMT_STDID, &filter);

	filter.id   = 0x10000096;
	filter.mask = 0;
	can_async_set_filter(&CAN_Node1, 1, CAN_FMT_EXTID, &filter);
}
