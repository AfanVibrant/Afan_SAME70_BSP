/* Auto-generated config file hpl_tc_config.h */
#ifndef HPL_TC_CONFIG_H
#define HPL_TC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#ifndef CONF_TC0_ENABLE
#define CONF_TC0_ENABLE 1
#endif

#include "peripheral_clk_config.h"

// <h> Basic configuration

// <e> Enable Divided Clock
// <id> timer_div_clock
#ifndef CONF_TC0_DIVIDE_CLOCK_ENABLE
#define CONF_TC0_DIVIDE_CLOCK_ENABLE 1
#endif

// <o> Clock Selection
// <0x0=> TIMER_CLOCK1 (PCK6)
// <0x1=> TIMER_CLOCK2 (MCK/8)
// <0x2=> TIMER_CLOCK3 (MCK/32)
// <0x3=> TIMER_CLOCK4 (MCK/128)
// <0x4=> TIMER_CLOCK5 (SLCK)
// <i> This defines the clock selection
// <id> timer_prescaler
#ifndef CONF_TC0_TCCLKS
#define CONF_TC0_TCCLKS 0x1
#endif

// </e>

// <o> Waveform Period value(uS) <0-4294967295>
// <id> waveform_period
#ifndef CONF_TC0_WAVEFORM_PEROID
#define CONF_TC0_WAVEFORM_PEROID 1000
#endif

// <o> Waveform Duty value(0.1%) <1-1000>
// <id> waveform_duty
#ifndef CONF_TC0_WAVEFORM_DUTY
#define CONF_TC0_WAVEFORM_DUTY 500
#endif
// </h>

// <h> Event Control
// <e> External Event/Trigger Control in Capture Mode
// <id> timer_external_trigger_enable
#ifndef CONF_TC0_CPCTRG
#define CONF_TC0_CPCTRG 0
#endif

// <o> External Trigger Edge Selection
// <0x0=> The clock is not gated by an external signal
// <0x1=> Rising edge
// <0x2=> Falling edge
// <0x3=> Each edge
// <i> This defines external trigger edge selection.
//<id> timer_etrgedg
#ifndef CONF_TC0_ETRGEDG
#define CONF_TC0_ETRGEDG 0
#endif

// <o> TIOA or TIOB External Trigger Selection
// <0x0=> TIOB is used as an external trigger
// <0x1=> TIOA is used as an external trigger
// <i> This defines whether external trigger selection is TIOB or TIOA.
//<id> timer_abetrg
#ifndef CONF_TC0_ABETRG
#define CONF_TC0_ABETRG 0
#endif

// </e>

// <e> Fault Output Control
// <id> timer_fault_control
#ifndef CONF_TC0_FAULT_CONTROL
#define CONF_TC0_FAULT_CONTROL 0
#endif

// <q> Compare Fault Channel0 Enable
// <i> This defines whether the FAULT output source (CPCS flag) is enable or disable from channel0.
// <id> timer_fault_chan0_enable
#ifndef CONF_TC0_FAULT_CHAN0_ENABLE
#define CONF_TC0_FAULT_CHAN0_ENABLE 0
#endif

// <q> Compare Fault Channel1 Enable
// <i> This defines whether the FAULT output source (CPCS flag) is enable or disable from channel1.
// <id> timer_fault_chan1_enable
#ifndef CONF_TC0_FAULT_CHAN1_ENABLE
#define CONF_TC0_FAULT_CHAN1_ENABLE 0
#endif
// </e>

// </h>

// No Divided Clock or not
#define CONF_TC0_NODIVCLK 0
#if CONF_TC0_DIVIDE_CLOCK_ENABLE == 0
#undef CONF_TC0_NODIVCLK
#define CONF_TC0_NODIVCLK 1
#endif

// Calculating correct top value based on requested tick interval.
#if CONF_TC0_TCCLKS == 0x0
#define CONF_TC0_CLKS_FREQUENCY CONF_PCK6_FREQUENCY

