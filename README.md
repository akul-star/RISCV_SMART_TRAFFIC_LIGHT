# RISCV_SMART_TRAFFIC_LIGHT
This repository summarizes the progress made in the ASIC class with the RISC-V Project.

# AIM:
The project is **Smart Traffic Light** which will operate the traffic light's and whenever a vehicle will try to break the traffic light's, a buzzer will turn on and let the authorities know that the traffic lights have been broken. This project will be using a custom RISC-V processor especially taped out for this particular application.

# Working:
The program continuously cycles through a traffic light sequence: red, red/yellow, green, yellow. A global variable, laserSensorState, is used to simulate a laser sensor's state (on/off) and is turned off when the light is green. A buzzer is simulated with the buzzerState variable, which is activated when the sensor detects a vehicle running a red or yellow light. LED states and the buzzer are controlled within the setLEDState and controlBuzzer functions. The program prints LED and buzzer states, simulating the behavior of a traffic light system with vehicle violation detection.

# Flowchart
<img width="490" alt="image" src="https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/57cf8a24-52f5-4a19-adc8-553c6bd2d490">

# Testing

- Open a terminal window.
- Navigate to the directory containing the sample.c file.
- Design a function that executes the intended logic you require.
- Compile the code using the GCC compiler and verify the output:


  # C-Code

