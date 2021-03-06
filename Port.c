 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Hisham
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"


#if (DIO_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Pin_ConfigType * Port_PinConfiguration = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set. 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Provide initial value for o/p pin
*              - Setup the internal resistor for i/p pin
*              - Setup the mode for GPIO pin
************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr )
{
    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    volatile uint32 delay = 0;
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* check if the input configuration pointer is not a NULL_PTR */
      if (NULL_PTR == ConfigPtr)
      {
        /* Report to DET  */
        Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                         PORT_INIT_SID, PORT_E_PARAM_CONFIG);
      }
      else
    #endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
    {
      Port_PinConfiguration = ConfigPtr->Pin_config; /* address of the first Pin_config structure --> Pin_config[0] */
      
      /* Configure All Pins By Looping On The Whole Pin_Config Array. */
      for(int i =0; i<PORT_CONFIGURED_PINS; i++)
      {
        /* Point to the correct PORT Base Address according to the Port Id stored in the port_num member */
        switch(ConfigPtr->Pin_config[i].port_num)
        {
            case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                     break;
            case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                     break;
            case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                     break;
            case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                     break;
            case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                     break;
            case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                     break;
        }
        
        /* Enable clock for PORT and allow time for clock to start*/
        SYSCTL_REGCGC2_REG |= (1<<ConfigPtr->Pin_config[i].port_num);
        delay = SYSCTL_REGCGC2_REG;
        
        if( ((ConfigPtr->Pin_config[i].port_num == 3) && (ConfigPtr->Pin_config[i].pin_num == 7)) || ((ConfigPtr->Pin_config[i].port_num == 5) && (ConfigPtr->Pin_config[i].pin_num == 0)) ) /* PD7 or PF0 */
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */   
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
        }
        else if( (ConfigPtr->Pin_config[i].port_num == 2) && (ConfigPtr->Pin_config[i].pin_num <= 3) ) /* PC0 to PC3 */
        {
            /* Do Nothing ...  this is the JTAG pins */
            continue;
        }
        else
        {
            /* Do Nothing ... No need to unlock the commit register for this pin */
        }
        
        /* Configure Pin Direction */
        if(ConfigPtr->Pin_config[i].direction == PORT_PIN_OUT)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
            
            if(ConfigPtr->Pin_config[i].initial_value == STD_HIGH)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
            }
        }
        else if(ConfigPtr->Pin_config[i].direction == PORT_PIN_IN)
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            
            if(ConfigPtr->Pin_config[i].resistor == PULL_UP)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
            }
            else if(ConfigPtr->Pin_config[i].resistor == PULL_DOWN)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
            }
        }
        else
        {
            /* Do Nothing */
        }
        
        /* Configure Pin Mode */
        switch(ConfigPtr->Pin_config[i].mode)
        {
          case DIO:
            /* Clear the corresponding bit in the GPIOAFSEL register to disable the alternative functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);  
            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);  
            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Pin_config[i].pin_num * 4));  
            break;
          case ADC:
            /* Set the corresponding bit in the GPIOAFSEL register to enable the alternative functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);  
            /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);
            /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);  
            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Pin_config[i].pin_num * 4));  
            break;
          case CAN:
          case SSI:
          case UART:
          case I2C:
          case GPT:
          case PWM:
            /* Set the corresponding bit in the GPIOAFSEL register to enable the alternative functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);  
            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Pin_config[i].pin_num);  
            /* Set the corresponding bit in the GPIOPCTL register to select the alternative functionality on this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (ConfigPtr->Pin_config[i].pctl_mode << (ConfigPtr->Pin_config[i].pin_num * 4));
            break;
        }
      }
      
      /* Set Port Status To Initialized */
      Port_Status = PORT_INITIALIZED;
    }
}

/******************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number.
*                  Direction - Port Pin Direction .         
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction .
*******************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction)
{
  volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
  boolean error = FALSE;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the port is initialized */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
    /* check if Incorrect Port Pin ID passed */
    if (Pin >= PORT_CONFIGURED_PINS)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
    /* check if pin direction is unchangeable */
    if (STD_OFF == Port_PinConfiguration[Pin].direction_changable)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
  #endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
  if(FALSE == error)
  {
    /* Point to the correct PORT Base Address according to the Port Id stored in the port_num member */
    switch(Port_PinConfiguration[Pin].port_num)
    {
      case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
               break;
      case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
               break;
      case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
               break;
      case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
               break;
      case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
               break;
      case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
               break;
    }
    
    /* Configure Pin Direction */
    if(Port_PinConfiguration[Pin].direction == PORT_PIN_OUT)
    {
      /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);                
      
      if(Port_PinConfiguration[Pin].initial_value == STD_HIGH)
      {
        /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);          
      }
      else
      {
        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);        
      }
    }
    else if(Port_PinConfiguration[Pin].direction == PORT_PIN_IN)
    {
      /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);             
      
      if(Port_PinConfiguration[Pin].resistor == PULL_UP)
      {
        /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);       
      }
      else if(Port_PinConfiguration[Pin].resistor == PULL_DOWN)
      {
        /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);     
      }
      else
      {
        /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);     
        /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);   
      }
    }
    else
    {
      /* Do Nothing */
    }
  }
}
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

