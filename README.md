# RISCV_SMART_TRAFFIC_LIGHT
This repository summarizes the progress made in the ASIC class with the RISC-V Project.

# AIM:
The project is **Smart Traffic Light** which will operate the traffic light's and whenever a vehicle will try to break the traffic light's, a buzzer will turn on and let the authorities know that the traffic lights have been broken. This project will be using a custom RISC-V processor especially taped out for this particular application.

# WORKING:
The program continuously cycles through a traffic light sequence: red, red/yellow, green, yellow. A global variable, laserSensorState, is used to simulate a laser sensor's state (on/off) and is turned off when the light is green. A buzzer is simulated with the buzzerState variable, which is activated when the sensor detects a vehicle running a red or yellow light. LED states and the buzzer are controlled within the setLEDState and controlBuzzer functions. The program prints LED and buzzer states, simulating the behavior of a traffic light system with vehicle violation detection.

# BLOCK DIAGRAM:
<img width="490" alt="image" src="https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/57cf8a24-52f5-4a19-adc8-553c6bd2d490">

# Testing

- Open a terminal window.
- Navigate to the directory containing the sample.c file.
- Design a function that executes the intended logic you require.
- Compile the code using the GCC compiler and verify the output:


  # C-Code

```
//#include<stdio.h>
//#include<stdlib.h>

int main()
{
while(1)
{

  int laser;
  int red=0, yellow=0, green=0, buzzer=0;
  int red_reg, yellow_reg, green_reg, buzzer_reg;
   
  
  
  asm volatile(
  "andi %0, x30, 0x01\n\t"
  : "=r" (laser)
  :
  :);
  
  
  int mask = 0xFFFFFFF0; 
   red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;
  
  asm volatile(
        "and x30,x30,%3\n\t"
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"  
    	:
    	: "r" (red_reg), "r" (yellow_reg), "r" (green_reg), "r"(mask)
    	: "x30"
    	);
  
   red=1, yellow=0, green=0;
  // printf("RED light ON\n\t");
  
  if(laser){
     buzzer=1;
    //  printf("BUZZER ON\n\t");
      }
      
  else{
     buzzer=0;
      //printf("BUZZER OFF\n\t");
  }
      
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
//     for (int i = 0; i < 5; i++) 
//    {
//        for (int j = 0; j < 1000000; j++) 
//        {}
   
//    } 
       
  red=1, yellow=1, green=0;
  //printf("RED & YELLOW ON\n\t");
  
  if(laser) {
     buzzer=1;
    // printf("BUZZER ON\n\t");
     }
  else
  {
     buzzer=0;
    // printf("BUZZER OFF\n\t");
      }
      
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
//        for (int j = 0; j < 1000000; j++) 
//        {}
       
//    }
      
      
    red=0, yellow=0, green=1;
    //     printf("GREEN light ON\n\t");
  if(laser)
  {
     buzzer=0;
     //     printf("BUZZER is OFF\n\t");
          }
  else
  {
     buzzer=0;
     //     printf("BUZZER is OFF\n\t");
      }
      
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
//     for (int i = 0; i < 5; i++) 
//    {
//        for (int j = 0; j < 1000000; j++) 
//        {}
//   }
    
    
  red=0, yellow=1, green=0;
   //    printf("YELLOW is ON\n\t");
  
  if(laser)
  {
     buzzer=1;
   //   printf("BUZZER is ON\n\t"); 
      }
  else
  {
     buzzer=0;
   //   printf("BUZZER is OFF\n\t");
      }
      
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
    	
    	int testing;
		asm volatile(
    		"addi %0, x30, 0\n\t"
    		:"=r"(testing)
    		:
    		:"x30"
    		);
    //		printf("outcome = %d\n",testing);
	

     //delay_sleep(2);
  //   for (int i = 0; i < 2; i++) 
  //  {
  //      for (int j = 0; j < 1000000; j++) 
  //      {}
  //  }    
	
//}
return 0;
}
}

```

# Assembly Code Conversion

**Commands to convert C-code to assembly language**

```
riscv64-unknown-elf-gcc -mabi=ilp32 -march=rv32i -ffreestanding -nostdlib -o ./out "file_name.c"
riscv64-unknown-elf-objdump -d -r out > asm.txt
```

**Assembly Code:**

