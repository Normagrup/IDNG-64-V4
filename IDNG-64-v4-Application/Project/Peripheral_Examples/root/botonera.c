#include "stm32f0xx.h"
#include "config.h"
#include "wdt.h"
#include "daliUtils.h"

#define INC_SENSORES_PRT
	#include "sensores.h"
#undef INC_SENSORES_PRT

unsigned int cnt;

volatile unsigned char botoneraLinkLedBlinkActivo;
volatile unsigned char botoneraLinkLedBlinkCnt;
volatile unsigned char 	botoneraFailLedBlinkActivo;
volatile unsigned char botoneraFailLedBlinkCnt;


unsigned char botoneraFailLedEncendido;


interfacesEventos _eventoInterfaz;



unsigned char auxPressed;


unsigned char _enviando;

unsigned char _botoneraTest;
unsigned char _botoneraTestOn;



void botoneraTestOn (unsigned char period)
{
	_botoneraTest=0;
	_botoneraTestOn=period;
}

void botoneraTestOff (void)
{
	_botoneraTestOn=0;
}





void botoneraLinkLedBlink (void)
{
	botoneraLinkLedBlinkActivo=0x01;
	botoneraLinkLedBlinkCnt=0;	
}

void botoneraFailLedBlink(void)
{
	botoneraFailLedBlinkActivo=0x01;
	botoneraFailLedBlinkCnt=0;	
	
}

void botoneraFailLedEncender(void)
{
	botoneraFailLedEncendido=0x01;
}

void botoneraFailLedApagar(void)
{
	botoneraFailLedEncendido=0x00;
}




void botoneraTick (void)
{
	if (botoneraLinkLedBlinkActivo==0x01)
	{
		if (botoneraLinkLedBlinkCnt<1)
		{
			botoneraLinkLedBlinkCnt++;
		}
		else
		{
			botoneraLinkLedBlinkActivo=0;
		}
	}
	
	if (botoneraFailLedBlinkActivo==0x01)
	{
		if (botoneraFailLedBlinkCnt<5)
		{
			botoneraFailLedBlinkCnt++;
		}
		else
		{
			botoneraFailLedBlinkActivo=0;
		}
	}	
	
	if (_botoneraTest>0)
	{
		_botoneraTest--;
	}
	else
	{
		_botoneraTest=50;
		if ((_botoneraTestOn>0) && (_botoneraTestOn!=0xFF))	_botoneraTestOn--;		
	}
	
}



void botoneraDoTask (void)
{
	
	if (((_botoneraTestOn==0)	&& ((botoneraFailLedEncendido==0x01) || (botoneraFailLedBlinkActivo==0x01))) || ((_botoneraTestOn>0)&& (_botoneraTest>30)))
	{		
		GPIO_SetBits(GPIOC, GPIO_Pin_1); 
	}
	else
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_1); 
	}	
	

	if (((_botoneraTestOn==0) && ((botoneraLinkLedBlinkActivo==0x00) && (botoneraFailLedEncendido==0x00))) || ((_botoneraTestOn>0)&& (_botoneraTest<20)))
	{	
		GPIO_SetBits(GPIOC, GPIO_Pin_2); 
	}
	else
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_2); 
	}
	
	if (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)==0x00)
	{
		
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)==0x00);
		sendKeepAlive();
		
		if (daliUtilsBlinkGet()==0x00)
		{		
			daliUtilsBlinkSend (0xFF,3000);			
		}
		else
		{
			daliUtilsBlinkTerminate();
		}	
	}
	
	if (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)==0x00)
	{
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)==0x00);
		configResetNetworkSettings();
		wdtReboot();
	}
	
}

