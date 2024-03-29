#pragma once

#define INV_X_GYRO      (0x40)
#define INV_Y_GYRO      (0x20)
#define INV_Z_GYRO      (0x10)
#define INV_XYZ_GYRO    (INV_X_GYRO | INV_Y_GYRO | INV_Z_GYRO)
#define INV_XYZ_ACCEL   (0x08)
#define INV_XYZ_COMPASS (0x01)

#define MPU9150_ADDRESS 0b1101001
#define MPU9150_WHOAMI 	 	  117

//Magnetometer Registers
#define MPU9150_RA_MAG_ADDRESS               0x0C
#define MPU9150_RA_MAG_XOUT_L                0x03
#define MPU9150_RA_MAG_XOUT_H                0x04
#define MPU9150_RA_MAG_YOUT_L                0x05
#define MPU9150_RA_MAG_YOUT_H                0x06
#define MPU9150_RA_MAG_ZOUT_L                0x07
#define MPU9150_RA_MAG_ZOUT_H                0x08

#define MPU9150_RA_MAG_CNTL					0x0A

#define MPU9150_ADDRESS_AD0_LOW     0x68 // address pin low (GND), default for InvenSense evaluation board
#define MPU9150_ADDRESS_AD0_HIGH    0x69 // address pin high (VCC)
#define MPU9150_DEFAULT_ADDRESS     MPU9150_ADDRESS_AD0_LOW