```

out:     file format elf32-littleriscv


Disassembly of section .text:

00010054 <main>:
   10054:	fc010113          	addi	sp,sp,-64
   10058:	02812e23          	sw	s0,60(sp)
   1005c:	04010413          	addi	s0,sp,64
   10060:	fe042623          	sw	zero,-20(s0)
   10064:	fe042423          	sw	zero,-24(s0)
   10068:	fe042223          	sw	zero,-28(s0)
   1006c:	fe042023          	sw	zero,-32(s0)
   10070:	001f7793          	andi	a5,t5,1
   10074:	fcf42e23          	sw	a5,-36(s0)
   10078:	ff000793          	li	a5,-16
   1007c:	fcf42c23          	sw	a5,-40(s0)
   10080:	fec42783          	lw	a5,-20(s0)
   10084:	00179793          	slli	a5,a5,0x1
   10088:	fcf42a23          	sw	a5,-44(s0)
   1008c:	fe842783          	lw	a5,-24(s0)
   10090:	00279793          	slli	a5,a5,0x2
   10094:	fcf42823          	sw	a5,-48(s0)
   10098:	fe442783          	lw	a5,-28(s0)
   1009c:	00379793          	slli	a5,a5,0x3
   100a0:	fcf42623          	sw	a5,-52(s0)
   100a4:	fe042783          	lw	a5,-32(s0)
   100a8:	00479793          	slli	a5,a5,0x4
   100ac:	fcf42423          	sw	a5,-56(s0)
   100b0:	fd442783          	lw	a5,-44(s0)
   100b4:	fd042703          	lw	a4,-48(s0)
   100b8:	fcc42683          	lw	a3,-52(s0)
   100bc:	fd842603          	lw	a2,-40(s0)
   100c0:	00cf7f33          	and	t5,t5,a2
   100c4:	00ff6f33          	or	t5,t5,a5
   100c8:	00ef6f33          	or	t5,t5,a4
   100cc:	00df6f33          	or	t5,t5,a3
   100d0:	00100793          	li	a5,1
   100d4:	fef42623          	sw	a5,-20(s0)
   100d8:	fe042423          	sw	zero,-24(s0)
   100dc:	fe042223          	sw	zero,-28(s0)
   100e0:	fc042e23          	sw	zero,-36(s0)
   100e4:	fdc42783          	lw	a5,-36(s0)
   100e8:	00078863          	beqz	a5,100f8 <main+0xa4>
   100ec:	00100793          	li	a5,1
   100f0:	fef42023          	sw	a5,-32(s0)
   100f4:	0080006f          	j	100fc <main+0xa8>
   100f8:	fe042023          	sw	zero,-32(s0)
   100fc:	fd442783          	lw	a5,-44(s0)
   10100:	fd042703          	lw	a4,-48(s0)
   10104:	fcc42683          	lw	a3,-52(s0)
   10108:	fc842603          	lw	a2,-56(s0)
   1010c:	fd842583          	lw	a1,-40(s0)
   10110:	00bf7f33          	and	t5,t5,a1
   10114:	00ff6f33          	or	t5,t5,a5
   10118:	00ef6f33          	or	t5,t5,a4
   1011c:	00df6f33          	or	t5,t5,a3
   10120:	00cf6f33          	or	t5,t5,a2
   10124:	00100793          	li	a5,1
   10128:	fef42623          	sw	a5,-20(s0)
   1012c:	00100793          	li	a5,1
   10130:	fef42423          	sw	a5,-24(s0)
   10134:	fe042223          	sw	zero,-28(s0)
   10138:	fc042e23          	sw	zero,-36(s0)
   1013c:	fdc42783          	lw	a5,-36(s0)
   10140:	00078863          	beqz	a5,10150 <main+0xfc>
   10144:	00100793          	li	a5,1
   10148:	fef42023          	sw	a5,-32(s0)
   1014c:	0080006f          	j	10154 <main+0x100>
   10150:	fe042023          	sw	zero,-32(s0)
   10154:	fd442783          	lw	a5,-44(s0)
   10158:	fd042703          	lw	a4,-48(s0)
   1015c:	fcc42683          	lw	a3,-52(s0)
   10160:	fc842603          	lw	a2,-56(s0)
   10164:	fd842583          	lw	a1,-40(s0)
   10168:	00bf7f33          	and	t5,t5,a1
   1016c:	00ff6f33          	or	t5,t5,a5
   10170:	00ef6f33          	or	t5,t5,a4
   10174:	00df6f33          	or	t5,t5,a3
   10178:	00cf6f33          	or	t5,t5,a2
   1017c:	fe042623          	sw	zero,-20(s0)
   10180:	fe042423          	sw	zero,-24(s0)
   10184:	00100793          	li	a5,1
   10188:	fef42223          	sw	a5,-28(s0)
   1018c:	fc042e23          	sw	zero,-36(s0)
   10190:	fdc42783          	lw	a5,-36(s0)
   10194:	00078663          	beqz	a5,101a0 <main+0x14c>
   10198:	fe042023          	sw	zero,-32(s0)
   1019c:	0080006f          	j	101a4 <main+0x150>
   101a0:	fe042023          	sw	zero,-32(s0)
   101a4:	fd442783          	lw	a5,-44(s0)
   101a8:	fd042703          	lw	a4,-48(s0)
   101ac:	fcc42683          	lw	a3,-52(s0)
   101b0:	fc842603          	lw	a2,-56(s0)
   101b4:	fd842583          	lw	a1,-40(s0)
   101b8:	00bf7f33          	and	t5,t5,a1
   101bc:	00ff6f33          	or	t5,t5,a5
   101c0:	00ef6f33          	or	t5,t5,a4
   101c4:	00df6f33          	or	t5,t5,a3
   101c8:	00cf6f33          	or	t5,t5,a2
   101cc:	fe042623          	sw	zero,-20(s0)
   101d0:	00100793          	li	a5,1
   101d4:	fef42423          	sw	a5,-24(s0)
   101d8:	fe042223          	sw	zero,-28(s0)
   101dc:	fdc42783          	lw	a5,-36(s0)
   101e0:	00078863          	beqz	a5,101f0 <main+0x19c>
   101e4:	00100793          	li	a5,1
   101e8:	fef42023          	sw	a5,-32(s0)
   101ec:	0080006f          	j	101f4 <main+0x1a0>
   101f0:	fe042023          	sw	zero,-32(s0)
   101f4:	fd442783          	lw	a5,-44(s0)
   101f8:	fd042703          	lw	a4,-48(s0)
   101fc:	fcc42683          	lw	a3,-52(s0)
   10200:	fc842603          	lw	a2,-56(s0)
   10204:	fd842583          	lw	a1,-40(s0)
   10208:	00bf7f33          	and	t5,t5,a1
   1020c:	00ff6f33          	or	t5,t5,a5
   10210:	00ef6f33          	or	t5,t5,a4
   10214:	00df6f33          	or	t5,t5,a3
   10218:	00cf6f33          	or	t5,t5,a2
   1021c:	000f0793          	mv	a5,t5
   10220:	fcf42223          	sw	a5,-60(s0)
   10224:	00000793          	li	a5,0
   10228:	00078513          	mv	a0,a5
   1022c:	03c12403          	lw	s0,60(sp)
   10230:	04010113          	addi	sp,sp,64
   10234:	00008067          	ret



```
# Instructions used in the Assembly code:

