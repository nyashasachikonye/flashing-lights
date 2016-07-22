/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO(R)
**                STMicroelectronics STM32F4xx Standard Peripherals Library
**
**  Distribution: The file is distributed “as is,” without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. Distribution of this file (unmodified or modified) is not
**  permitted. Atollic AB permit registered Atollic TrueSTUDIO(R) users the
**  rights to distribute the assembled, compiled & linked contents of this
**  file as part of an application binary file, provided that it is built
**  using the Atollic TrueSTUDIO(R) toolchain.
**
**
*****************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

/* Private macro */
#define GREENLED LED4
#define BLUELED LED6
/* Private variables */
/* Private function prototypes */
/* Private functions */
void delay_ms(uint32_t milli);

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  /**
  *  IMPORTANT NOTE!
  *  The symbol VECT_TAB_SRAM needs to be defined when building the project
  *  if code has been located to RAM and interrupts are used. 
  *  Otherwise the interrupt table located in flash will be used.
  *  See also the <system_*.c> file and how the SystemInit() function updates 
  *  SCB->VTOR register.  
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /* TODO - Add your application code here */

  /* Initialize LEDs */
  STM_EVAL_LEDInit(BLUELED);

  STM_EVAL_LEDInit(GREENLED);

  /* Initialize PushButton */
  STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);

  /* Turn on LEDs */
  STM_EVAL_LEDOn(BLUELED);

  STM_EVAL_LEDOff(GREENLED);

	int count = 1;
	int time = 1000;

  /* Infinite loop */
  while (1)
  {
	  if(count == 5)
	  {
	  count = 1;
	  }

	  if(STM_EVAL_PBGetState(BUTTON_USER) == 1)
	  {
		  while(STM_EVAL_PBGetState(BUTTON_USER) == 1){}

		  time = 1000/(count*10);

	  }

	  /* toggle Blue LED */
	  STM_EVAL_LEDOff(GREENLED);
	  STM_EVAL_LEDToggle(BLUELED);

	  /* Delay */
	  delay_ms(time);

	  if(STM_EVAL_PBGetState(BUTTON_USER) == 1)
	  	  {
	  		while(STM_EVAL_PBGetState(BUTTON_USER) == 1){}

	  		time = 1000/(count*10);;

	  		 count ++;

	  	  }



	  STM_EVAL_LEDOff(BLUELED);
	  STM_EVAL_LEDToggle(GREENLED);

		/* Delay*/
		delay_ms(time);

  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}


/**
  * @brief  Delay in ms
  * @param  integer amount of milliseconds
  * @retval None
  */
void delay_ms(uint32_t milli)
{
	uint32_t delay = milli * 17612;              // approximate loops per ms at 168 MHz, Debug config
	for(; delay != 0; delay--);
}

