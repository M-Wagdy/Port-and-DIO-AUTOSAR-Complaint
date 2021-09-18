 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM 
 *              Microcontroller - Port Driver
 *
 * Author: Mohamed Hisham
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION               (1U)
#define PORT_CFG_SW_MINOR_VERSION               (0U)
#define PORT_CFG_SW_PATCH_VERSION               (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION       (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION       (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION       (3U)


/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                   (STD_ON)

/* Pre-compile option for Set Pin Direction API */
#define PORT_SET_PIN_DIRECTION_API              (STD_ON)

/* Pre-compile option for presence of Set Pin Mode API */
#define PORT_SET_PIN_MODE_API                   (STD_ON)

/* Pre-compile option for presence of Version Info API */
#define PORT_VERSION_INFO_API                   (STD_ON)

/* Number of comfigured pins*/
#define PORT_CONFIGURED_PINS                 (43U)

/* Configured Port ID's  */
#define PORT_A_INDEX                    0U 
#define PORT_B_INDEX                    1U 
#define PORT_C_INDEX                    2U 
#define PORT_D_INDEX                    3U 
#define PORT_E_INDEX                    4U 
#define PORT_F_INDEX                    5U 

/* Configured Channel ID's */
#define PORT_A_PIN_0                        (Port_PinType)0
#define PORT_A_PIN_1                        (Port_PinType)1
#define PORT_A_PIN_2                        (Port_PinType)2
#define PORT_A_PIN_3                        (Port_PinType)3
#define PORT_A_PIN_4                        (Port_PinType)4
#define PORT_A_PIN_5                        (Port_PinType)5
#define PORT_A_PIN_6                        (Port_PinType)6
#define PORT_A_PIN_7                        (Port_PinType)7

#define PORT_B_PIN_0                        (Port_PinType)0
#define PORT_B_PIN_1                        (Port_PinType)1
#define PORT_B_PIN_2                        (Port_PinType)2
#define PORT_B_PIN_3                        (Port_PinType)3
#define PORT_B_PIN_4                        (Port_PinType)4
#define PORT_B_PIN_5                        (Port_PinType)5
#define PORT_B_PIN_6                        (Port_PinType)6
#define PORT_B_PIN_7                        (Port_PinType)7

#define PORT_C_PIN_0                        (Port_PinType)0
#define PORT_C_PIN_1                        (Port_PinType)1
#define PORT_C_PIN_2                        (Port_PinType)2
#define PORT_C_PIN_3                        (Port_PinType)3
#define PORT_C_PIN_4                        (Port_PinType)4
#define PORT_C_PIN_5                        (Port_PinType)5
#define PORT_C_PIN_6                        (Port_PinType)6
#define PORT_C_PIN_7                        (Port_PinType)7

#define PORT_D_PIN_0                        (Port_PinType)0
#define PORT_D_PIN_1                        (Port_PinType)1
#define PORT_D_PIN_2                        (Port_PinType)2
#define PORT_D_PIN_3                        (Port_PinType)3
#define PORT_D_PIN_4                        (Port_PinType)4
#define PORT_D_PIN_5                        (Port_PinType)5
#define PORT_D_PIN_6                        (Port_PinType)6
#define PORT_D_PIN_7                        (Port_PinType)7

#define PORT_E_PIN_0                        (Port_PinType)0
#define PORT_E_PIN_1                        (Port_PinType)1
#define PORT_E_PIN_2                        (Port_PinType)2
#define PORT_E_PIN_3                        (Port_PinType)3
#define PORT_E_PIN_4                        (Port_PinType)4
#define PORT_E_PIN_5                        (Port_PinType)5

#define PORT_F_PIN_0                        (Port_PinType)0
#define PORT_F_PIN_1                        (Port_PinType)1
#define PORT_F_PIN_2                        (Port_PinType)2
#define PORT_F_PIN_3                        (Port_PinType)3
#define PORT_F_PIN_4                        (Port_PinType)4

