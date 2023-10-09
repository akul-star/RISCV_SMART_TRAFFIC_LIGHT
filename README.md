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
void traffic();
void delay_sleep(int);

int main ()
{ 
  while(1)
  {
    traffic();
  }
  return 0;
}


void delay_sleep(int seconds) 
{
    for (int i = 0; i < seconds; i++) 
    {
        for (int j = 0; j < 1000000; j++) 
        {}
    }
}



void traffic()
{
  int laser;
  asm volatile(
  "andi %0, x30, 0x01\n\t"
  : "=r" (laser)
  :
  :);
  
  int red=0, yellow=0, green=0, buzzer=0;
  int red_reg=red*2, yellow_reg=yellow*4, green_reg=green*8, buzzer_reg=buzzer*16;
  
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
     delay_sleep(5);    
  
  
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
     delay_sleep(2);
     
     
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
     delay_sleep(5);    
  
  
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
     delay_sleep(2);    
     
     
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

out:     file format elf32-littleriscv


Disassembly of section .text:

00010074 <main>:
   10074:	ff010113          	add	sp,sp,-16
   10078:	00112623          	sw	ra,12(sp)
   1007c:	00812423          	sw	s0,8(sp)
   10080:	01010413          	add	s0,sp,16
   10084:	070000ef          	jal	100f4 <traffic>
   10088:	ffdff06f          	j	10084 <main+0x10>

0001008c <delay_sleep>:
   1008c:	fd010113          	add	sp,sp,-48
   10090:	02812623          	sw	s0,44(sp)
   10094:	03010413          	add	s0,sp,48
   10098:	fca42e23          	sw	a0,-36(s0)
   1009c:	fe042623          	sw	zero,-20(s0)
   100a0:	0340006f          	j	100d4 <delay_sleep+0x48>
   100a4:	fe042423          	sw	zero,-24(s0)
   100a8:	0100006f          	j	100b8 <delay_sleep+0x2c>
   100ac:	fe842783          	lw	a5,-24(s0)
   100b0:	00178793          	add	a5,a5,1
   100b4:	fef42423          	sw	a5,-24(s0)
   100b8:	fe842703          	lw	a4,-24(s0)
   100bc:	000f47b7          	lui	a5,0xf4
   100c0:	23f78793          	add	a5,a5,575 # f423f <__global_pointer$+0xe2787>
   100c4:	fee7d4e3          	bge	a5,a4,100ac <delay_sleep+0x20>
   100c8:	fec42783          	lw	a5,-20(s0)
   100cc:	00178793          	add	a5,a5,1
   100d0:	fef42623          	sw	a5,-20(s0)
   100d4:	fec42703          	lw	a4,-20(s0)
   100d8:	fdc42783          	lw	a5,-36(s0)
   100dc:	fcf744e3          	blt	a4,a5,100a4 <delay_sleep+0x18>
   100e0:	00000013          	nop
   100e4:	00000013          	nop
   100e8:	02c12403          	lw	s0,44(sp)
   100ec:	03010113          	add	sp,sp,48
   100f0:	00008067          	ret

000100f4 <traffic>:
   100f4:	fc010113          	add	sp,sp,-64
   100f8:	02112e23          	sw	ra,60(sp)
   100fc:	02812c23          	sw	s0,56(sp)
   10100:	04010413          	add	s0,sp,64
   10104:	001f7793          	and	a5,t5,1
   10108:	fef42623          	sw	a5,-20(s0)
   1010c:	fe042423          	sw	zero,-24(s0)
   10110:	fe042223          	sw	zero,-28(s0)
   10114:	fe042023          	sw	zero,-32(s0)
   10118:	fc042e23          	sw	zero,-36(s0)
   1011c:	fe842783          	lw	a5,-24(s0)
   10120:	00179793          	sll	a5,a5,0x1
   10124:	fcf42c23          	sw	a5,-40(s0)
   10128:	fe442783          	lw	a5,-28(s0)
   1012c:	00279793          	sll	a5,a5,0x2
   10130:	fcf42a23          	sw	a5,-44(s0)
   10134:	fe042783          	lw	a5,-32(s0)
   10138:	00379793          	sll	a5,a5,0x3
   1013c:	fcf42823          	sw	a5,-48(s0)
   10140:	fdc42783          	lw	a5,-36(s0)
   10144:	00479793          	sll	a5,a5,0x4
   10148:	fcf42623          	sw	a5,-52(s0)
   1014c:	fd842783          	lw	a5,-40(s0)
   10150:	fd442703          	lw	a4,-44(s0)
   10154:	fd042683          	lw	a3,-48(s0)
   10158:	00ff6f33          	or	t5,t5,a5
   1015c:	00ef6f33          	or	t5,t5,a4
   10160:	00df6f33          	or	t5,t5,a3
   10164:	00100793          	li	a5,1
   10168:	fef42423          	sw	a5,-24(s0)
   1016c:	fe042223          	sw	zero,-28(s0)
   10170:	fe042023          	sw	zero,-32(s0)
   10174:	fec42783          	lw	a5,-20(s0)
   10178:	00078863          	beqz	a5,10188 <traffic+0x94>
   1017c:	00100793          	li	a5,1
   10180:	fcf42e23          	sw	a5,-36(s0)
   10184:	0080006f          	j	1018c <traffic+0x98>
   10188:	fc042e23          	sw	zero,-36(s0)
   1018c:	fd842783          	lw	a5,-40(s0)
   10190:	fd442703          	lw	a4,-44(s0)
   10194:	fd042683          	lw	a3,-48(s0)
   10198:	fcc42603          	lw	a2,-52(s0)
   1019c:	00ff6f33          	or	t5,t5,a5
   101a0:	00ef6f33          	or	t5,t5,a4
   101a4:	00df6f33          	or	t5,t5,a3
   101a8:	00cf6f33          	or	t5,t5,a2
   101ac:	00500513          	li	a0,5
   101b0:	eddff0ef          	jal	1008c <delay_sleep>
   101b4:	00100793          	li	a5,1
   101b8:	fef42423          	sw	a5,-24(s0)
   101bc:	00100793          	li	a5,1
   101c0:	fef42223          	sw	a5,-28(s0)
   101c4:	fe042023          	sw	zero,-32(s0)
   101c8:	fec42783          	lw	a5,-20(s0)
   101cc:	00078863          	beqz	a5,101dc <traffic+0xe8>
   101d0:	00100793          	li	a5,1
   101d4:	fcf42e23          	sw	a5,-36(s0)
   101d8:	0080006f          	j	101e0 <traffic+0xec>
   101dc:	fc042e23          	sw	zero,-36(s0)
   101e0:	fd842783          	lw	a5,-40(s0)
   101e4:	fd442703          	lw	a4,-44(s0)
   101e8:	fd042683          	lw	a3,-48(s0)
   101ec:	fcc42603          	lw	a2,-52(s0)
   101f0:	00ff6f33          	or	t5,t5,a5
   101f4:	00ef6f33          	or	t5,t5,a4
   101f8:	00df6f33          	or	t5,t5,a3
   101fc:	00cf6f33          	or	t5,t5,a2
   10200:	00200513          	li	a0,2
   10204:	e89ff0ef          	jal	1008c <delay_sleep>
   10208:	fe042423          	sw	zero,-24(s0)
   1020c:	fe042223          	sw	zero,-28(s0)
   10210:	00100793          	li	a5,1
   10214:	fef42023          	sw	a5,-32(s0)
   10218:	fec42783          	lw	a5,-20(s0)
   1021c:	00078663          	beqz	a5,10228 <traffic+0x134>
   10220:	fc042e23          	sw	zero,-36(s0)
   10224:	0080006f          	j	1022c <traffic+0x138>
   10228:	fc042e23          	sw	zero,-36(s0)
   1022c:	fd842783          	lw	a5,-40(s0)
   10230:	fd442703          	lw	a4,-44(s0)
   10234:	fd042683          	lw	a3,-48(s0)
   10238:	fcc42603          	lw	a2,-52(s0)
   1023c:	00ff6f33          	or	t5,t5,a5
   10240:	00ef6f33          	or	t5,t5,a4
   10244:	00df6f33          	or	t5,t5,a3
   10248:	00cf6f33          	or	t5,t5,a2
   1024c:	00500513          	li	a0,5
   10250:	e3dff0ef          	jal	1008c <delay_sleep>
   10254:	fe042423          	sw	zero,-24(s0)
   10258:	00100793          	li	a5,1
   1025c:	fef42223          	sw	a5,-28(s0)
   10260:	fe042023          	sw	zero,-32(s0)
   10264:	fec42783          	lw	a5,-20(s0)
   10268:	00078863          	beqz	a5,10278 <traffic+0x184>
   1026c:	00100793          	li	a5,1
   10270:	fcf42e23          	sw	a5,-36(s0)
   10274:	0080006f          	j	1027c <traffic+0x188>
   10278:	fc042e23          	sw	zero,-36(s0)
   1027c:	fd842783          	lw	a5,-40(s0)
   10280:	fd442703          	lw	a4,-44(s0)
   10284:	fd042683          	lw	a3,-48(s0)
   10288:	fcc42603          	lw	a2,-52(s0)
   1028c:	00ff6f33          	or	t5,t5,a5
   10290:	00ef6f33          	or	t5,t5,a4
   10294:	00df6f33          	or	t5,t5,a3
   10298:	00cf6f33          	or	t5,t5,a2
   1029c:	00200513          	li	a0,2
   102a0:	dedff0ef          	jal	1008c <delay_sleep>
   102a4:	00000013          	nop
   102a8:	03c12083          	lw	ra,60(sp)
   102ac:	03812403          	lw	s0,56(sp)
   102b0:	04010113          	add	sp,sp,64
   102b4:	00008067          	ret

```
# Instructions used in the Assembly code:

```
Number of different instructions: 15
List of unique instructions:
sw
ret
sll
li
bge
jal
or
nop
beqz
j
blt
lw
add
and
lui

```
# Acknowledgement

1. Kunal Ghosh, VSD Corp. Pvt. Ltd.
2. Skywater Foundry
3. Chatgpt
4. Shant Rakshit, Colleague, IIITB.
5. Emil Jayanth Lal, Colleague, IIITB.
   