```
Number of different instructions: 12
List of unique instructions:
sw
and
j
mv
li
andi
beqz
or
ret
addi
lw
slli

```
# SPIKE Testing
We will be using "Spike" which is a RISC-V simulator. An open-source instruction-set simulator (ISS) for the RISC-V architecture. The C-code will be first using RISC-64 tool chain and then simulated for different scenario's according to the application using SPIKE simulator.

CASE-1
======
- The project is about a smart traffic light system which will ring the buzzer whenever a vehicle will break the traffic light. Case-1 is when the laser(input) will give 1 as input, which means vehicle is breaking the traffic light.

![laser1](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/bfd27dcb-f4b8-44af-9564-7233fa3bbd40)


- When red light is ON and the vehicle breaks the light, the buzzer is getting turned ON.
- When red & yellow light is ON and the vehicle breaks the light, the buzzer is getting turned ON.
- When yellow light is ON and the vehicle breaks the light, the buzzer is getting turned ON.
- When green light is ON the buzzer will be OFF.

CASE-2
======
Case-1 is when the laser(input) will give 1 as input, which means vehicle is breaking the traffic light.

![laser_0](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/ff99bc09-4821-4da8-ac3a-4940df6395da)

- When red light is ON and no the vehicle breaks the light, the buzzer is OFF.
- When red & yellow light is NO and no vehicle breaks the light, the buzzer is OFF.
- When yellow light is ON and NO vehicle breaks the light, the buzzer is OFF.
- When green light is ON the buzzer will be OFF.



# Acknowledgement

1. Kunal Ghosh, VSD Corp. Pvt. Ltd.
2. Skywater Foundry
3. Chatgpt
4. Shant Rakshit, Colleague, IIITB.
5. Emil Jayanth Lal, Colleague, IIITB.
   