```
#include <stdio.h>

void traffic();

void sleep(int seconds) {
    int delayFactor = 1000000; // Delay factor for one second (adjust as needed)
    int totalDelay = seconds * delayFactor;
    for (int i = 0; i < totalDelay; i++) {
        // Empty for loop
    }
}

int main ()
{ 
  while(1)
  {
    traffic();
  }
  return 0;
}

void traffic()
{
  int laser;
  asm(
  "andi %0, x30, 0x01\n\t"
  : "=r" (laser));
  
  int red=0, yellow=0, green=0, buzzer=0;
  int red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;
  asm(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"  
    	: "=r" (red_reg), "=r" (yellow_reg), "=r" (green_reg));
  
  red=1, yellow=0, green=0;
  
  if(laser)
     buzzer=1;
  else
     buzzer=0;
      
      
      asm(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	: "=r" (red_reg), "=r" (yellow_reg), "=r" (green_reg), "=r" (buzzer_reg));
     sleep(5);    
  
  
  red=1, yellow=1, green=0;
  
  if(laser)
     buzzer=1;
  else
     buzzer=0;
      
      
      asm(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	: "=r" (red_reg), "=r" (yellow_reg), "=r" (green_reg), "=r" (buzzer_reg));
     sleep(2);
     
     
    red=0, yellow=0, green=1;
  
  if(laser)
     buzzer=0;
  else
     buzzer=0;
      
      
      asm(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	: "=r" (red_reg), "=r" (yellow_reg), "=r" (green_reg), "=r" (buzzer_reg));
     sleep(5);    
  
  
    red=0, yellow=1, green=0;
  
  if(laser)
     buzzer=1;
  else
     buzzer=0;
      
      asm(
    	"or x30, x30, %0\n\t"  
    	"or x30, x30, %1\n\t"  
    	"or x30, x30, %2\n\t"
    	"or x30, x30, %3\n\t"  
    	: "=r" (red_reg), "=r" (yellow_reg), "=r" (green_reg), "=r" (buzzer_reg));
     sleep(2);    
     
     
}
  
```
# Assembly Code Conversion
**Commands to convert C-code to assembly language**
```
home/akul-sinha/riscv32-toolchain/bin/riscv32-unknown-elf-gcc -c -mabi=ilp32 -march=rv32im -ffreestanding -o Traffic1.o Traffic1.c
/home/akul-sinha/riscv32-toolchain/bin/riscv32-unknown-elf-objdump -d Traffic1.o > Traffic1.txt
```
**Assembly Code:**
```
Traffic1.o:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <sleep>:
   0:	fd010113          	add	sp,sp,-48
   4:	02812623          	sw	s0,44(sp)
   8:	03010413          	add	s0,sp,48
   c:	fca42e23          	sw	a0,-36(s0)
  10:	000f47b7          	lui	a5,0xf4
  14:	24078793          	add	a5,a5,576 # f4240 <.L14+0xf4030>
  18:	fef42423          	sw	a5,-24(s0)
  1c:	fdc42703          	lw	a4,-36(s0)
  20:	fe842783          	lw	a5,-24(s0)
  24:	02f707b3          	mul	a5,a4,a5
  28:	fef42223          	sw	a5,-28(s0)
  2c:	fe042623          	sw	zero,-20(s0)
  30:	0100006f          	j	40 <.L2>

00000034 <.L3>:
  34:	fec42783          	lw	a5,-20(s0)
  38:	00178793          	add	a5,a5,1
  3c:	fef42623          	sw	a5,-20(s0)

00000040 <.L2>:
  40:	fec42703          	lw	a4,-20(s0)
  44:	fe442783          	lw	a5,-28(s0)
  48:	fef746e3          	blt	a4,a5,34 <.L3>
  4c:	00000013          	nop
  50:	00000013          	nop
  54:	02c12403          	lw	s0,44(sp)
  58:	03010113          	add	sp,sp,48
  5c:	00008067          	ret

00000060 <main>:
  60:	ff010113          	add	sp,sp,-16
  64:	00112623          	sw	ra,12(sp)
  68:	00812423          	sw	s0,8(sp)
  6c:	01010413          	add	s0,sp,16

00000070 <.L5>:
  70:	00000097          	auipc	ra,0x0
  74:	000080e7          	jalr	ra # 70 <.L5>
  78:	ff9ff06f          	j	70 <.L5>

0000007c <traffic>:
  7c:	fc010113          	add	sp,sp,-64
  80:	02112e23          	sw	ra,60(sp)
  84:	02812c23          	sw	s0,56(sp)
  88:	04010413          	add	s0,sp,64
  8c:	001f7793          	and	a5,t5,1
  90:	fef42623          	sw	a5,-20(s0)
  94:	fe042423          	sw	zero,-24(s0)
  98:	fe042223          	sw	zero,-28(s0)
  9c:	fe042023          	sw	zero,-32(s0)
  a0:	fc042e23          	sw	zero,-36(s0)
  a4:	fe842783          	lw	a5,-24(s0)
  a8:	00179793          	sll	a5,a5,0x1
  ac:	fcf42c23          	sw	a5,-40(s0)
  b0:	fe442783          	lw	a5,-28(s0)
  b4:	00279793          	sll	a5,a5,0x2
  b8:	fcf42a23          	sw	a5,-44(s0)
  bc:	fe042783          	lw	a5,-32(s0)
  c0:	00379793          	sll	a5,a5,0x3
  c4:	fcf42823          	sw	a5,-48(s0)
  c8:	fdc42783          	lw	a5,-36(s0)
  cc:	00479793          	sll	a5,a5,0x4
  d0:	fcf42623          	sw	a5,-52(s0)
  d4:	00df6f33          	or	t5,t5,a3
  d8:	00ef6f33          	or	t5,t5,a4
  dc:	00ff6f33          	or	t5,t5,a5
  e0:	fcd42c23          	sw	a3,-40(s0)
  e4:	fce42a23          	sw	a4,-44(s0)
  e8:	fcf42823          	sw	a5,-48(s0)
  ec:	00100793          	li	a5,1
  f0:	fef42423          	sw	a5,-24(s0)
  f4:	fe042223          	sw	zero,-28(s0)
  f8:	fe042023          	sw	zero,-32(s0)
  fc:	fec42783          	lw	a5,-20(s0)
 100:	00078863          	beqz	a5,110 <.L7>
 104:	00100793          	li	a5,1
 108:	fcf42e23          	sw	a5,-36(s0)
 10c:	0080006f          	j	114 <.L8>

00000110 <.L7>:
 110:	fc042e23          	sw	zero,-36(s0)

00000114 <.L8>:
 114:	00cf6f33          	or	t5,t5,a2
 118:	00df6f33          	or	t5,t5,a3
 11c:	00ef6f33          	or	t5,t5,a4
 120:	00ff6f33          	or	t5,t5,a5
 124:	fcc42c23          	sw	a2,-40(s0)
 128:	fcd42a23          	sw	a3,-44(s0)
 12c:	fce42823          	sw	a4,-48(s0)
 130:	fcf42623          	sw	a5,-52(s0)
 134:	00500513          	li	a0,5
 138:	00000097          	auipc	ra,0x0
 13c:	000080e7          	jalr	ra # 138 <.L8+0x24>
 140:	00100793          	li	a5,1
 144:	fef42423          	sw	a5,-24(s0)
 148:	00100793          	li	a5,1
 14c:	fef42223          	sw	a5,-28(s0)
 150:	fe042023          	sw	zero,-32(s0)
 154:	fec42783          	lw	a5,-20(s0)
 158:	00078863          	beqz	a5,168 <.L9>
 15c:	00100793          	li	a5,1
 160:	fcf42e23          	sw	a5,-36(s0)
 164:	0080006f          	j	16c <.L10>

00000168 <.L9>:
 168:	fc042e23          	sw	zero,-36(s0)

0000016c <.L10>:
 16c:	00cf6f33          	or	t5,t5,a2
 170:	00df6f33          	or	t5,t5,a3
 174:	00ef6f33          	or	t5,t5,a4
 178:	00ff6f33          	or	t5,t5,a5
 17c:	fcc42c23          	sw	a2,-40(s0)
 180:	fcd42a23          	sw	a3,-44(s0)
 184:	fce42823          	sw	a4,-48(s0)
 188:	fcf42623          	sw	a5,-52(s0)
 18c:	00200513          	li	a0,2
 190:	00000097          	auipc	ra,0x0
 194:	000080e7          	jalr	ra # 190 <.L10+0x24>
 198:	fe042423          	sw	zero,-24(s0)
 19c:	fe042223          	sw	zero,-28(s0)
 1a0:	00100793          	li	a5,1
 1a4:	fef42023          	sw	a5,-32(s0)
 1a8:	fec42783          	lw	a5,-20(s0)
 1ac:	00078663          	beqz	a5,1b8 <.L11>
 1b0:	fc042e23          	sw	zero,-36(s0)
 1b4:	0080006f          	j	1bc <.L12>

000001b8 <.L11>:
 1b8:	fc042e23          	sw	zero,-36(s0)

000001bc <.L12>:
 1bc:	00cf6f33          	or	t5,t5,a2
 1c0:	00df6f33          	or	t5,t5,a3
 1c4:	00ef6f33          	or	t5,t5,a4
 1c8:	00ff6f33          	or	t5,t5,a5
 1cc:	fcc42c23          	sw	a2,-40(s0)
 1d0:	fcd42a23          	sw	a3,-44(s0)
 1d4:	fce42823          	sw	a4,-48(s0)
 1d8:	fcf42623          	sw	a5,-52(s0)
 1dc:	00500513          	li	a0,5
 1e0:	00000097          	auipc	ra,0x0
 1e4:	000080e7          	jalr	ra # 1e0 <.L12+0x24>
 1e8:	fe042423          	sw	zero,-24(s0)
 1ec:	00100793          	li	a5,1
 1f0:	fef42223          	sw	a5,-28(s0)
 1f4:	fe042023          	sw	zero,-32(s0)
 1f8:	fec42783          	lw	a5,-20(s0)
 1fc:	00078863          	beqz	a5,20c <.L13>
 200:	00100793          	li	a5,1
 204:	fcf42e23          	sw	a5,-36(s0)
 208:	0080006f          	j	210 <.L14>

0000020c <.L13>:
 20c:	fc042e23          	sw	zero,-36(s0)

00000210 <.L14>:
 210:	00cf6f33          	or	t5,t5,a2
 214:	00df6f33          	or	t5,t5,a3
 218:	00ef6f33          	or	t5,t5,a4
 21c:	00ff6f33          	or	t5,t5,a5
 220:	fcc42c23          	sw	a2,-40(s0)
 224:	fcd42a23          	sw	a3,-44(s0)
 228:	fce42823          	sw	a4,-48(s0)
 22c:	fcf42623          	sw	a5,-52(s0)
 230:	00200513          	li	a0,2
 234:	00000097          	auipc	ra,0x0
 238:	000080e7          	jalr	ra # 234 <.L14+0x24>
 23c:	00000013          	nop
 240:	03c12083          	lw	ra,60(sp)
 244:	03812403          	lw	s0,56(sp)
 248:	04010113          	add	sp,sp,64
 24c:	00008067          	ret

```
# Instructions used in the Assembly code:

```
Number of different instructions: 16
List of unique instructions:
mul
lw
add
ret
nop
sll
beqz
j
or
sw
blt
and
lui
auipc
li
jalr

```
# Acknowledgement

1. Kunal Ghosh, VSD Corp. Pvt. Ltd.
2. Skywater Foundry
3. Chatgpt
4. Shant Rakshit, Colleague, IIITB.
5. Emil Jayanth Lal, Colleague, IIITB.
   
