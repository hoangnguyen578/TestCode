/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The GLCD application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "systick.h"
#include "GLCD.h"
#include "TouchPanel.h"


/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
int main(void)
{
//	uint8_t i;
	TP_Init(); 
  delay_init();
  LCD_Initializtion();
  TouchPanel_Calibrate();
  LCD_Clear(Green);
  GUI_Text(56,144,"Cong ty GTH",Red,White);
  GUI_Text(52,160,"Test TFT SSD1289",Red,White);
  /* Infinite loop */
  while (1)
  {
			getDisplayPoint(&display, Read_Ads7846(), &matrix ) ;
			TP_DrawPoint(display.x,display.y);
//			for(i=0; i<10; i++)
//			{
//					PutChar( 40, 166, i+48, Blue,White );
//					delay_ms(1000);
//			}
			
			if((display.x>32)&&(display.x<140))
			{
				if((display.y>32)&&(display.y<140))
				{
					GUI_Text(56,144,"OFF",Red,White);
				}
			}
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