/* Pins Directions */
#define PORT_A_PIN_0_DIR            PORT_PIN_IN
#define PORT_A_PIN_1_DIR            PORT_PIN_IN
#define PORT_A_PIN_2_DIR            PORT_PIN_IN
#define PORT_A_PIN_3_DIR            PORT_PIN_IN
#define PORT_A_PIN_4_DIR            PORT_PIN_IN
#define PORT_A_PIN_5_DIR            PORT_PIN_IN
#define PORT_A_PIN_6_DIR            PORT_PIN_IN
#define PORT_A_PIN_7_DIR            PORT_PIN_IN

#define PORT_B_PIN_0_DIR            PORT_PIN_IN
#define PORT_B_PIN_1_DIR            PORT_PIN_IN
#define PORT_B_PIN_2_DIR            PORT_PIN_IN
#define PORT_B_PIN_3_DIR            PORT_PIN_IN
#define PORT_B_PIN_4_DIR            PORT_PIN_IN
#define PORT_B_PIN_5_DIR            PORT_PIN_IN
#define PORT_B_PIN_6_DIR            PORT_PIN_IN
#define PORT_B_PIN_7_DIR            PORT_PIN_IN

#define PORT_C_PIN_0_DIR            PORT_PIN_IN
#define PORT_C_PIN_1_DIR            PORT_PIN_IN
#define PORT_C_PIN_2_DIR            PORT_PIN_IN
#define PORT_C_PIN_3_DIR            PORT_PIN_IN
#define PORT_C_PIN_4_DIR            PORT_PIN_IN
#define PORT_C_PIN_5_DIR            PORT_PIN_IN 
#define PORT_C_PIN_6_DIR            PORT_PIN_IN
#define PORT_C_PIN_7_DIR            PORT_PIN_IN

#define PORT_D_PIN_0_DIR            PORT_PIN_IN
#define PORT_D_PIN_1_DIR            PORT_PIN_IN
#define PORT_D_PIN_2_DIR            PORT_PIN_IN 
#define PORT_D_PIN_3_DIR            PORT_PIN_IN
#define PORT_D_PIN_4_DIR            PORT_PIN_IN
#define PORT_D_PIN_5_DIR            PORT_PIN_IN
#define PORT_D_PIN_6_DIR            PORT_PIN_IN
#define PORT_D_PIN_7_DIR            PORT_PIN_IN

#define PORT_E_PIN_0_DIR            PORT_PIN_IN
#define PORT_E_PIN_1_DIR            PORT_PIN_IN
#define PORT_E_PIN_2_DIR            PORT_PIN_IN 
#define PORT_E_PIN_3_DIR            PORT_PIN_IN
#define PORT_E_PIN_4_DIR            PORT_PIN_IN
#define PORT_E_PIN_5_DIR            PORT_PIN_IN

#define PORT_F_PIN_0_DIR            PORT_PIN_IN
#define PORT_F_PIN_1_DIR            PORT_PIN_OUT
#define PORT_F_PIN_2_DIR            PORT_PIN_IN 
#define PORT_F_PIN_3_DIR            PORT_PIN_IN
#define PORT_F_PIN_4_DIR            PORT_PIN_IN

/* Pins Levels */
#define PORT_A_PIN_0_VALUE          STD_LOW
#define PORT_A_PIN_1_VALUE          STD_LOW
#define PORT_A_PIN_2_VALUE          STD_LOW
#define PORT_A_PIN_3_VALUE          STD_LOW
#define PORT_A_PIN_4_VALUE          STD_LOW
#define PORT_A_PIN_5_VALUE          STD_LOW
#define PORT_A_PIN_6_VALUE          STD_LOW
#define PORT_A_PIN_7_VALUE          STD_LOW

#define PORT_B_PIN_0_VALUE          STD_LOW
#define PORT_B_PIN_1_VALUE          STD_LOW
#define PORT_B_PIN_2_VALUE          STD_LOW
#define PORT_B_PIN_3_VALUE          STD_LOW
#define PORT_B_PIN_4_VALUE          STD_LOW
#define PORT_B_PIN_5_VALUE          STD_LOW
#define PORT_B_PIN_6_VALUE          STD_LOW
#define PORT_B_PIN_7_VALUE          STD_LOW