#elif CONF_TC0_TCCLKS == 0x1
#define CONF_TC0_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 8

#elif CONF_TC0_TCCLKS == 0x2
#define CONF_TC0_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 32

#elif CONF_TC0_TCCLKS == 0x3
#define CONF_TC0_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 128

#elif CONF_TC0_TCCLKS == 0x4
#define CONF_TC0_CLKS_FREQUENCY CONF_SLCK_FREQUENCY
#endif

#if CONF_TC0_DIVIDE_CLOCK_ENABLE == 0
#undef CONF_TC0_CLKS_FREQUENCY
#define CONF_TC0_CLKS_FREQUENCY CONF_TC0_FREQUENCY
#endif

#ifndef CONF_TC0_TICKS_PER_US
#define CONF_TC0_TICKS_PER_US (CONF_TC0_CLKS_FREQUENCY / 1000000)
#endif

#ifndef CONF_TC0_RC
#define CONF_TC0_RC (CONF_TC0_TICKS_PER_US * CONF_TC0_WAVEFORM_PEROID)
#endif

#if (CONF_TC0_RC > 0xFFFF)
#warning For 16-bit channels, RC field size is limited to register bits 15:0
#endif

#ifndef CONF_TC0_RA
#define CONF_TC0_RA (CONF_TC0_TICKS_PER_US * CONF_TC0_WAVEFORM_DUTY)
#endif

#ifndef CONF_TC0_RB
#define CONF_TC0_RB (CONF_TC0_TICKS_PER_US * CONF_TC0_WAVEFORM_DUTY)
#endif

#ifndef CONF_TC0_CMR_REG_VAL
#define CONF_TC0_CMR_REG_VAL                                                                                           \
	(TC_CMR_TCCLKS(CONF_TC0_TCCLKS) | (0x1 << 10) | (0x2 << 13) | TC_CMR_WAVE | (0x1 << 16) | (0x2 << 18)              \
	 | (0x1 << 24) | (0x2 << 26))
#endif

#ifndef CONF_TC1_ENABLE
#define CONF_TC1_ENABLE 1
#endif

#include "peripheral_clk_config.h"

// <h> Basic configuration

// <e> Enable Divided Clock
// <id> timer_div_clock
#ifndef CONF_TC1_DIVIDE_CLOCK_ENABLE
#define CONF_TC1_DIVIDE_CLOCK_ENABLE 1
#endif

// <o> Clock Selection
// <0x0=> TIMER_CLOCK1 (PCK6)
// <0x1=> TIMER_CLOCK2 (MCK/8)
// <0x2=> TIMER_CLOCK3 (MCK/32)
// <0x3=> TIMER_CLOCK4 (MCK/128)
// <0x4=> TIMER_CLOCK5 (SLCK)
// <i> This defines the clock selection
// <id> timer_prescaler
#ifndef CONF_TC1_TCCLKS
#define CONF_TC1_TCCLKS 0x1
#endif

// </e>

// <o> Waveform Period value(uS) <0-4294967295>
// <id> waveform_period
#ifndef CONF_TC1_WAVEFORM_PEROID
#define CONF_TC1_WAVEFORM_PEROID 1000
#endif

// <o> Waveform Duty value(0.1%) <1-1000>
// <id> waveform_duty
#ifndef CONF_TC1_WAVEFORM_DUTY
#define CONF_TC1_WAVEFORM_DUTY 500
#endif
// </h>

// <h> Event Control
// <e> External Event/Trigger Control in Capture Mode
// <id> timer_external_trigger_enable
#ifndef CONF_TC1_CPCTRG
#define CONF_TC1_CPCTRG 0
#endif