#define MPU9150_RA_XG_OFFS_TC       0x00 //[7] PWR_MODE, [6:1] XG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU9150_RA_YG_OFFS_TC       0x01 //[7] PWR_MODE, [6:1] YG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU9150_RA_ZG_OFFS_TC       0x02 //[7] PWR_MODE, [6:1] ZG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU9150_RA_X_FINE_GAIN      0x03 //[7:0] X_FINE_GAIN
#define MPU9150_RA_Y_FINE_GAIN      0x04 //[7:0] Y_FINE_GAIN
#define MPU9150_RA_Z_FINE_GAIN      0x05 //[7:0] Z_FINE_GAIN
#define MPU9150_RA_XA_OFFS_H        0x06 //[15:0] XA_OFFS
#define MPU9150_RA_XA_OFFS_L_TC     0x07
#define MPU9150_RA_YA_OFFS_H        0x08 //[15:0] YA_OFFS
#define MPU9150_RA_YA_OFFS_L_TC     0x09
#define MPU9150_RA_ZA_OFFS_H        0x0A //[15:0] ZA_OFFS
#define MPU9150_RA_ZA_OFFS_L_TC     0x0B
#define MPU9150_RA_XG_OFFS_USRH     0x13 //[15:0] XG_OFFS_USR
#define MPU9150_RA_XG_OFFS_USRL     0x14
#define MPU9150_RA_YG_OFFS_USRH     0x15 //[15:0] YG_OFFS_USR
#define MPU9150_RA_YG_OFFS_USRL     0x16
#define MPU9150_RA_ZG_OFFS_USRH     0x17 //[15:0] ZG_OFFS_USR
#define MPU9150_RA_ZG_OFFS_USRL     0x18
#define MPU9150_RA_SMPLRT_DIV       0x19
#define MPU9150_RA_CONFIG           0x1A
#define MPU9150_RA_GYRO_CONFIG      0x1B
#define MPU9150_RA_ACCEL_CONFIG     0x1C
#define MPU9150_RA_FF_THR           0x1D
#define MPU9150_RA_FF_DUR           0x1E
#define MPU9150_RA_MOT_THR          0x1F
#define MPU9150_RA_MOT_DUR          0x20
#define MPU9150_RA_ZRMOT_THR        0x21
#define MPU9150_RA_ZRMOT_DUR        0x22
#define MPU9150_RA_FIFO_EN          0x23
#define MPU9150_RA_I2C_MST_CTRL     0x24
#define MPU9150_RA_I2C_SLV0_ADDR    0x25
#define MPU9150_RA_I2C_SLV0_REG     0x26
#define MPU9150_RA_I2C_SLV0_CTRL    0x27
#define MPU9150_RA_I2C_SLV1_ADDR    0x28
#define MPU9150_RA_I2C_SLV1_REG     0x29
#define MPU9150_RA_I2C_SLV1_CTRL    0x2A
#define MPU9150_RA_I2C_SLV2_ADDR    0x2B
#define MPU9150_RA_I2C_SLV2_REG     0x2C
#define MPU9150_RA_I2C_SLV2_CTRL    0x2D
#define MPU9150_RA_I2C_SLV3_ADDR    0x2E
#define MPU9150_RA_I2C_SLV3_REG     0x2F
#define MPU9150_RA_I2C_SLV3_CTRL    0x30
#define MPU9150_RA_I2C_SLV4_ADDR    0x31
#define MPU9150_RA_I2C_SLV4_REG     0x32
#define MPU9150_RA_I2C_SLV4_DO      0x33
#define MPU9150_RA_I2C_SLV4_CTRL    0x34
#define MPU9150_RA_I2C_SLV4_DI      0x35
#define MPU9150_RA_I2C_MST_STATUS   0x36
#define MPU9150_RA_INT_PIN_CFG      0x37
#define MPU9150_RA_INT_ENABLE       0x38
#define MPU9150_RA_DMP_INT_STATUS   0x39
#define MPU9150_RA_INT_STATUS       0x3A
#define MPU9150_RA_ACCEL_XOUT_H     0x3B
#define MPU9150_RA_ACCEL_XOUT_L     0x3C
#define MPU9150_RA_ACCEL_YOUT_H     0x3D
#define MPU9150_RA_ACCEL_YOUT_L     0x3E
#define MPU9150_RA_ACCEL_ZOUT_H     0x3F
#define MPU9150_RA_ACCEL_ZOUT_L     0x40
#define MPU9150_RA_TEMP_OUT_H       0x41
#define MPU9150_RA_TEMP_OUT_L       0x42
#define MPU9150_RA_GYRO_XOUT_H      0x43
#define MPU9150_RA_GYRO_XOUT_L      0x44
#define MPU9150_RA_GYRO_YOUT_H      0x45
#define MPU9150_RA_GYRO_YOUT_L      0x46
#define MPU9150_RA_GYRO_ZOUT_H      0x47
#define MPU9150_RA_GYRO_ZOUT_L      0x48
#define MPU9150_RA_EXT_SENS_DATA_00 0x49
#define MPU9150_RA_EXT_SENS_DATA_01 0x4A
#define MPU9150_RA_EXT_SENS_DATA_02 0x4B
#define MPU9150_RA_EXT_SENS_DATA_03 0x4C
#define MPU9150_RA_EXT_SENS_DATA_04 0x4D
#define MPU9150_RA_EXT_SENS_DATA_05 0x4E
#define MPU9150_RA_EXT_SENS_DATA_06 0x4F
#define MPU9150_RA_EXT_SENS_DATA_07 0x50
#define MPU9150_RA_EXT_SENS_DATA_08 0x51
#define MPU9150_RA_EXT_SENS_DATA_09 0x52
#define MPU9150_RA_EXT_SENS_DATA_10 0x53
#define MPU9150_RA_EXT_SENS_DATA_11 0x54
#define MPU9150_RA_EXT_SENS_DATA_12 0x55
#define MPU9150_RA_EXT_SENS_DATA_13 0x56
#define MPU9150_RA_EXT_SENS_DATA_14 0x57
#define MPU9150_RA_EXT_SENS_DATA_15 0x58
#define MPU9150_RA_EXT_SENS_DATA_16 0x59
#define MPU9150_RA_EXT_SENS_DATA_17 0x5A
#define MPU9150_RA_EXT_SENS_DATA_18 0x5B
#define MPU9150_RA_EXT_SENS_DATA_19 0x5C
#define MPU9150_RA_EXT_SENS_DATA_20 0x5D
#define MPU9150_RA_EXT_SENS_DATA_21 0x5E
#define MPU9150_RA_EXT_SENS_DATA_22 0x5F
#define MPU9150_RA_EXT_SENS_DATA_23 0x60
#define MPU9150_RA_MOT_DETECT_STATUS    0x61
#define MPU9150_RA_I2C_SLV0_DO      0x63
#define MPU9150_RA_I2C_SLV1_DO      0x64
#define MPU9150_RA_I2C_SLV2_DO      0x65
#define MPU9150_RA_I2C_SLV3_DO      0x66
#define MPU9150_RA_I2C_MST_DELAY_CTRL   0x67
#define MPU9150_RA_SIGNAL_PATH_RESET    0x68
#define MPU9150_RA_MOT_DETECT_CTRL      0x69
#define MPU9150_RA_USER_CTRL        0x6A
#define MPU9150_RA_PWR_MGMT_1       0x6B
#define MPU9150_RA_PWR_MGMT_2       0x6C
#define MPU9150_RA_BANK_SEL         0x6D
#define MPU9150_RA_MEM_START_ADDR   0x6E
#define MPU9150_RA_MEM_R_W          0x6F
#define MPU9150_RA_DMP_CFG_1        0x70
#define MPU9150_RA_DMP_CFG_2        0x71
#define MPU9150_RA_FIFO_COUNTH      0x72
#define MPU9150_RA_FIFO_COUNTL      0x73
#define MPU9150_RA_FIFO_R_W         0x74
#define MPU9150_RA_WHO_AM_I         0x75