#define PORT_C_PIN_0_VALUE          STD_LOW
#define PORT_C_PIN_1_VALUE          STD_LOW
#define PORT_C_PIN_2_VALUE          STD_LOW
#define PORT_C_PIN_3_VALUE          STD_LOW
#define PORT_C_PIN_4_VALUE          STD_LOW
#define PORT_C_PIN_5_VALUE          STD_LOW
#define PORT_C_PIN_6_VALUE          STD_LOW
#define PORT_C_PIN_7_VALUE          STD_LOW

#define PORT_D_PIN_0_VALUE          STD_LOW
#define PORT_D_PIN_1_VALUE          STD_LOW
#define PORT_D_PIN_2_VALUE          STD_LOW
#define PORT_D_PIN_3_VALUE          STD_LOW
#define PORT_D_PIN_4_VALUE          STD_LOW
#define PORT_D_PIN_5_VALUE          STD_LOW
#define PORT_D_PIN_6_VALUE          STD_LOW
#define PORT_D_PIN_7_VALUE          STD_LOW

#define PORT_E_PIN_0_VALUE          STD_LOW
#define PORT_E_PIN_1_VALUE          STD_LOW
#define PORT_E_PIN_2_VALUE          STD_LOW
#define PORT_E_PIN_3_VALUE          STD_LOW
#define PORT_E_PIN_4_VALUE          STD_LOW
#define PORT_E_PIN_5_VALUE          STD_LOW

#define PORT_F_PIN_0_VALUE          STD_LOW
#define PORT_F_PIN_1_VALUE          STD_LOW
#define PORT_F_PIN_2_VALUE          STD_LOW
#define PORT_F_PIN_3_VALUE          STD_LOW
#define PORT_F_PIN_4_VALUE          STD_LOW

/* Pin Resistors */
#define PORT_A_PIN_0_RESISTOR       OFF
#define PORT_A_PIN_1_RESISTOR       OFF
#define PORT_A_PIN_2_RESISTOR       OFF
#define PORT_A_PIN_3_RESISTOR       OFF
#define PORT_A_PIN_4_RESISTOR       OFF
#define PORT_A_PIN_5_RESISTOR       OFF
#define PORT_A_PIN_6_RESISTOR       OFF
#define PORT_A_PIN_7_RESISTOR       OFF

#define PORT_B_PIN_0_RESISTOR       OFF
#define PORT_B_PIN_1_RESISTOR       OFF
#define PORT_B_PIN_2_RESISTOR       OFF
#define PORT_B_PIN_3_RESISTOR       OFF
#define PORT_B_PIN_4_RESISTOR       OFF
#define PORT_B_PIN_5_RESISTOR       OFF
#define PORT_B_PIN_6_RESISTOR       OFF
#define PORT_B_PIN_7_RESISTOR       OFF

#define PORT_C_PIN_0_RESISTOR       OFF
#define PORT_C_PIN_1_RESISTOR       OFF
#define PORT_C_PIN_2_RESISTOR       OFF
#define PORT_C_PIN_3_RESISTOR       OFF
#define PORT_C_PIN_4_RESISTOR       OFF
#define PORT_C_PIN_5_RESISTOR       OFF
#define PORT_C_PIN_6_RESISTOR       OFF
#define PORT_C_PIN_7_RESISTOR       OFF

#define PORT_D_PIN_0_RESISTOR       OFF
#define PORT_D_PIN_1_RESISTOR       OFF
#define PORT_D_PIN_2_RESISTOR       OFF
#define PORT_D_PIN_3_RESISTOR       OFF
#define PORT_D_PIN_4_RESISTOR       OFF
#define PORT_D_PIN_5_RESISTOR       OFF
#define PORT_D_PIN_6_RESISTOR       OFF
#define PORT_D_PIN_7_RESISTOR       OFF

#define PORT_E_PIN_0_RESISTOR       OFF
#define PORT_E_PIN_1_RESISTOR       OFF
#define PORT_E_PIN_2_RESISTOR       OFF
#define PORT_E_PIN_3_RESISTOR       OFF
#define PORT_E_PIN_4_RESISTOR       OFF
#define PORT_E_PIN_5_RESISTOR       OFF

#define PORT_F_PIN_0_RESISTOR       OFF
#define PORT_F_PIN_1_RESISTOR       OFF
#define PORT_F_PIN_2_RESISTOR       OFF
#define PORT_F_PIN_3_RESISTOR       OFF
#define PORT_F_PIN_4_RESISTOR       PULL_UP