// <o> External Trigger Edge Selection
// <0x0=> The clock is not gated by an external signal
// <0x1=> Rising edge
// <0x2=> Falling edge
// <0x3=> Each edge
// <i> This defines external trigger edge selection.
//<id> timer_etrgedg
#ifndef CONF_TC1_ETRGEDG
#define CONF_TC1_ETRGEDG 0
#endif

// <o> TIOA or TIOB External Trigger Selection
// <0x0=> TIOB is used as an external trigger
// <0x1=> TIOA is used as an external trigger
// <i> This defines whether external trigger selection is TIOB or TIOA.
//<id> timer_abetrg
#ifndef CONF_TC1_ABETRG
#define CONF_TC1_ABETRG 0
#endif

// </e>

// <e> Fault Output Control
// <id> timer_fault_control
#ifndef CONF_TC1_FAULT_CONTROL
#define CONF_TC1_FAULT_CONTROL 0
#endif

// <q> Compare Fault Channel0 Enable
// <i> This defines whether the FAULT output source (CPCS flag) is enable or disable from channel0.
// <id> timer_fault_chan0_enable
#ifndef CONF_TC1_FAULT_CHAN0_ENABLE
#define CONF_TC1_FAULT_CHAN0_ENABLE 0
#endif

// <q> Compare Fault Channel1 Enable
// <i> This defines whether the FAULT output source (CPCS flag) is enable or disable from channel1.
// <id> timer_fault_chan1_enable
#ifndef CONF_TC1_FAULT_CHAN1_ENABLE
#define CONF_TC1_FAULT_CHAN1_ENABLE 0
#endif
// </e>

// </h>

// No Divided Clock or not
#define CONF_TC1_NODIVCLK 0
#if CONF_TC1_DIVIDE_CLOCK_ENABLE == 0
#undef CONF_TC1_NODIVCLK
#define CONF_TC1_NODIVCLK 1
#endif

// Calculating correct top value based on requested tick interval.
#if CONF_TC1_TCCLKS == 0x0
#define CONF_TC1_CLKS_FREQUENCY CONF_PCK6_FREQUENCY

#elif CONF_TC1_TCCLKS == 0x1
#define CONF_TC1_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 8

#elif CONF_TC1_TCCLKS == 0x2
#define CONF_TC1_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 32

#elif CONF_TC1_TCCLKS == 0x3
#define CONF_TC1_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 128

#elif CONF_TC1_TCCLKS == 0x4
#define CONF_TC1_CLKS_FREQUENCY CONF_SLCK_FREQUENCY
#endif

#if CONF_TC1_DIVIDE_CLOCK_ENABLE == 0
#undef CONF_TC1_CLKS_FREQUENCY
#define CONF_TC1_CLKS_FREQUENCY CONF_TC1_FREQUENCY
#endif

#ifndef CONF_TC1_TICKS_PER_US
#define CONF_TC1_TICKS_PER_US (CONF_TC1_CLKS_FREQUENCY / 1000000)
#endif

#ifndef CONF_TC1_RC
#define CONF_TC1_RC (CONF_TC1_TICKS_PER_US * CONF_TC1_WAVEFORM_PEROID)
#endif

#if (CONF_TC1_RC > 0xFFFF)
#warning For 16-bit channels, RC field size is limited to register bits 15:0
#endif

#ifndef CONF_TC1_RA
#define CONF_TC1_RA (CONF_TC1_TICKS_PER_US * CONF_TC1_WAVEFORM_DUTY)
#endif

#ifndef CONF_TC1_RB
#define CONF_TC1_RB (CONF_TC1_TICKS_PER_US * CONF_TC1_WAVEFORM_DUTY)
#endif

#ifndef CONF_TC1_CMR_REG_VAL
#define CONF_TC1_CMR_REG_VAL                                                                                           \
	(TC_CMR_TCCLKS(CONF_TC1_TCCLKS) | (0x1 << 10) | (0x2 << 13) | TC_CMR_WAVE | (0x1 << 16) | (0x2 << 18)              \
	 | (0x1 << 24) | (0x2 << 26))