#define MPU9150_TC_PWR_MODE_BIT     7
#define MPU9150_TC_OFFSET_BIT       6
#define MPU9150_TC_OFFSET_LENGTH    6
#define MPU9150_TC_OTP_BNK_VLD_BIT  0

#define MPU9150_VDDIO_LEVEL_VLOGIC  0
#define MPU9150_VDDIO_LEVEL_VDD     1

#define MPU9150_CFG_EXT_SYNC_SET_BIT    5
#define MPU9150_CFG_EXT_SYNC_SET_LENGTH 3
#define MPU9150_CFG_DLPF_CFG_BIT    2
#define MPU9150_CFG_DLPF_CFG_LENGTH 3

#define MPU9150_EXT_SYNC_DISABLED       0x0
#define MPU9150_EXT_SYNC_TEMP_OUT_L     0x1
#define MPU9150_EXT_SYNC_GYRO_XOUT_L    0x2
#define MPU9150_EXT_SYNC_GYRO_YOUT_L    0x3
#define MPU9150_EXT_SYNC_GYRO_ZOUT_L    0x4
#define MPU9150_EXT_SYNC_ACCEL_XOUT_L   0x5
#define MPU9150_EXT_SYNC_ACCEL_YOUT_L   0x6
#define MPU9150_EXT_SYNC_ACCEL_ZOUT_L   0x7

#define MPU9150_DLPF_BW_256         0x00
#define MPU9150_DLPF_BW_188         0x01
#define MPU9150_DLPF_BW_98          0x02
#define MPU9150_DLPF_BW_42          0x03
#define MPU9150_DLPF_BW_20          0x04
#define MPU9150_DLPF_BW_10          0x05
#define MPU9150_DLPF_BW_5           0x06

#define MPU9150_GCONFIG_FS_SEL_BIT      4
#define MPU9150_GCONFIG_FS_SEL_LENGTH   2

#define MPU9150_GYRO_FS_250         0x00
#define MPU9150_GYRO_FS_500         0x01
#define MPU9150_GYRO_FS_1000        0x02
#define MPU9150_GYRO_FS_2000        0x03

#define MPU9150_ACONFIG_XA_ST_BIT           7
#define MPU9150_ACONFIG_YA_ST_BIT           6
#define MPU9150_ACONFIG_ZA_ST_BIT           5
#define MPU9150_ACONFIG_AFS_SEL_BIT         4
#define MPU9150_ACONFIG_AFS_SEL_LENGTH      2
#define MPU9150_ACONFIG_ACCEL_HPF_BIT       2
#define MPU9150_ACONFIG_ACCEL_HPF_LENGTH    3

#define MPU9150_ACCEL_FS_2          0x00
#define MPU9150_ACCEL_FS_4          0x01
#define MPU9150_ACCEL_FS_8          0x02
#define MPU9150_ACCEL_FS_16         0x03

#define MPU9150_DHPF_RESET          0x00
#define MPU9150_DHPF_5              0x01
#define MPU9150_DHPF_2P5            0x02
#define MPU9150_DHPF_1P25           0x03
#define MPU9150_DHPF_0P63           0x04
#define MPU9150_DHPF_HOLD           0x07

#define MPU9150_TEMP_FIFO_EN_BIT    7
#define MPU9150_XG_FIFO_EN_BIT      6
#define MPU9150_YG_FIFO_EN_BIT      5
#define MPU9150_ZG_FIFO_EN_BIT      4
#define MPU9150_ACCEL_FIFO_EN_BIT   3
#define MPU9150_SLV2_FIFO_EN_BIT    2
#define MPU9150_SLV1_FIFO_EN_BIT    1
#define MPU9150_SLV0_FIFO_EN_BIT    0

