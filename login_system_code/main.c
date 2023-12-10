/*
 * main.c

 *
 *  Created on: Dec 9, 2023
 *      Author: hp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include<util/delay.h>

 u8 reading=0;
u8 flag=0;

void Stepper_Motor(void);
void DC_Motor(void);


void main(void)
{

CLCD_voidInit();
KPD_voidInit();

DIO_voidSetPortDirection(DIO_PORTD,PORT_DIR_OUTPUT);

CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_4);
CLCD_voidSendString("Welcome");
CLCD_voidSetPosition(CLCD_ROW_2,(CLCD_COL_1));
CLCD_voidSendString("To our system");
_delay_ms(2000);
CLCD_voidClearScreen();

while(1)
{
	CLCD_voidSendString("press 1 for DC");
	CLCD_voidSetPosition(CLCD_ROW_2,(CLCD_COL_1)-1);
	CLCD_voidSendString("press 2 for step");


	reading=KPD_u8GetPressed();

	switch(reading)
	{
	case 1:
		flag=1;

       DC_Motor();
		break;

	case 2:
		flag=1;
       Stepper_Motor();
		break;


	}

}

}


void DC_Motor(void)
{


	while(flag==1)
	{
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_VAL_LOW);
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_VAL_LOW);
		reading=0;
		CLCD_voidClearScreen();
		CLCD_voidSendString("Welcom to DC");
		_delay_ms(2000);
		CLCD_voidClearScreen();
		CLCD_voidSendString("Press 1 for CW");
		CLCD_voidSetPosition(CLCD_ROW_2,(CLCD_COL_1)-1);
		CLCD_voidSendString("Press 2 for ACW");
		_delay_ms(1000);
		CLCD_voidClearScreen();
		CLCD_voidSendString("Press 3 for back");
				_delay_ms(1000);
		CLCD_voidClearScreen();

		do{
			reading=KPD_u8GetPressed();

			switch(reading)
			{

			case 1:
				CLCD_voidSendString("Rotate CW");
				CLCD_voidSetPosition(CLCD_ROW_2,(CLCD_COL_1)-1);
				CLCD_voidSendString("Press c to back");

				while(reading!='&')
				{
					reading=KPD_u8GetPressed();
					if(reading=='&')break;
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_VAL_HIGH);
					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_VAL_LOW);

				}
				flag=1;
				break;


			case 2:
							CLCD_voidSendString("Rotate ACW");
							CLCD_voidSetPosition(CLCD_ROW_2,(CLCD_COL_1)-1);
							CLCD_voidSendString("Press c to back");

							while(reading!='&')
							{
								reading=KPD_u8GetPressed();
								if(reading=='&')break;
								DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_VAL_LOW);
								DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_VAL_HIGH);

							}
							flag=1;
							break;

			case 3:
				CLCD_voidClearScreen();
				flag=0;
				break;



			}


		}while(reading=='\0');


	}


}









void Stepper_Motor(void)
{
	while(flag==1)
	{
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_LOW);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_LOW);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_LOW);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_LOW);

	reading=0;
			CLCD_voidClearScreen();
			CLCD_voidSendString("Welcom to Step");
			_delay_ms(2000);
			CLCD_voidClearScreen();
			CLCD_voidSendString("Press 1 for CW");
			CLCD_voidSetPosition(CLCD_ROW_2,(CLCD_COL_1)-1);
			CLCD_voidSendString("Press 2 for ACW");
			_delay_ms(1000);
			CLCD_voidClearScreen();
			CLCD_voidSendString("Press 3 for back");
					_delay_ms(1000);
			CLCD_voidClearScreen();

			do{

				reading=KPD_u8GetPressed();

				switch(reading)
				{
				case 1:
					CLCD_voidSendString("Rotate CW");
					CLCD_voidSetPosition(CLCD_ROW_2,(CLCD_COL_1)-1);
					CLCD_voidSendString("Press c to back");

					while(reading!='&')
					{
						reading=KPD_u8GetPressed();
						if(reading=='&')break;

							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_LOW);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_HIGH);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_HIGH);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_LOW);
							_delay_ms(10);

							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_HIGH);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_HIGH);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_LOW);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_LOW);
							_delay_ms(10);

							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_HIGH);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_LOW);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_LOW);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_HIGH);
							_delay_ms(10);

							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_LOW);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_LOW);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_HIGH);
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_HIGH);
							_delay_ms(10);

				}
						 flag=1;
						 break;

				case 2:

					CLCD_voidSendString("Rotate ACW");
					CLCD_voidSetPosition(CLCD_ROW_2,(CLCD_COL_1)-1);
					CLCD_voidSendString("Press c to back");

					while(reading!='&')
					{
						reading=KPD_u8GetPressed();
								if(reading=='&')break;

									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_LOW);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_HIGH);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_HIGH);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_LOW);
									_delay_ms(10);

									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_LOW);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_LOW);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_HIGH);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_HIGH);
									_delay_ms(10);

									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_HIGH);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_LOW);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_LOW);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_HIGH);
									_delay_ms(10);



									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,PIN_VAL_HIGH);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,PIN_VAL_HIGH);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,PIN_VAL_LOW);
									DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,PIN_VAL_LOW);
									_delay_ms(10);

					}
								 flag=1;
								 break;

				case 3:
								CLCD_voidClearScreen();
								flag=0;
								break;

					}


			}while(reading=='\0');

	}
}