#endif

#ifndef CONF_TC2_ENABLE
#define CONF_TC2_ENABLE 1
#endif

#include "peripheral_clk_config.h"

// <h> Basic configuration

// <e> Enable Divided Clock
// <id> timer_div_clock
#ifndef CONF_TC2_DIVIDE_CLOCK_ENABLE
#define CONF_TC2_DIVIDE_CLOCK_ENABLE 1
#endif

// <o> Clock Selection
// <0x0=> TIMER_CLOCK1 (PCK6)
// <0x1=> TIMER_CLOCK2 (MCK/8)
// <0x2=> TIMER_CLOCK3 (MCK/32)
// <0x3=> TIMER_CLOCK4 (MCK/128)
// <0x4=> TIMER_CLOCK5 (SLCK)
// <i> This defines the clock selection
// <id> timer_prescaler
#ifndef CONF_TC2_TCCLKS
#define CONF_TC2_TCCLKS 0x1
#endif

// </e>

// <o> Waveform Period value(uS) <0-4294967295>
// <id> waveform_period
#ifndef CONF_TC2_WAVEFORM_PEROID
#define CONF_TC2_WAVEFORM_PEROID 1000
#endif

// <o> Waveform Duty value(0.1%) <1-1000>
// <id> waveform_duty
#ifndef CONF_TC2_WAVEFORM_DUTY
#define CONF_TC2_WAVEFORM_DUTY 500
#endif
// </h>

// <h> Event Control
// <e> External Event/Trigger Control in Capture Mode
// <id> timer_external_trigger_enable
#ifndef CONF_TC2_CPCTRG
#define CONF_TC2_CPCTRG 0
#endif

// <o> External Trigger Edge Selection
// <0x0=> The clock is not gated by an external signal
// <0x1=> Rising edge
// <0x2=> Falling edge
// <0x3=> Each edge
// <i> This defines external trigger edge selection.
//<id> timer_etrgedg
#ifndef CONF_TC2_ETRGEDG
#define CONF_TC2_ETRGEDG 0
#endif

// <o> TIOA or TIOB External Trigger Selection
// <0x0=> TIOB is used as an external trigger
// <0x1=> TIOA is used as an external trigger
// <i> This defines whether external trigger selection is TIOB or TIOA.
//<id> timer_abetrg
#ifndef CONF_TC2_ABETRG
#define CONF_TC2_ABETRG 0
#endif

// </e>

// <e> Fault Output Control
// <id> timer_fault_control
#ifndef CONF_TC2_FAULT_CONTROL
#define CONF_TC2_FAULT_CONTROL 0
#endif

// <q> Compare Fault Channel0 Enable
// <i> This defines whether the FAULT output source (CPCS flag) is enable or disable from channel0.
// <id> timer_fault_chan0_enable
#ifndef CONF_TC2_FAULT_CHAN0_ENABLE
#define CONF_TC2_FAULT_CHAN0_ENABLE 0
#endif

// <q> Compare Fault Channel1 Enable
// <i> This defines whether the FAULT output source (CPCS flag) is enable or disable from channel1.
// <id> timer_fault_chan1_enable
#ifndef CONF_TC2_FAULT_CHAN1_ENABLE
#define CONF_TC2_FAULT_CHAN1_ENABLE 0
#endif
// </e>

// </h>

// No Divided Clock or not
#define CONF_TC2_NODIVCLK 0
#if CONF_TC2_DIVIDE_CLOCK_ENABLE == 0
#undef CONF_TC2_NODIVCLK
#define CONF_TC2_NODIVCLK 1
#endif

// Calculating correct top value based on requested tick interval.
#if CONF_TC2_TCCLKS == 0x0
#define CONF_TC2_CLKS_FREQUENCY CONF_PCK6_FREQUENCY

#elif CONF_TC2_TCCLKS == 0x1
#define CONF_TC2_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 8

