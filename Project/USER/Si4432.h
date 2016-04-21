/*si4432.h*/
#ifndef SI4432_H
#define SI4432_H
//#include "stm8s.h"

#define  SI4432_DEVICE_TYPE                                 0x00
#define  SI4432_DEVICE_VERSION                              0x01
#define  SI4432_DEVICE_STATUS                               0x02
#define  SI4432_INTERRUPT_STATUS_1                          0x03
#define  SI4432_INTERRUPT_STATUS_2                          0x04

#define  SI4432_INTERRUPT_ENABLE_1                          0x05
#define  SI4432_INTERRUPT_ENABLE_2                          0x06

#define  SI4432_OPERATING_AND_FUNCTION_CONTROL_1            0x07
#define  SI4432_OPERATING_AND_FUNCTION_CONTROL_2            0x08

#define  SI4432_CRYSTAL_OSCILLATOR_LOAD_CAPACITANCE         0x09
#define  SI4432_MICROCONTROLLER_OUTPUT_CLOCK                0x0A
#define  SI4432_GPIO0_CONFIGURATION                         0x0B
#define  SI4432_GPIO1_CONFIGURATION                         0x0C
#define  SI4432_GPIO2_CONFIGURATION                         0x0D
#define  SI4432_IO_PORT_CONFIGURATION                       0x0E
#define  SI4432_ADC_CONFIGURATION                           0x0F

#define  SI4432_ADC_SENSOR_AMPLIFIER_OFFSET                 0x10
#define  SI4432_ADC_VALUE                                   0x11
#define  SI4432_TEMPERATURE_SENSOR_CONTROL                  0x12
#define  SI4432_TEMPERATURE_VALUE_OFFSET                    0x13
#define  SI4432_WAKE_UP_TIMER_PERIOD_1                      0x14
#define  SI4432_WAKE_UP_TIMER_PERIOD_2                      0x15
#define  SI4432_WAKE_UP_TIMER_PERIOD_3                      0x16
#define  SI4432_WAKE_UP_TIMER_VALUE_1                       0x17
#define  SI4432_WAKE_UP_TIMER_VALUE_2                       0x18
#define  SI4432_LOW_DUTY_CYCLE_MODE_DURATION                0x19
#define  SI4432_LOW_BATTERY_DETECTOR_THRESHOLD              0x1A
#define  SI4432_BATTERY_VOLTAGE_LEVEL                       0x1B
#define  SI4432_IF_FILTER_BANDWIDTH                         0x1C
#define  SI4432_AFC_LOOP_GEARSHIFT_OVERRIDE                 0x1D
#define  SI4432_AFC_TIMING_CONTROL                          0x1E
#define  SI4432_CLOCK_RECOVERY_GEARSHIFT_OVERRIDE           0x1F

#define  SI4432_CLOCK_RECOVERY_OVERSAMPLING_RATIO           0x20
#define  SI4432_CLOCK_RECOVERY_OFFSET_2                     0x21
#define  SI4432_CLOCK_RECOVERY_OFFSET_1                     0x22
#define  SI4432_CLOCK_RECOVERY_OFFSET_0                     0x23
#define  SI4432_CLOCK_RECOVERY_TIMING_LOOP_GAIN_1           0x24
#define  SI4432_CLOCK_RECOVERY_TIMING_LOOP_GAIN_0           0x25
#define  SI4432_RECEIVED_SIGNAL_STRENGTH_INDICATOR          0x26

#define  SI4432_RSSI_THRESHOLD                              0x27
#define  SI4432_ANTENNA_DIVERSITY_REGISTER_1                0x28
#define  SI4432_ANTENNA_DIVERSITY_REGISTER_2                0x29

#define  SI4432_DATA_ACCESS_CONTROL                         0x30
#define  SI4432_EZMAC_STATUS                                0x31
#define  SI4432_HEADER_CONTROL_1                            0x32
#define  SI4432_HEADER_CONTROL_2                            0x33
#define  SI4432_PREAMBLE_LENGTH                             0x34
#define  SI4432_PREAMBLE_DETECTION_CONTROL                  0x35
#define  SI4432_SYNC_WORD_3                                 0x36
#define  SI4432_SYNC_WORD_2                                 0x37
#define  SI4432_SYNC_WORD_1                                 0x38
#define  SI4432_SYNC_WORD_0                                 0x39
#define  SI4432_TRANSMIT_HEADER_3                           0x3A
#define  SI4432_TRANSMIT_HEADER_2                           0x3B
#define  SI4432_TRANSMIT_HEADER_1                           0x3C
#define  SI4432_TRANSMIT_HEADER_0                           0x3D
#define  SI4432_TRANSMIT_PACKET_LENGTH                      0x3E
#define  SI4432_CHECK_HEADER_3                              0x3F