/******************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None    
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
*******************************************************************************/
void Port_RefreshPortDirection( void )
{
  volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the port is initialized */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
    }
    else
  #endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Refresh All Pins By Looping On The Whole Pin_Config Array. */
    for(int i =0; i<PORT_CONFIGURED_PINS; i++)
    {
      /* Point to the correct PORT Base Address according to the Port Id stored in the port_num member */
      switch(Port_PinConfiguration[i].port_num)
      {
        case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                 break;
        case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                 break;
        case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                 break;
        case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                 break;
        case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                 break;
        case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                 break;
      }
      
      if( STD_OFF == Port_PinConfiguration[i].direction_changable )
      {
          /* Do Nothing ...  This Is The Unchangable Direction Pins */
          continue;
      }
      else
      {
          /* Do Nothing */
      }
      
      /* Configure Pin Direction */
      if(Port_PinConfiguration[i].direction == PORT_PIN_OUT)
      {
        /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PinConfiguration[i].pin_num);                
        
        if(Port_PinConfiguration[i].initial_value == STD_HIGH)
        {
          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PinConfiguration[i].pin_num);          
        }
        else
        {
          /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PinConfiguration[i].pin_num);        
        }
      }
      else if(Port_PinConfiguration[i].direction == PORT_PIN_IN)
      {
        /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PinConfiguration[i].pin_num);             
        
        if(Port_PinConfiguration[i].resistor == PULL_UP)
        {
          /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PinConfiguration[i].pin_num);       
        }
        else if(Port_PinConfiguration[i].resistor == PULL_DOWN)
        {
          /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PinConfiguration[i].pin_num);     
        }
        else
        {
          /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PinConfiguration[i].pin_num);     
          /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PinConfiguration[i].pin_num);   
        }
      }
      else
      {
        /* Do Nothing */
      }
    }
  }
}

/******************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None    
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version 
*                                 information of this module. 
* Return value: None
* Description: Returns the version information of this module. 
*******************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
  boolean error = FALSE;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the port is initialized */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
    /* Check if input pointer is not Null pointer */
    if (NULL_PTR == versioninfo)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
  #endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
  if(FALSE == error)
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)PORT_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
  }
}
#endif /* (PORT_VERSION_INFO_API == STD_ON) */

/******************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number 
*                  Mode - New Port Pin mode to be set on port pin.     
* Parameters (inout): None
* Parameters (out): None 
* Return value: None
* Description: Sets the port pin mode. 
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
  volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
  boolean error = FALSE;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the port is initialized */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
    /* check if Incorrect Port Pin ID passed */
    if (Pin >= PORT_CONFIGURED_PINS)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
    /* check if pin mode is unchangeable */
    if (STD_OFF == Port_PinConfiguration[Pin].mode_changable)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
    /* check if mode is not valid */
    if (DIO != Port_PinConfiguration[Pin].mode && ADC != Port_PinConfiguration[Pin].mode && 
        UART != Port_PinConfiguration[Pin].mode &&CAN != Port_PinConfiguration[Pin].mode && 
        PWM != Port_PinConfiguration[Pin].mode && GPT != Port_PinConfiguration[Pin].mode &&
        I2C != Port_PinConfiguration[Pin].mode && SSI != Port_PinConfiguration[Pin].mode)
    {
      /* Report to DET  */
      Det_ReportError( PORT_MODULE_ID, PORT_INSTANCE_ID, 
                       PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
      error = TRUE;
    }
    else
    {
      /* Do Nothing */
    }
  #endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
  if(FALSE == error)
  {
    /* Point to the correct PORT Base Address according to the Port Id stored in the port_num member */
    switch(Port_PinConfiguration[Pin].port_num)
    {
      case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
               break;
      case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
               break;
      case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
               break;
      case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
               break;
      case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
               break;
      case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
               break;
    }
    
    /* Configure Pin Mode */
    switch(Port_PinConfiguration[Pin].mode)
    {
      case DIO:
        /* Clear the corresponding bit in the GPIOAFSEL register to disable the alternative functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);  
        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);
        /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);  
        /* Clear the PMCx bits for this pin */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_PinConfiguration[Pin].pin_num * 4));  
        break;
      case ADC:
        /* Set the corresponding bit in the GPIOAFSEL register to enable the alternative functionality on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);  
        /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);
        /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);  
        /* Clear the PMCx bits for this pin */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_PinConfiguration[Pin].pin_num * 4));     
        break;
      case CAN:
      case SSI:
      case UART:
      case I2C:
      case GPT:
      case PWM:
        /* Set the corresponding bit in the GPIOAFSEL register to enable the alternative functionality on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);  
        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);
        /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PinConfiguration[Pin].pin_num);  
        /* Set the corresponding bit in the GPIOPCTL register to select the alternative functionality on this pin */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (Port_PinConfiguration[Pin].pctl_mode << (Port_PinConfiguration[Pin].pin_num * 4));
        break;
    }
  }
}
#endif /* (PORT_SET_PIN_MODE_API == STD_ON) */