#define MPU9150_MULT_MST_EN_BIT     7
#define MPU9150_WAIT_FOR_ES_BIT     6
#define MPU9150_SLV_3_FIFO_EN_BIT   5
#define MPU9150_I2C_MST_P_NSR_BIT   4
#define MPU9150_I2C_MST_CLK_BIT     3
#define MPU9150_I2C_MST_CLK_LENGTH  4

#define MPU9150_CLOCK_DIV_348       0x0
#define MPU9150_CLOCK_DIV_333       0x1
#define MPU9150_CLOCK_DIV_320       0x2
#define MPU9150_CLOCK_DIV_308       0x3
#define MPU9150_CLOCK_DIV_296       0x4
#define MPU9150_CLOCK_DIV_286       0x5
#define MPU9150_CLOCK_DIV_276       0x6
#define MPU9150_CLOCK_DIV_267       0x7
#define MPU9150_CLOCK_DIV_258       0x8
#define MPU9150_CLOCK_DIV_500       0x9
#define MPU9150_CLOCK_DIV_471       0xA
#define MPU9150_CLOCK_DIV_444       0xB
#define MPU9150_CLOCK_DIV_421       0xC
#define MPU9150_CLOCK_DIV_400       0xD
#define MPU9150_CLOCK_DIV_381       0xE
#define MPU9150_CLOCK_DIV_364       0xF

#define MPU9150_I2C_SLV_RW_BIT      7
#define MPU9150_I2C_SLV_ADDR_BIT    6
#define MPU9150_I2C_SLV_ADDR_LENGTH 7
#define MPU9150_I2C_SLV_EN_BIT      7
#define MPU9150_I2C_SLV_BYTE_SW_BIT 6
#define MPU9150_I2C_SLV_REG_DIS_BIT 5
#define MPU9150_I2C_SLV_GRP_BIT     4
#define MPU9150_I2C_SLV_LEN_BIT     3
#define MPU9150_I2C_SLV_LEN_LENGTH  4

#define MPU9150_I2C_SLV4_RW_BIT         7
#define MPU9150_I2C_SLV4_ADDR_BIT       6
#define MPU9150_I2C_SLV4_ADDR_LENGTH    7
#define MPU9150_I2C_SLV4_EN_BIT         7
#define MPU9150_I2C_SLV4_INT_EN_BIT     6
#define MPU9150_I2C_SLV4_REG_DIS_BIT    5
#define MPU9150_I2C_SLV4_MST_DLY_BIT    4
#define MPU9150_I2C_SLV4_MST_DLY_LENGTH 5

#define MPU9150_MST_PASS_THROUGH_BIT    7
#define MPU9150_MST_I2C_SLV4_DONE_BIT   6
#define MPU9150_MST_I2C_LOST_ARB_BIT    5
#define MPU9150_MST_I2C_SLV4_NACK_BIT   4
#define MPU9150_MST_I2C_SLV3_NACK_BIT   3
#define MPU9150_MST_I2C_SLV2_NACK_BIT   2
#define MPU9150_MST_I2C_SLV1_NACK_BIT   1
#define MPU9150_MST_I2C_SLV0_NACK_BIT   0

#define MPU9150_INTCFG_INT_LEVEL_BIT        7
#define MPU9150_INTCFG_INT_OPEN_BIT         6
#define MPU9150_INTCFG_LATCH_INT_EN_BIT     5
#define MPU9150_INTCFG_INT_RD_CLEAR_BIT     4
#define MPU9150_INTCFG_FSYNC_INT_LEVEL_BIT  3
#define MPU9150_INTCFG_FSYNC_INT_EN_BIT     2
#define MPU9150_INTCFG_I2C_BYPASS_EN_BIT    1
#define MPU9150_INTCFG_CLKOUT_EN_BIT        0

#define MPU9150_INTMODE_ACTIVEHIGH  0x00
#define MPU9150_INTMODE_ACTIVELOW   0x01

#define MPU9150_INTDRV_PUSHPULL     0x00
#define MPU9150_INTDRV_OPENDRAIN    0x01

