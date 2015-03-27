/*
 * Armanag.c
 *
 * Created: 3/21/2015 2:15:22 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include "/RoboTec/RoboTec/RoboTec/Headers/Armanag.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/main.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/ADC.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/Motors.h"

uint8_t angleFlag = 0;
uint8_t prevState = 0;
float radius = 14;
float omega = 0.0;
uint8_t c=0;

uint8_t CheckSensor()
{
	uint8_t state;
	
	state = (((0x0F & PINB)) | ((0x70 & PINF)) | (0x80 & PIND));
	
 	return state;
}

void ProcessLineState(uint8_t mask)
{
	left_speed = 0;
	right_speed = 0;
	radius = 0; 
	omega = 0;
	
	switch(mask)
	{
		case 0b00000000:
		{
			//forward(speed(0));
			//Do nothing
			switch(angleFlag)
			{
				case ACUTE_ANGLE_LEFT:
				{
					steer(SPEED+50,0);
					angleFlag = PREVIOUS_COMAND;
				}
				break;
				case ACUTE_ANGLE_RIGHT:
				{
					steer(SPEED+50,0);
					angleFlag = PREVIOUS_COMAND;
				}
				break;
				default:
				{
					
				}
			}
			prevState = mask;
		}
		break;
		
		case 0b00011000:
		{
			//Go forward 
			//alfa = 0
			forward(SPEED);

			prevState = mask;
		}
		break;
		
		case 0b00110000:
		{
			//turn left
			//alfa = 4
			
			if(prevState != mask)
			{
				c=10;
			}
			
			if(count == 2000)
			{
				c+=3;
				count=0;
			}
			else
			{
				count++;
			}
			
			right_speed = SPEED + c;
			steer(SPEED, right_speed);
			
			prevState = mask;
		}
		break;
		
		case 0b01100000:
		{
			//turn left
			//alfa = 8
			if(prevState != mask)
			{
				c=30;
			}
			
			if(count == 2500)
			{
				c+=15;
				count=0;
			}
			else
			{
				count++;
			}
			

			right_speed = SPEED + c;
			steer(SPEED, right_speed);
			
			prevState = mask;
		}
		break;
		
		case 0b11000000:
		{
			//turn left
			//alfa = 12
			
			if(prevState != mask)
			{
				c=45;
			}
			
			if(count == 2500)
			{
				c+=20;
				count=0;
			}
			else
			{
				count++;
			}
			
			
			right_speed = SPEED + c;
			steer(SPEED-50, right_speed);
			
			prevState = mask;
		}
		break;
		
		case 0b00001100:
		{
			//turn right
			//alfa = 4
			
			if(prevState != mask)
			{
				c=10;
			}
			
			if(count == 2000)
			{
				c+=3;
				count=0;
			}
			else
			{
				count++;
			}
			

			left_speed = SPEED + c;
			
			steer(left_speed, SPEED);
			
			prevState = mask;
		}
		break;		
		
		case 0b00000110:
		{
			//turn right
			//alfa = 8
			
			if(prevState != mask)
			{
				c=30;
			}
			
			if(count == 2500)
			{
				c+=15;
				count=0;
			}
			else
			{
				count++;
			}
			

			left_speed = SPEED + c;
			
			steer(left_speed, SPEED);
			prevState = mask;
		}
		break;
		
		case 0b00000011:
		{
			//turn right
			//alfa = 12
			if(prevState != mask)
			{
				c=45;
			}
			
			if(count == 2500)
			{
				c+=20;
				count=0;
			}
			else
			{
				count++;
			}
			

			left_speed = SPEED + c;
			
			steer(left_speed, SPEED-50);
			prevState = mask;
				
			prevState = mask;
		}
		break;
		case 0b10000000:
		{
			//turn sharply to the left
			//alfa = 16
			if(prevState != mask)
			{
				c=75;
			}
			
			if(count == 2500)
			{
				c+=25;
				count=0;
			}
			else
			{
				count++;
			}
			

			right_speed = SPEED + c;
			
			steer(SPEED-70, right_speed);
			//steer(left_speed, right_speed);
			prevState = mask;
			prevState = mask;
		}
		break;
		case 0b00000001:
		{
			//turn sharply to the right
			//alfa = 16
			if(prevState != mask)
			{
				c=75;
			}
						
			if(count == 2500)
			{
				c+=25;
				count=0;
			}
			else
			{
				count++;
			}
						

			left_speed = SPEED + c;
						
			steer(left_speed, SPEED-70);
			//steer(left_speed, right_speed);
			prevState = mask;
			
		}
		break;
		case 0b11100000:
		{
			prevState = mask;
		}
		//turn left
		break;
		
		case 0b01110000:
		//turn left
		{
			prevState = mask;
		}
		break;
		
		case 0b00111000:
		//turn left
		{
			prevState = mask;
		}
		break;
		
		case 0b00011100:
		//turn right
		{
			prevState = mask;
		}
		break;
		
		case 0b00001110:
		//turn right
		{
			prevState = mask;
		}
		break;
		
		case 0b00000111:
		//turn right
		{
			angleFlag = ACUTE_ANGLE_RIGHT;
			prevState = mask;
		}
		break;
		
		case 0b10011000:
		//acute angle turn towards left
		{
		
			angleFlag = ACUTE_ANGLE_LEFT;
			prevState = mask;
		}
		break;
		
		case 0b00011001:
		//acute angle turn towards right
		{
			angleFlag = ACUTE_ANGLE_RIGHT;
			prevState = mask;
		}
		break;
		case 0b11110000:
		//90 degree turn towards left
		{
			left_speed = 0;
			steer(left_speed, SPEED/2);
			prevState = mask;
		}
		break;
		
		case 0b00001111:
		//90 degree turn towards right
		{
			right_speed = 0;
			steer(SPEED/2, right_speed);
			prevState = mask;
		}
		break;
		
		case 0b11001100:
		// acute angle turn towards left
		{
			prevState = mask;
		}
		break;
		
		case 0b11011000 :
		// acute angle turn towards left
		{
			angleFlag = ACUTE_ANGLE_LEFT;
			prevState = mask;
		}
		break;
		
		case 0b00110011:
		// acute angle turn towards right
		{
			angleFlag = ACUTE_ANGLE_RIGHT;
			prevState = mask;
		}
		break;
		
		case 0b00011011:
		// acute angle turn towards right
		{
			angleFlag = ACUTE_ANGLE_RIGHT;
			prevState = mask;
		}
		break;
		
		case 0b11111000:
		//90 degree turn towards left
		{
			left_speed = 0;
			steer(left_speed, SPEED/2);
			prevState = mask;
		}
		break;
		
		case 0b00011111:
		//90 degree turn towards right
		{
			right_speed = 0;
			steer(SPEED/2, right_speed);
			prevState = mask;
		}
		break;
		
		case 0b11011100:
		//acute angle turn towards left
		{
			angleFlag = ACUTE_ANGLE_LEFT;
			prevState = mask;
		}
		break;
		
		case 0b00111011:
		//acute angle turn towards right
		{
			angleFlag = ACUTE_ANGLE_RIGHT;
			prevState = mask;
		}
		break;
		
		case 0b11111100:
		//90 degree turn towards left
		{
			left_speed = 0;
			steer(left_speed, SPEED/2);
			prevState = mask;
		}
		break;
		
		case 0b00111111:
		//90 degree turn towards right
		{
			left_speed = 0;
			steer(left_speed, SPEED/2);
			prevState = mask;
		}
		break;
		
		case 0b11111110:
		//turn to left
		{
			right_speed = 0;
			steer(SPEED/2, right_speed);
			prevState = mask;
		}
		break;
		
		case 0b01111111:
		//turn to right
		{
			left_speed = 0;
			steer(left_speed, SPEED/2);
			prevState = mask;
		}
		break;
		
		case 0b11111111:
		//do nothing
		{
			forward(SPEED);
			prevState = mask;
		}
		break;
		
		
		default:
		{
			
		}
	}
}

uint8_t getRatio(float omega, float r)
{
	uint8_t ratio = 1;
	
	ratio = (uint8_t)((omega*(r + 7.5)) / (omega*(r-7,5)));
	
	return ratio;
}

float getOmega(uint8_t angle)
{
	float omega = 1;
	omega = angle*17,44;
	return omega;
}