/* Pin direction changeable. */
#define PORT_A_PIN_0_DIR_CHANGEABLE     STD_OFF
#define PORT_A_PIN_1_DIR_CHANGEABLE     STD_OFF
#define PORT_A_PIN_2_DIR_CHANGEABLE     STD_OFF
#define PORT_A_PIN_3_DIR_CHANGEABLE     STD_OFF
#define PORT_A_PIN_4_DIR_CHANGEABLE     STD_OFF
#define PORT_A_PIN_5_DIR_CHANGEABLE     STD_OFF
#define PORT_A_PIN_6_DIR_CHANGEABLE     STD_OFF
#define PORT_A_PIN_7_DIR_CHANGEABLE     STD_OFF

#define PORT_B_PIN_0_DIR_CHANGEABLE     STD_OFF
#define PORT_B_PIN_1_DIR_CHANGEABLE     STD_OFF
#define PORT_B_PIN_2_DIR_CHANGEABLE     STD_OFF
#define PORT_B_PIN_3_DIR_CHANGEABLE     STD_OFF
#define PORT_B_PIN_4_DIR_CHANGEABLE     STD_OFF
#define PORT_B_PIN_5_DIR_CHANGEABLE     STD_OFF
#define PORT_B_PIN_6_DIR_CHANGEABLE     STD_OFF
#define PORT_B_PIN_7_DIR_CHANGEABLE     STD_OFF

#define PORT_C_PIN_0_DIR_CHANGEABLE     STD_OFF
#define PORT_C_PIN_1_DIR_CHANGEABLE     STD_OFF
#define PORT_C_PIN_2_DIR_CHANGEABLE     STD_OFF
#define PORT_C_PIN_3_DIR_CHANGEABLE     STD_OFF
#define PORT_C_PIN_4_DIR_CHANGEABLE     STD_OFF
#define PORT_C_PIN_5_DIR_CHANGEABLE     STD_OFF
#define PORT_C_PIN_6_DIR_CHANGEABLE     STD_OFF
#define PORT_C_PIN_7_DIR_CHANGEABLE     STD_OFF

#define PORT_D_PIN_0_DIR_CHANGEABLE     STD_OFF
#define PORT_D_PIN_1_DIR_CHANGEABLE     STD_OFF
#define PORT_D_PIN_2_DIR_CHANGEABLE     STD_OFF
#define PORT_D_PIN_3_DIR_CHANGEABLE     STD_OFF
#define PORT_D_PIN_4_DIR_CHANGEABLE     STD_OFF
#define PORT_D_PIN_5_DIR_CHANGEABLE     STD_OFF
#define PORT_D_PIN_6_DIR_CHANGEABLE     STD_OFF
#define PORT_D_PIN_7_DIR_CHANGEABLE     STD_OFF

#define PORT_E_PIN_0_DIR_CHANGEABLE     STD_OFF
#define PORT_E_PIN_1_DIR_CHANGEABLE     STD_OFF
#define PORT_E_PIN_2_DIR_CHANGEABLE     STD_OFF
#define PORT_E_PIN_3_DIR_CHANGEABLE     STD_OFF
#define PORT_E_PIN_4_DIR_CHANGEABLE     STD_OFF
#define PORT_E_PIN_5_DIR_CHANGEABLE     STD_OFF

#define PORT_F_PIN_0_DIR_CHANGEABLE     STD_OFF
#define PORT_F_PIN_1_DIR_CHANGEABLE     STD_OFF
#define PORT_F_PIN_2_DIR_CHANGEABLE     STD_OFF
#define PORT_F_PIN_3_DIR_CHANGEABLE     STD_OFF
#define PORT_F_PIN_4_DIR_CHANGEABLE     STD_OFF

/* Pin mode type */ 
#define DIO                       0U
#define ADC                       1U
#define UART                      2U
#define CAN                       3U
#define PWM                       4U
#define GPT                       5U
#define I2C                       6U
#define SSI                       7U

