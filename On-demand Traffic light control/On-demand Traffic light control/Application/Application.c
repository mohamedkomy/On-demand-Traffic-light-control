             #include "Application.h"
			uint8_t mode =1;
			uint8_t red=0;
			uint8_t green=0;
			void APP_init(void)
			{
				
				//Car LED initialization
				Led_Init(PORT_A,green_car);
				Led_Init(PORT_A,yellow_car);
				Led_Init(PORT_A,red_car);
				
				//Pedestrian LED initialization
				Led_Init(PORT_B,green_pedestrian);
				Led_Init(PORT_B,yellow_pedestrian);
				Led_Init(PORT_B,red_pedestrian);
				
				//Button initialization
				Button_Init(PORT_D,pin2);
				
				//Timer initialization
				TIMER_init();
				
				//Enable Global interrupts & setup rising edge detection for button
				sei();
				RISING_EDGE_SETUP();
				SETUP_INT0();
			}
			
			
			
			/*Change from normal mode to pedestrian mode when the pedestrian button is pressed.
			If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
			If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
			At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
			After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
			Traffic lights signals are going to the normal mode again.*/
			void APP_start(void)
			{
				
				switch(mode)
				{
					case 1: 
					LED_OFF(PORT_B,red_pedestrian);
					LED_OFF(PORT_B,green_pedestrian);
					LED_OFF(PORT_B,yellow_pedestrian);
					LED_ON(PORT_A,green_car);
					if(mode==0)
					{
						green =1;
						break;
					}
					TIMER_delay(5000);
					if(mode==0)
					{
						green =1;
						break;
					}
					
					
					LED_OFF(PORT_A,green_car);
				if(mode==0)
				{
					green =1;
					break;
				}
					for(uint8_t i=0;i<5;i++)
					{
						LED_ON(PORT_A,yellow_car);
							TIMER_delay(500);
						LED_OFF(PORT_A,yellow_car);
						TIMER_delay(500);
					}
					if(mode==0)
					{
						green =1;
						break;
					}
					
					
				
					LED_ON(PORT_A,red_car);
					if(mode==0)
					{
						red =1;
						break;
					}
					TIMER_delay(5000);
					if(mode==0)
					{
						red =1;
						break;
					}
					LED_OFF(PORT_A,red_car);
					break;
					
					case 0:
					if(red==1)
					{
							LED_ON(PORT_A,red_car);
							LED_ON(PORT_B,green_pedestrian);
							TIMER_delay(5000);
							LED_OFF(PORT_A,red_car);
								for(uint8_t i=0;i<5;i++)
								{
									LED_ON(PORT_A,yellow_car);
									LED_ON(PORT_B,yellow_pedestrian);
									TIMER_delay(500);
									LED_OFF(PORT_A,yellow_car);
									LED_OFF(PORT_B,yellow_pedestrian);
									TIMER_delay(500);
								}
								LED_OFF(PORT_B,green_pedestrian);
								LED_ON(PORT_A,green_car);
								LED_ON(PORT_B,red_pedestrian);
								TIMER_delay(1000);
								mode=1;
								red=0;
							
					}
					else if(green==1)
					{
						LED_ON(PORT_B,red_pedestrian);
						for(uint8_t i=0;i<5;i++)
						{
							LED_ON(PORT_A,yellow_car);
							LED_ON(PORT_B,yellow_pedestrian);
							TIMER_delay(500);
							LED_OFF(PORT_A,yellow_car);
							LED_OFF(PORT_B,yellow_pedestrian);
							TIMER_delay(500);
						}
						LED_OFF(PORT_B,red_pedestrian);
						LED_OFF(PORT_A,green_car);
						LED_ON(PORT_B,green_pedestrian);
						LED_ON(PORT_A,red_car);
						TIMER_delay(5000);
						LED_OFF(PORT_A,red_car);
						for(uint8_t i=0;i<5;i++)
						{
							LED_ON(PORT_A,yellow_car);
							LED_ON(PORT_B,yellow_pedestrian);
							TIMER_delay(500);
							LED_OFF(PORT_A,yellow_car);
							LED_OFF(PORT_B,yellow_pedestrian);
							TIMER_delay(500);
						}
						LED_OFF(PORT_B,green_pedestrian);
						LED_ON(PORT_A,green_car);
						LED_ON(PORT_B,red_pedestrian);
						TIMER_delay(1000);
						mode=1;
						green=0;
					}
				
					break;
					default:
					break;
					
				}
			}
				
			ISR(EXT_INT_0)
			{
				
				mode=0;
			}
			