#define MPU9150_INTLATCH_50USPULSE  0x00
#define MPU9150_INTLATCH_WAITCLEAR  0x01

#define MPU9150_INTCLEAR_STATUSREAD 0x00
#define MPU9150_INTCLEAR_ANYREAD    0x01

#define MPU9150_INTERRUPT_FF_BIT            7
#define MPU9150_INTERRUPT_MOT_BIT           6
#define MPU9150_INTERRUPT_ZMOT_BIT          5
#define MPU9150_INTERRUPT_FIFO_OFLOW_BIT    4
#define MPU9150_INTERRUPT_I2C_MST_INT_BIT   3
#define MPU9150_INTERRUPT_PLL_RDY_INT_BIT   2
#define MPU9150_INTERRUPT_DMP_INT_BIT       1
#define MPU9150_INTERRUPT_DATA_RDY_BIT      0

// TODO: figure out what these actually do
// UMPL source code is not very obivous
#define MPU9150_DMPINT_5_BIT            5
#define MPU9150_DMPINT_4_BIT            4
#define MPU9150_DMPINT_3_BIT            3
#define MPU9150_DMPINT_2_BIT            2
#define MPU9150_DMPINT_1_BIT            1
#define MPU9150_DMPINT_0_BIT            0

#define MPU9150_MOTION_MOT_XNEG_BIT     7
#define MPU9150_MOTION_MOT_XPOS_BIT     6
#define MPU9150_MOTION_MOT_YNEG_BIT     5
#define MPU9150_MOTION_MOT_YPOS_BIT     4
#define MPU9150_MOTION_MOT_ZNEG_BIT     3
#define MPU9150_MOTION_MOT_ZPOS_BIT     2
#define MPU9150_MOTION_MOT_ZRMOT_BIT    0

#define MPU9150_DELAYCTRL_DELAY_ES_SHADOW_BIT   7
#define MPU9150_DELAYCTRL_I2C_SLV4_DLY_EN_BIT   4
#define MPU9150_DELAYCTRL_I2C_SLV3_DLY_EN_BIT   3
#define MPU9150_DELAYCTRL_I2C_SLV2_DLY_EN_BIT   2
#define MPU9150_DELAYCTRL_I2C_SLV1_DLY_EN_BIT   1
#define MPU9150_DELAYCTRL_I2C_SLV0_DLY_EN_BIT   0

#define MPU9150_PATHRESET_GYRO_RESET_BIT    2
#define MPU9150_PATHRESET_ACCEL_RESET_BIT   1
#define MPU9150_PATHRESET_TEMP_RESET_BIT    0

#define MPU9150_DETECT_ACCEL_ON_DELAY_BIT       5
#define MPU9150_DETECT_ACCEL_ON_DELAY_LENGTH    2
#define MPU9150_DETECT_FF_COUNT_BIT             3
#define MPU9150_DETECT_FF_COUNT_LENGTH          2
#define MPU9150_DETECT_MOT_COUNT_BIT            1
#define MPU9150_DETECT_MOT_COUNT_LENGTH         2

#define MPU9150_DETECT_DECREMENT_RESET  0x0
#define MPU9150_DETECT_DECREMENT_1      0x1
#define MPU9150_DETECT_DECREMENT_2      0x2
#define MPU9150_DETECT_DECREMENT_4      0x3

#define MPU9150_USERCTRL_DMP_EN_BIT             7
#define MPU9150_USERCTRL_FIFO_EN_BIT            6
#define MPU9150_USERCTRL_I2C_MST_EN_BIT         5
#define MPU9150_USERCTRL_I2C_IF_DIS_BIT         4
#define MPU9150_USERCTRL_DMP_RESET_BIT          3
#define MPU9150_USERCTRL_FIFO_RESET_BIT         2
#define MPU9150_USERCTRL_I2C_MST_RESET_BIT      1
#define MPU9150_USERCTRL_SIG_COND_RESET_BIT     0

#define MPU9150_PWR1_DEVICE_RESET_BIT   7
#define MPU9150_PWR1_SLEEP_BIT          6
#define MPU9150_PWR1_CYCLE_BIT          5
#define MPU9150_PWR1_TEMP_DIS_BIT       3
#define MPU9150_PWR1_CLKSEL_BIT         2
#define MPU9150_PWR1_CLKSEL_LENGTH      3