/* Pin mode. */
#define PORT_A_PIN_0_MODE         DIO
#define PORT_A_PIN_1_MODE         DIO
#define PORT_A_PIN_2_MODE         DIO
#define PORT_A_PIN_3_MODE         DIO
#define PORT_A_PIN_4_MODE         DIO
#define PORT_A_PIN_5_MODE         DIO
#define PORT_A_PIN_6_MODE         DIO
#define PORT_A_PIN_7_MODE         DIO

#define PORT_B_PIN_0_MODE         DIO
#define PORT_B_PIN_1_MODE         DIO
#define PORT_B_PIN_2_MODE         DIO
#define PORT_B_PIN_3_MODE         DIO
#define PORT_B_PIN_4_MODE         DIO
#define PORT_B_PIN_5_MODE         DIO
#define PORT_B_PIN_6_MODE         DIO
#define PORT_B_PIN_7_MODE         DIO

#define PORT_C_PIN_0_MODE         DIO
#define PORT_C_PIN_1_MODE         DIO
#define PORT_C_PIN_2_MODE         DIO
#define PORT_C_PIN_3_MODE         DIO
#define PORT_C_PIN_4_MODE         DIO
#define PORT_C_PIN_5_MODE         DIO
#define PORT_C_PIN_6_MODE         DIO
#define PORT_C_PIN_7_MODE         DIO

#define PORT_D_PIN_0_MODE         DIO
#define PORT_D_PIN_1_MODE         DIO
#define PORT_D_PIN_2_MODE         DIO
#define PORT_D_PIN_3_MODE         DIO
#define PORT_D_PIN_4_MODE         DIO
#define PORT_D_PIN_5_MODE         DIO
#define PORT_D_PIN_6_MODE         DIO
#define PORT_D_PIN_7_MODE         DIO
   
#define PORT_E_PIN_0_MODE         DIO
#define PORT_E_PIN_1_MODE         DIO
#define PORT_E_PIN_2_MODE         DIO
#define PORT_E_PIN_3_MODE         DIO
#define PORT_E_PIN_4_MODE         DIO
#define PORT_E_PIN_5_MODE         DIO

#define PORT_F_PIN_0_MODE         DIO
#define PORT_F_PIN_1_MODE         DIO
#define PORT_F_PIN_2_MODE         DIO
#define PORT_F_PIN_3_MODE         DIO
#define PORT_F_PIN_4_MODE         DIO

/* Pin PCTL Register Mode Number */
#define PORT_A_PIN_0_PCTL         0U
#define PORT_A_PIN_1_PCTL         0U
#define PORT_A_PIN_2_PCTL         0U
#define PORT_A_PIN_3_PCTL         0U
#define PORT_A_PIN_4_PCTL         0U
#define PORT_A_PIN_5_PCTL         0U
#define PORT_A_PIN_6_PCTL         0U
#define PORT_A_PIN_7_PCTL         0U

#define PORT_B_PIN_0_PCTL         0U
#define PORT_B_PIN_1_PCTL         0U
#define PORT_B_PIN_2_PCTL         0U
#define PORT_B_PIN_3_PCTL         0U
#define PORT_B_PIN_4_PCTL         0U
#define PORT_B_PIN_5_PCTL         0U
#define PORT_B_PIN_6_PCTL         0U
#define PORT_B_PIN_7_PCTL         0U

#define PORT_C_PIN_0_PCTL         0U
#define PORT_C_PIN_1_PCTL         0U
#define PORT_C_PIN_2_PCTL         0U
#define PORT_C_PIN_3_PCTL         0U
#define PORT_C_PIN_4_PCTL         0U
#define PORT_C_PIN_5_PCTL         0U
#define PORT_C_PIN_6_PCTL         0U
#define PORT_C_PIN_7_PCTL         0U

#define PORT_D_PIN_0_PCTL         0U
#define PORT_D_PIN_1_PCTL         0U
#define PORT_D_PIN_2_PCTL         0U
#define PORT_D_PIN_3_PCTL         0U
#define PORT_D_PIN_4_PCTL         0U
#define PORT_D_PIN_5_PCTL         0U
#define PORT_D_PIN_6_PCTL         0U
#define PORT_D_PIN_7_PCTL         0U
   
