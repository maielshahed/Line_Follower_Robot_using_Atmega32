/*
 * line_follower_robot.c
 *
 * Created: 8/6/2024 11:24:56 PM
 *  Author: Mai El Shahed
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#include "Dio.h"
#include "direction_speed.h"
volatile int ir_sensor_right;
volatile   int ir_sensor_left;
int main(void)
{
	motor_vinti();
	PWM_init();
	
	
	//input
	DIO_vsetpindir('D',0,0);//ir_sensor_right
	DIO_vsetpindir('D',1,0);//ir_sensor_left
	
    while(1)
    {
        //TODO:: Please write your application code 
		
		ir_sensor_right=DIO_uread('D',0);
		 ir_sensor_left=DIO_uread('D',1);
	

		////if Right Sensor and Left Sensor are at block color then it will call forword function
		
		if (ir_sensor_right==1 && ir_sensor_left==1){
			motor_forword(70);
		}
		
		
		
		//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
		
		if (ir_sensor_right==0 && ir_sensor_left==1){
			turn_left_slow(120);
			
		}
		//if Right Sensor is black and Left Sensor is white then it will call turn Left function
		if (ir_sensor_right==1 && ir_sensor_left==0){
			turn_right_slow(120);
			
			
		}
		
		//if Right Sensor and Left Sensor are at white color then it will call Stop function
		if (ir_sensor_right==0 && ir_sensor_left==0)
		{
			stop_motor();
		}
			
	
		
	
	
    }
}