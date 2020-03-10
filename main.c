/*------------------------------------------------------------------*-
Main.c (v1.00)
------------------------------------------------------------------
Milk pasteurization example.
-*------------------------------------------------------------------*/
#include "Main.H"
//#include "Port.H"
#include "Simple_EOS.H"
#include "Motor.H"
#include "Pulse_Count.H"
#include "lcd.h"
/* --------------------------------------------------------------- */
void main(void)
{

PULSE_COUNT_Init();
lcd_init();

	
Motor_Init();
// Set up simple EOS (30ms tick interval)
sEOS_Init_Timer2(30);
while(1) // Super Loop
{
// Enter idle mode to save power

sEOS_Go_To_Sleep();
}
}
/*------------------------------------------------------------------*-
---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/