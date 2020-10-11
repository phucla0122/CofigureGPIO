# include "msp.h"
# include "stdbool.h"
int main(void){
	bool p1_2 = true;
	// Stop watch dog timer
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
	//GPIO function for p1.1 , p1.4
	P1->SEL0 &= (uint8_t)(~0x13);
	P1->SEL1 &= (uint8_t)(~0x13);
	P2->SEL0 &= (uint8_t)(~0x07);
	P2->SEL1 &= (uint8_t)(~0x07);
	//Set Input direction
	P1->DIR &= (uint8_t)(~0x12);
	//Set Output direction
	P1->DIR |= (uint8_t)(0x01);
	P2 ->DIR |= (uint8_t) (0x07);
	//Set REN  
	P1->REN |= (uint8_t)(0x12);
	//Set Output
	P1->OUT |= (uint8_t)(0x13);
	P2->OUT |= (uint8_t)(0x07);
	// Initialize  LEDs states
	P1->OUT &= (uint8_t)(~(0x01));
	P2->OUT &= (uint8_t)(~(0x07));
	// Create while loop
	while(1){
		uint8_t i = 100;
		while((P1->IN & 0x02) && (P1->IN & 0x10)){}
		while(i>0){i--;}
		if((P1->IN & 0x10) && (P1->IN & 0x02)){
			continue;
		}
		else{
			bool buttonOne = !(P1->IN & (uint8_t)0x2); 
			uint8_t checkrelease = 0x12;
			while(P1->IN & checkrelease != checkrelease) {
            // Do nothing until released
       }
			//implement 6.1 and 6.2
			if(buttonOne){		
				if(p1_2){
					P1->OUT ^= (uint8_t)(0x01);
				}else{
					if((P2->OUT & 0x01) && (!(P2->OUT & 0x06))){	
						P2->OUT &= (uint8_t)(~0x07);
						P2->OUT |= (uint8_t)(0x02);
					}else if((P2->OUT & 0x02) && (!(P2->OUT & 0x05))){
						P2->OUT &= (uint8_t)(~0x07);
						P2->OUT |= (uint8_t)(0x03);
					}else if((P2->OUT & 0x03) && (!(P2->OUT & 0x04))){
						P2->OUT &= (uint8_t)(~0x07);
						P2->OUT |= (uint8_t)(0x04);
					}else if((P2->OUT & 0x04) && (!(P2->OUT & 0x03))){
						P2->OUT &= (uint8_t)(~0x07);
						P2->OUT |= (uint8_t)(0x05);
					}else if((P2->OUT & 0x05) && (!(P2->OUT & 0x02))){
						P2->OUT &= (uint8_t)(~0x07);
						P2->OUT |= (uint8_t)(0x06);
					}else if((P2->OUT & 0x06) && (!(P2->OUT & 0x01))){
						P2->OUT &= (uint8_t)(~0x07);
						P2->OUT |= (uint8_t)(0x07);
					}else if(P2->OUT & 0x07){
						P2->OUT &= (uint8_t)(~0x07);
					}else{
						P2->OUT &= (uint8_t)(~0x07);
						P2->OUT |= (uint8_t)(0x01);
					}					
				}		
			}else{
				p1_2 = !p1_2;
			}
		}
	}
}
		
		
		
		
		
		
			