#elif CONF_TC2_TCCLKS == 0x2
#define CONF_TC2_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 32

#elif CONF_TC2_TCCLKS == 0x3
#define CONF_TC2_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 128

#elif CONF_TC2_TCCLKS == 0x4
#define CONF_TC2_CLKS_FREQUENCY CONF_SLCK_FREQUENCY
#endif

#if CONF_TC2_DIVIDE_CLOCK_ENABLE == 0
#undef CONF_TC2_CLKS_FREQUENCY
#define CONF_TC2_CLKS_FREQUENCY CONF_TC2_FREQUENCY
#endif

#ifndef CONF_TC2_TICKS_PER_US
#define CONF_TC2_TICKS_PER_US (CONF_TC2_CLKS_FREQUENCY / 1000000)
#endif

#ifndef CONF_TC2_RC
#define CONF_TC2_RC (CONF_TC2_TICKS_PER_US * CONF_TC2_WAVEFORM_PEROID)
#endif

#if (CONF_TC2_RC > 0xFFFF)
#warning For 16-bit channels, RC field size is limited to register bits 15:0
#endif

#ifndef CONF_TC2_RA
#define CONF_TC2_RA (CONF_TC2_TICKS_PER_US * CONF_TC2_WAVEFORM_DUTY)
#endif

#ifndef CONF_TC2_RB
#define CONF_TC2_RB (CONF_TC2_TICKS_PER_US * CONF_TC2_WAVEFORM_DUTY)
#endif

#ifndef CONF_TC2_CMR_REG_VAL
#define CONF_TC2_CMR_REG_VAL                                                                                           \
	(TC_CMR_TCCLKS(CONF_TC2_TCCLKS) | (0x1 << 10) | (0x2 << 13) | TC_CMR_WAVE | (0x1 << 16) | (0x2 << 18)              \
	 | (0x1 << 24) | (0x2 << 26))
#endif

#ifndef CONF_TC3_ENABLE
#define CONF_TC3_ENABLE 1
#endif

#include "peripheral_clk_config.h"

// <h> Basic configuration

// <e> Enable Divided Clock
// <id> timer_div_clock
#ifndef CONF_TC3_DIVIDE_CLOCK_ENABLE
#define CONF_TC3_DIVIDE_CLOCK_ENABLE 1
#endif

// <o> Clock Selection
// <0x0=> TIMER_CLOCK1 (PCK6)
// <0x1=> TIMER_CLOCK2 (MCK/8)
// <0x2=> TIMER_CLOCK3 (MCK/32)
// <0x3=> TIMER_CLOCK4 (MCK/128)
// <0x4=> TIMER_CLOCK5 (SLCK)
// <i> This defines the clock selection
// <id> timer_prescaler
#ifndef CONF_TC3_TCCLKS
#define CONF_TC3_TCCLKS 0x1
#endif

// </e>

// <o> Waveform Period value(uS) <0-4294967295>
// <id> waveform_period
#ifndef CONF_TC3_WAVEFORM_PEROID
#define CONF_TC3_WAVEFORM_PEROID 1000
#endif

// <o> Waveform Duty value(0.1%) <1-1000>
// <id> waveform_duty
#ifndef CONF_TC3_WAVEFORM_DUTY
#define CONF_TC3_WAVEFORM_DUTY 500
#endif
// </h>

// <h> Event Control
// <e> External Event/Trigger Control in Capture Mode
// <id> timer_external_trigger_enable
#ifndef CONF_TC3_CPCTRG
#define CONF_TC3_CPCTRG 0
#endif

// <o> External Trigger Edge Selection
// <0x0=> The clock is not gated by an external signal
// <0x1=> Rising edge
// <0x2=> Falling edge
// <0x3=> Each edge
// <i> This defines external trigger edge selection.
//<id> timer_etrgedg
#ifndef CONF_TC3_ETRGEDG
#define CONF_TC3_ETRGEDG 0
#endif