#define MPU9150_CLOCK_INTERNAL          0x00
#define MPU9150_CLOCK_PLL_XGYRO         0x01
#define MPU9150_CLOCK_PLL_YGYRO         0x02
#define MPU9150_CLOCK_PLL_ZGYRO         0x03
#define MPU9150_CLOCK_PLL_EXT32K        0x04
#define MPU9150_CLOCK_PLL_EXT19M        0x05
#define MPU9150_CLOCK_KEEP_RESET        0x07

#define MPU9150_PWR2_LP_WAKE_CTRL_BIT       7
#define MPU9150_PWR2_LP_WAKE_CTRL_LENGTH    2
#define MPU9150_PWR2_STBY_XA_BIT            5
#define MPU9150_PWR2_STBY_YA_BIT            4
#define MPU9150_PWR2_STBY_ZA_BIT            3
#define MPU9150_PWR2_STBY_XG_BIT            2
#define MPU9150_PWR2_STBY_YG_BIT            1
#define MPU9150_PWR2_STBY_ZG_BIT            0

#define MPU9150_WAKE_FREQ_1P25      0x0
#define MPU9150_WAKE_FREQ_2P5       0x1
#define MPU9150_WAKE_FREQ_5         0x2
#define MPU9150_WAKE_FREQ_10        0x3

#define MPU9150_BANKSEL_PRFTCH_EN_BIT       6
#define MPU9150_BANKSEL_CFG_USER_BANK_BIT   5
#define MPU9150_BANKSEL_MEM_SEL_BIT         4
#define MPU9150_BANKSEL_MEM_SEL_LENGTH      5

#define MPU9150_WHO_AM_I_BIT        6
#define MPU9150_WHO_AM_I_LENGTH     6

#define MPU9150_DMP_MEMORY_BANKS        8
#define MPU9150_DMP_MEMORY_BANK_SIZE    256
#define MPU9150_DMP_MEMORY_CHUNK_SIZE   16

#define BIT_I2C_MST_VDDIO   (0x80)
#define BIT_FIFO_EN         (0x40)
#define BIT_DMP_EN          (0x80)
#define BIT_FIFO_RST        (0x04)
#define BIT_DMP_RST         (0x08)
#define BIT_FIFO_OVERFLOW   (0x10)
#define BIT_DATA_RDY_EN     (0x01)
#define BIT_DMP_INT_EN      (0x02)
#define BIT_MOT_INT_EN      (0x40)
#define BITS_FSR            (0x18)
#define BITS_LPF            (0x07)
#define BITS_HPF            (0x07)
#define BITS_CLK            (0x07)
#define BIT_FIFO_SIZE_1024  (0x40)
#define BIT_FIFO_SIZE_2048  (0x80)
#define BIT_FIFO_SIZE_4096  (0xC0)
#define BIT_RESET           (0x80)
#define BIT_SLEEP           (0x40)
#define BIT_S0_DELAY_EN     (0x01)
#define BIT_S2_DELAY_EN     (0x04)
#define BITS_SLAVE_LENGTH   (0x0F)
#define BIT_SLAVE_BYTE_SW   (0x40)
#define BIT_SLAVE_GROUP     (0x10)
#define BIT_SLAVE_EN        (0x80)
#define BIT_I2C_READ        (0x80)
#define BITS_I2C_MASTER_DLY (0x1F)
#define BIT_AUX_IF_EN       (0x20)
#define BIT_ACTL            (0x80)
#define BIT_LATCH_EN        (0x20)
#define BIT_ANY_RD_CLR      (0x10)
#define BIT_BYPASS_EN       (0x02)
#define BITS_WOM_EN         (0xC0)
#define BIT_LPA_CYCLE       (0x20)
#define BIT_STBY_XA         (0x20)
#define BIT_STBY_YA         (0x10)
#define BIT_STBY_ZA         (0x08)
#define BIT_STBY_XG         (0x04)
#define BIT_STBY_YG         (0x02)
#define BIT_STBY_ZG         (0x01)
#define BIT_STBY_XYZA       (BIT_STBY_XA | BIT_STBY_YA | BIT_STBY_ZA)
#define BIT_STBY_XYZG       (BIT_STBY_XG | BIT_STBY_YG | BIT_STBY_ZG)


#define AKM_REG_WHOAMI      (0x00)

