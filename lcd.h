/*------------------------------------------------------------------*-
lcd.h (v1.00)
------------------------------------------------------------------
- lcd header file
-*------------------------------------------------------------------*/
#include "Main.h"

// ------ Public function prototypes -------------------------------

void delay(unsigned int count);
void lcd_data(unsigned char abc);
void lcd_cmd(unsigned char abc);
void lcd_init();
void lcd_clear();
void lcd_cursor(char row, char column)	;
void lcd_out(char row1, char column1,char *str);
void lcd_print(char row2, char coloumn2, unsigned int value,  int digits);



/*------------------------------------------------------------------*-
---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/