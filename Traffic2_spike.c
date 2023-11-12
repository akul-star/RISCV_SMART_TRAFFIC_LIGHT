//#include<stdio.h>
//#include<stdlib.h>

int main()
{
while(1)
{

  int laser;
  int red, yellow, green, buzzer;
  int red_reg, yellow_reg, green_reg, buzzer_reg;
   
  red=0, yellow=0, green=0, buzzer=0;
  
  asm volatile(
  "andi %0, x30, 0x01\n\t"
  : "=r" (laser)
  :
  :);
  
  
  int mask = 0xFFFFFFE1; 
   red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;
  
   asm volatile(
        "and x30,x30,%4\n\t"
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg), "r"(mask)
    	: "x30"
    	);
    	
    	
  
   red=1, yellow=0, green=0;
  // printf("RED light ON\n\t");
  
  if(laser==0){
     buzzer=1;
    //  printf("BUZZER N\n\t");
      }
      
  else{
     buzzer=0;
      //printf("BUZZER OFF\n\t");
  }
      
     red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;  
      asm volatile(
        "and x30,x30,%4\n\t"
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg), "r"(mask)
    	: "x30"
    	);
     //delay_sleep(5);    
   // for (int i = 0; i < 5; i++) 
    //{
        for (int j = 0; j < 100; j++) 
        {}
   
    //} 
       
  red=1, yellow=1, green=0;
  //printf("RED & YELLOW ON\n\t");
  
  if(laser==0) {
     buzzer=1;
    // printf("BUZZER ON\n\t");
     }
  else
  {
     buzzer=0;
    // printf("BUZZER OFF\n\t");
      }
   
    red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;
      asm volatile(
        "and x30,x30,%4\n\t"
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg), "r"(mask)
    	: "x30"
    	);
     //delay_sleep(2);
     //for (int i = 0; i < 2; i++) 
    //{
        for (int j = 0; j < 100; j++) 
        
       
    //}
      
      
    red=0, yellow=0, green=1;
    //     printf("GREEN light ON\n\t");
  if(laser==0)
  {
     buzzer=0;
     //     printf("BUZZER is OFF\n\t");
          }
  else
  {
     buzzer=0;
     //     printf("BUZZER is OFF\n\t");
      }
    
     red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;
      asm volatile(
        "and x30,x30,%4\n\t"
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg), "r"(mask)
    	: "x30"
    	);
     //delay_sleep(5);    
//    for (int i = 0; i < 5; i++) 
//   {
        for (int j = 0; j < 100; j++) 
        {}
   //}
    
    
  red=0, yellow=1, green=0;
   //    printf("YELLOW is ON\n\t");
  
  if(laser==0)
  {
     buzzer=1;
   //   printf("BUZZER is ON\n\t"); 
      }
  else
  {
     buzzer=0;
   //   printf("BUZZER is OFF\n\t");
      }
   red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;    
      asm volatile(
        "and x30,x30,%4\n\t"
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r" (buzzer_reg), "r"(mask)
    	: "x30"
    	);
    	
    	
     //delay_sleep(2);
//     for (int i = 0; i < 2; i++) 
//    {
        for (int j = 0; j < 100; j++) 
        {}
       
	
//} 
return 0;
}
}
