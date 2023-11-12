int main()
{
while(1)
{

  int laser;
  int red=0, yellow=0, green=0, buzzer=0;
  int red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;
  asm volatile(
  "andi %0, x30, 0x01\n\t"
  : "=r" (laser)
  :
  :);
  
  
  asm volatile(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg)
    	: "x30"
    	);
  
  red=1, yellow=0, green=0;
  
  if(laser)
     buzzer=1;
  else
     buzzer=0;
      
      
      asm volatile(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg)
    	: "x30"
    	);
     //delay_sleep(5);    
     for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 1000000; j++) 
        {}
    } 
  
  red=1, yellow=1, green=0;
  
  if(laser)
     buzzer=1;
  else
     buzzer=0;
      
      
      asm volatile(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg)
    	: "x30"
    	);
     //delay_sleep(2);
     for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 1000000; j++) 
        {}
    }
     
    red=0, yellow=0, green=1;
  
  if(laser)
     buzzer=0;
  else
     buzzer=0;
      
      
      asm volatile(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg)
    	: "x30"
    	);
     //delay_sleep(5);    
     for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 1000000; j++) 
        {}
    }
  
    red=0, yellow=1, green=0;
  
  if(laser)
     buzzer=1;
  else
     buzzer=0;
      
      asm volatile(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"
    	:  
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg)
    	: "x30"
    	);
     //delay_sleep(2);
     for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 1000000; j++) 
        {}
    }    

	
}
return 0;
}