#define  SI4432_CHECK_HEADER_2                              0x40
#define  SI4432_CHECK_HEADER_1                              0x41
#define  SI4432_CHECK_HEADER_0                              0x42
#define  SI4432_HEADER_ENABLE_3                             0x43
#define  SI4432_HEADER_ENABLE_2                             0x44
#define  SI4432_HEADER_ENABLE_1                             0x45
#define  SI4432_HEADER_ENABLE_0                             0x46
#define  SI4432_RECEIVED_HEADER_3                           0x47
#define  SI4432_RECEIVED_HEADER_2                           0x48
#define  SI4432_RECEIVED_HEADER_1                           0x49
#define  SI4432_RECEIVED_HEADER_0                           0x4A
#define  SI4432_RECEIVED_PACKET_LENGTH                      0x4B

#define  SI4432_ANALOG_TEST_BUS                             0x50
#define  SI4432_DIGITAL_TEST_BUS                            0x51
#define  SI4432_TX_RAMP_CONTROL                             0x52
#define  SI4432_PLL_TUNE_TIME                               0x53
#define  SI4432_CALIBRATION_CONTROL                         0x55
#define  SI4432_MODEM_TEST                                  0x56
#define  SI4432_CHARGEPUMP_TEST                             0x57
#define  SI4432_CHARGEPUMP_CURRENT_TRIMMING_OVERRIDE        0x58
#define  SI4432_DIVIDER_CURRENT_TRIMMING                    0x59
#define  SI4432_VCO_CURRENT_TRIMMING                        0x5A
#define  SI4432_VCO_CALIBRATION_OVERRIDE                    0x5B
#define  SI4432_SYNTHESIZER_TEST                            0x5C
#define  SI4432_BLOCK_ENABLE_OVERRIDE_1                     0x5D
#define  SI4432_BLOCK_ENABLE_OVERRIDE_2                     0x5E
#define  SI4432_BLOCK_ENABLE_OVERRIDE_3                     0x5F

#define  SI4432_CHANNEL_FILTER_COEFFICIENT_ADDRESS          0x60
#define  SI4432_CHANNEL_FILTER_COEFFICIENT_VALUE            0x61
#define  SI4432_CRYSTAL_OSCILLATOR_CONTROL_TEST             0x62
#define  SI4432_RC_OSCILLATOR_COARSE_CALIBRATION_OVERRIDE   0x63
#define  SI4432_RC_OSCILLATOR_FINE_CALIBRATION_OVERRIDE     0x64
#define  SI4432_LDO_CONTROL_OVERRIDE                        0x65
#define  SI4432_LDO_LEVEL_SETTING                           0x66
#define  SI4432_DELTASIGMA_ADC_TUNING_1                     0x67
#define  SI4432_DELTASIGMA_ADC_TUNING_2                     0x68
#define  SI4432_AGC_OVERRIDE_1                              0x69
#define  SI4432_AGC_OVERRIDE_2                              0x6A
#define  SI4432_GFSK_FIR_FILTER_COEFFICIENT_ADDRESS         0x6B
#define  SI4432_GFSK_FIR_FILTER_COEFFICIENT_VALUE           0x6C
#define  SI4432_TX_POWER                                    0x6D
#define  SI4432_TX_DATA_RATE_1                              0x6E
#define  SI4432_TX_DATA_RATE_0                              0x6F

#define  SI4432_MODULATION_MODE_CONTROL_1                   0x70
#define  SI4432_MODULATION_MODE_CONTROL_2                   0x71
#define  SI4432_FREQUENCY_DEVIATION                         0x72
#define  SI4432_FREQUENCY_OFFSET_1                          0x73
#define  SI4432_FREQUENCY_OFFSET_2                          0x74
#define  SI4432_FREQUENCY_BAND_SELECT                       0x75
#define  SI4432_NOMINAL_CARRIER_FREQUENCY_1                 0x76
#define  SI4432_NOMINAL_CARRIER_FREQUENCY_0                 0x77
#define  SI4432_FREQUENCY_HOPPING_CHANNEL_SELECT            0x79
#define  SI4432_FREQUENCY_HOPPING_STEP_SIZE                 0x7A
#define  SI4432_TX_FIFO_CONTROL_1                           0x7C
#define  SI4432_TX_FIFO_CONTROL_2                           0x7D
#define  SI4432_RX_FIFO_CONTROL                             0x7E
#define  SI4432_FIFO_ACCESS                                 0x7F

void Si4432_On(void);
void Si4432_OFF(void);
void InitSi4432(void);

void Test1(void);
void Test2(void);

void Test4(void);
void SetChipModle(u8 mod);
void Test5(u8 a);
void Test6(u8 a);
void ChipOnInit(void);

void MyDev1(void);
void MyDev2(void);
#endif