// <o> TIOA or TIOB External Trigger Selection
// <0x0=> TIOB is used as an external trigger
// <0x1=> TIOA is used as an external trigger
// <i> This defines whether external trigger selection is TIOB or TIOA.
//<id> timer_abetrg
#ifndef CONF_TC3_ABETRG
#define CONF_TC3_ABETRG 0
#endif

// </e>

// <e> Fault Output Control
// <id> timer_fault_control
#ifndef CONF_TC3_FAULT_CONTROL
#define CONF_TC3_FAULT_CONTROL 0
#endif

// <q> Compare Fault Channel0 Enable
// <i> This defines whether the FAULT output source (CPCS flag) is enable or disable from channel0.
// <id> timer_fault_chan0_enable
#ifndef CONF_TC3_FAULT_CHAN0_ENABLE
#define CONF_TC3_FAULT_CHAN0_ENABLE 0
#endif

// <q> Compare Fault Channel1 Enable
// <i> This defines whether the FAULT output source (CPCS flag) is enable or disable from channel1.
// <id> timer_fault_chan1_enable
#ifndef CONF_TC3_FAULT_CHAN1_ENABLE
#define CONF_TC3_FAULT_CHAN1_ENABLE 0
#endif
// </e>

// </h>

// No Divided Clock or not
#define CONF_TC3_NODIVCLK 0
#if CONF_TC3_DIVIDE_CLOCK_ENABLE == 0
#undef CONF_TC3_NODIVCLK
#define CONF_TC3_NODIVCLK 1
#endif

// Calculating correct top value based on requested tick interval.
#if CONF_TC3_TCCLKS == 0x0
#define CONF_TC3_CLKS_FREQUENCY CONF_PCK6_FREQUENCY

#elif CONF_TC3_TCCLKS == 0x1
#define CONF_TC3_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 8

#elif CONF_TC3_TCCLKS == 0x2
#define CONF_TC3_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 32

#elif CONF_TC3_TCCLKS == 0x3
#define CONF_TC3_CLKS_FREQUENCY CONF_MCK_FREQUENCY / 128

#elif CONF_TC3_TCCLKS == 0x4
#define CONF_TC3_CLKS_FREQUENCY CONF_SLCK_FREQUENCY
#endif

#if CONF_TC3_DIVIDE_CLOCK_ENABLE == 0
#undef CONF_TC3_CLKS_FREQUENCY
#define CONF_TC3_CLKS_FREQUENCY CONF_TC3_FREQUENCY
#endif

#ifndef CONF_TC3_TICKS_PER_US
#define CONF_TC3_TICKS_PER_US (CONF_TC3_CLKS_FREQUENCY / 1000000)
#endif

#ifndef CONF_TC3_RC
#define CONF_TC3_RC (CONF_TC3_TICKS_PER_US * CONF_TC3_WAVEFORM_PEROID)
#endif

#if (CONF_TC3_RC > 0xFFFF)
#warning For 16-bit channels, RC field size is limited to register bits 15:0
#endif

#ifndef CONF_TC3_RA
#define CONF_TC3_RA (CONF_TC3_TICKS_PER_US * CONF_TC3_WAVEFORM_DUTY)
#endif

#ifndef CONF_TC3_RB
#define CONF_TC3_RB (CONF_TC3_TICKS_PER_US * CONF_TC3_WAVEFORM_DUTY)
#endif

#ifndef CONF_TC3_CMR_REG_VAL
#define CONF_TC3_CMR_REG_VAL                                                                                           \
	(TC_CMR_TCCLKS(CONF_TC3_TCCLKS) | (0x1 << 10) | (0x2 << 13) | TC_CMR_WAVE | (0x1 << 16) | (0x2 << 18)              \
	 | (0x1 << 24) | (0x2 << 26))
#endif

// <<< end of configuration section >>>

#endif // HPL_TC_CONFIG_H
