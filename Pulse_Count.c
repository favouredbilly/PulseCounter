/*------------------------------------------------------------------*-
Pulse_Count.C (v1.00)
------------------------------------------------------------------
Count pulses from a mechanical switch or similar device.
Responds to falling edge of pulse: |___
-*------------------------------------------------------------------*/
#include "Main.H"
#include "Port.H"
#include "Bargraph.H"
#include "Pulse_Count.H"
#include "lcd.h"
// ------ Private function prototypes ------------------------------


// ------ Public variable definitions -------------------------------
// Set only after falling edge is detected
bit Falling_edge_G;
// ------ Private variable definitions ------------------------------
// The results of successive tests of the pulse signal
// (NOTE: Can't have arrays of bits...)
static bit Test4, Test3, Test2, Test1, Test0;
static tByte Total_G = 0;
static tWord Calls_G = 0;
static unsigned int a =0;
static unsigned int b =0;


// ------ Private constants ----------------------------------------
// Allows changed of logic without hardware changes
#define HI_LEVEL (0)
#define LO_LEVEL (1)
/*------------------------------------------------------------------*-
PULSE_COUNT_Init()
Initialisation function for the switch library.
-*------------------------------------------------------------------*/
void PULSE_COUNT_Init(void)
{
Sw_pin = 1; // Use this pin for input
// The tests (see text)
Test4 = LO_LEVEL;
Test3 = LO_LEVEL;
Test2 = LO_LEVEL;
Test1 = LO_LEVEL;
Test0 = LO_LEVEL;
}



/*------------------------------------------------------------------*-
PULSE_COUNT_Update()
This is the main switch function.
It should be called every 30 ms
(to allow for typical 20ms debounce time).
-*------------------------------------------------------------------*/
void PULSE_COUNT_Update(void)
{
// Clear timer flag
TF2 = 0;
b++;
// Shuffle the test results
Test4 = Test3;
Test3 = Test2;
Test2 = Test1;
Test1 = Test0;
// Get latest test result
Test0 = Sw_pin;
// Required result:
// Test4 == HI_LEVEL
// Test3 == HI_LEVEL
// Test1 == LO_LEVEL
// Test0 == LO_LEVEL
if ((Test4 == HI_LEVEL) && (Test3 == HI_LEVEL) &&
(Test1 == LO_LEVEL) && (Test0 == LO_LEVEL))
{
// Falling edge detected
Falling_edge_G = 1;
monitor = 1;
a++;
lcd_print(2,1,a,3);
Motor_Update();
}
else
{
// Default
Falling_edge_G = 0;
monitor = 0;
}




}
/*------------------------------------------------------------------*-
---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/