#define PORT_E_PIN_0_PCTL         0U
#define PORT_E_PIN_1_PCTL         0U
#define PORT_E_PIN_2_PCTL         0U
#define PORT_E_PIN_3_PCTL         0U
#define PORT_E_PIN_4_PCTL         0U
#define PORT_E_PIN_5_PCTL         0U

#define PORT_F_PIN_0_PCTL         0U
#define PORT_F_PIN_1_PCTL         0U
#define PORT_F_PIN_2_PCTL         0U
#define PORT_F_PIN_3_PCTL         0U
#define PORT_F_PIN_4_PCTL         0U

/* Pin mode changeable. */
#define PORT_A_PIN_0_MODE_CHANGEABLE    STD_OFF
#define PORT_A_PIN_1_MODE_CHANGEABLE    STD_OFF
#define PORT_A_PIN_2_MODE_CHANGEABLE    STD_OFF
#define PORT_A_PIN_3_MODE_CHANGEABLE    STD_OFF
#define PORT_A_PIN_4_MODE_CHANGEABLE    STD_OFF
#define PORT_A_PIN_5_MODE_CHANGEABLE    STD_OFF
#define PORT_A_PIN_6_MODE_CHANGEABLE    STD_OFF
#define PORT_A_PIN_7_MODE_CHANGEABLE    STD_OFF

#define PORT_B_PIN_0_MODE_CHANGEABLE    STD_OFF
#define PORT_B_PIN_1_MODE_CHANGEABLE    STD_OFF
#define PORT_B_PIN_2_MODE_CHANGEABLE    STD_OFF
#define PORT_B_PIN_3_MODE_CHANGEABLE    STD_OFF
#define PORT_B_PIN_4_MODE_CHANGEABLE    STD_OFF
#define PORT_B_PIN_5_MODE_CHANGEABLE    STD_OFF
#define PORT_B_PIN_6_MODE_CHANGEABLE    STD_OFF
#define PORT_B_PIN_7_MODE_CHANGEABLE    STD_OFF

#define PORT_C_PIN_0_MODE_CHANGEABLE    STD_OFF
#define PORT_C_PIN_1_MODE_CHANGEABLE    STD_OFF
#define PORT_C_PIN_2_MODE_CHANGEABLE    STD_OFF
#define PORT_C_PIN_3_MODE_CHANGEABLE    STD_OFF
#define PORT_C_PIN_4_MODE_CHANGEABLE    STD_OFF
#define PORT_C_PIN_5_MODE_CHANGEABLE    STD_OFF
#define PORT_C_PIN_6_MODE_CHANGEABLE    STD_OFF
#define PORT_C_PIN_7_MODE_CHANGEABLE    STD_OFF

#define PORT_D_PIN_0_MODE_CHANGEABLE    STD_OFF
#define PORT_D_PIN_1_MODE_CHANGEABLE    STD_OFF
#define PORT_D_PIN_2_MODE_CHANGEABLE    STD_OFF
#define PORT_D_PIN_3_MODE_CHANGEABLE    STD_OFF
#define PORT_D_PIN_4_MODE_CHANGEABLE    STD_OFF
#define PORT_D_PIN_5_MODE_CHANGEABLE    STD_OFF
#define PORT_D_PIN_6_MODE_CHANGEABLE    STD_OFF
#define PORT_D_PIN_7_MODE_CHANGEABLE    STD_OFF

#define PORT_E_PIN_0_MODE_CHANGEABLE    STD_OFF
#define PORT_E_PIN_1_MODE_CHANGEABLE    STD_OFF
#define PORT_E_PIN_2_MODE_CHANGEABLE    STD_OFF
#define PORT_E_PIN_3_MODE_CHANGEABLE    STD_OFF
#define PORT_E_PIN_4_MODE_CHANGEABLE    STD_OFF
#define PORT_E_PIN_5_MODE_CHANGEABLE    STD_OFF

#define PORT_F_PIN_0_MODE_CHANGEABLE    STD_OFF
#define PORT_F_PIN_1_MODE_CHANGEABLE    STD_OFF
#define PORT_F_PIN_2_MODE_CHANGEABLE    STD_OFF
#define PORT_F_PIN_3_MODE_CHANGEABLE    STD_OFF
#define PORT_F_PIN_4_MODE_CHANGEABLE    STD_OFF

#endif /* PORT_CFG_H */