#define AKM_REG_ST1         (0x02)
#define AKM_REG_HXL         (0x03)
#define AKM_REG_ST2         (0x09)

#define AKM_REG_CNTL        (0x0A)
#define AKM_REG_ASTC        (0x0C)
#define AKM_REG_ASAX        (0x10)
#define AKM_REG_ASAY        (0x11)
#define AKM_REG_ASAZ        (0x12)

#define AKM_DATA_READY      (0x01)
#define AKM_DATA_OVERRUN    (0x02)
#define AKM_OVERFLOW        (0x80)
#define AKM_DATA_ERROR      (0x40)

#define AKM_BIT_SELF_TEST   (0x40)

#define AKM_POWER_DOWN          (0x00 | SUPPORTS_AK89xx_HIGH_SENS)
#define AKM_SINGLE_MEASUREMENT  (0x01 | SUPPORTS_AK89xx_HIGH_SENS)
#define AKM_FUSE_ROM_ACCESS     (0x0F | SUPPORTS_AK89xx_HIGH_SENS)
#define AKM_MODE_SELF_TEST      (0x08 | SUPPORTS_AK89xx_HIGH_SENS)
#define SUPPORTS_AK89xx_HIGH_SENS   (0x00)

#define AKM_WHOAMI      (0x48)

#define GYRORESOLUTION 0.061035156f //   4000 / 2^16
//#define GYRORESOLUTION 0.015258789f
#define ACCRESOLUTION  0.0002441406f /// 2.0 // 8g / 2^16
#define MAGSOLUTION    0.3f

#include "Framework.hpp"
#include "SensorI2C.hpp"

class MPU9150 : public HAL_Accelerometer_I, public HAL_Gyroscope_I, public HAL_Magnetometer_I{

	public:
		MPU9150();

	    virtual bool 	is_alive();
	    virtual bool 	is_error();
	    virtual void    restart();

	    virtual int16_t get_acc_data(float& x, float& y, float& z);
	    virtual void    set_acc_calibration(AccelerometerCalibration& new_calibration);
	    virtual void    get_acc_calibration(AccelerometerCalibration& return_calibration);
		virtual void 	start_acc_calibration(void);
		virtual void 	stop_acc_calibration(void);

		virtual int16_t get_gyro_data(float&, float&, float&);
		virtual void    set_gyro_calibration(GyroscopeCalibration&);
		virtual void    get_gyro_calibration(GyroscopeCalibration&);
		virtual void 	start_gyro_calibration(void);
		virtual void 	stop_gyro_calibration(void);

		virtual int16_t get_mag_data(float& x, float& y, float& z){
			return 1;
		}
		virtual int16_t	get_raw_mag_data(int16_t* data){return 1; }
		virtual void  	get_mag_calibration(MagnetometerCalibration* c){}
		virtual void	set_mag_calibration(MagnetometerCalibration* c){}
		virtual void 	start_mag_calibration(void){}
		virtual void 	stop_mag_calibration(void){}
	private:
	    SensorI2C& i2c;

	    //Accelerometer variables:
	    float last_acc_values[3] = {0};
	    uint32_t acc_timestamp = 0;
	    AccelerometerCalibration acc_calibration;

	    //Gyroscope variables:
	    float last_gyro_values[3] = {0};
	    uint32_t gyro_timestamp = 0;
	    GyroscopeCalibration gyro_calibration;

	    //Calibrating variables:
	    bool gyro_calibrating = false;
	    bool acc_calibrating = false;
	    bool mag_calibrating = false;
	    float gyro_calibration_sum[3];
	    int   gyro_calibration_points;
	    float acc_calibration_sum[3];
	    int   acc_calibration_points;
	    float mag_calibration_sum[3];
	    int   mag_calibration_points;

	    //Methods:
	    bool setup();
	    int8_t set_gyro_fsr(uint16_t fsr);
	    int8_t set_accel_fsr(uint8_t fsr);
	    int8_t set_sample_rate(uint16_t rate);
	    int8_t set_sensors(uint8_t sensors);

	    int8_t set_lpf(uint8_t lpf);

	    int8_t set_compass_sample_rate(uint16_t rate);
	    int8_t setup_compass(void);
	    int8_t set_bypass(uint8_t bypass_on);

	    void process_gyro_calibration();
	    void process_acc_calibration(){}
	    void process_mag_calibration(){}
};
