# RISCV_SMART_TRAFFIC_LIGHT
This repository summarizes the progress made in the ASIC class with the RISC-V Project.

# AIM:
The project is **Smart Traffic Light** which will operate the traffic light's and whenever a vehicle will try to break the traffic light's, a buzzer will turn on and let the authorities know that the traffic lights have been broken. This project will be using a custom RISC-V processor especially taped out for this particular application.

# Working:
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
   10054:	fa010113          	addi	sp,sp,-96
   10058:	04812e23          	sw	s0,92(sp)
   1005c:	06010413          	addi	s0,sp,96
   10060:	fc042623          	sw	zero,-52(s0)
   10064:	fc042423          	sw	zero,-56(s0)
   10068:	fc042223          	sw	zero,-60(s0)
   1006c:	fc042023          	sw	zero,-64(s0)
   10070:	fcc42783          	lw	a5,-52(s0)
   10074:	00179793          	slli	a5,a5,0x1
   10078:	faf42e23          	sw	a5,-68(s0)
   1007c:	fc842783          	lw	a5,-56(s0)
   10080:	00279793          	slli	a5,a5,0x2
   10084:	faf42c23          	sw	a5,-72(s0)
   10088:	fc442783          	lw	a5,-60(s0)
   1008c:	00379793          	slli	a5,a5,0x3
   10090:	faf42a23          	sw	a5,-76(s0)
   10094:	fc042783          	lw	a5,-64(s0)
   10098:	00479793          	slli	a5,a5,0x4
   1009c:	faf42823          	sw	a5,-80(s0)
   100a0:	001f7793          	andi	a5,t5,1
   100a4:	faf42623          	sw	a5,-84(s0)
   100a8:	fbc42783          	lw	a5,-68(s0)
   100ac:	fb842703          	lw	a4,-72(s0)
   100b0:	fb442683          	lw	a3,-76(s0)
   100b4:	00ff6f33          	or	t5,t5,a5
   100b8:	00ef6f33          	or	t5,t5,a4
   100bc:	00df6f33          	or	t5,t5,a3
   100c0:	00100793          	li	a5,1
   100c4:	fcf42623          	sw	a5,-52(s0)
   100c8:	fc042423          	sw	zero,-56(s0)
   100cc:	fc042223          	sw	zero,-60(s0)
   100d0:	fac42783          	lw	a5,-84(s0)
   100d4:	00078863          	beqz	a5,100e4 <main+0x90>
   100d8:	00100793          	li	a5,1
   100dc:	fcf42023          	sw	a5,-64(s0)
   100e0:	0080006f          	j	100e8 <main+0x94>
   100e4:	fc042023          	sw	zero,-64(s0)
   100e8:	fbc42783          	lw	a5,-68(s0)
   100ec:	fb842703          	lw	a4,-72(s0)
   100f0:	fb442683          	lw	a3,-76(s0)
   100f4:	fb042603          	lw	a2,-80(s0)
   100f8:	00ff6f33          	or	t5,t5,a5
   100fc:	00ef6f33          	or	t5,t5,a4
   10100:	00df6f33          	or	t5,t5,a3
   10104:	00cf6f33          	or	t5,t5,a2
   10108:	fe042623          	sw	zero,-20(s0)
   1010c:	0340006f          	j	10140 <main+0xec>
   10110:	fe042423          	sw	zero,-24(s0)
   10114:	0100006f          	j	10124 <main+0xd0>
   10118:	fe842783          	lw	a5,-24(s0)
   1011c:	00178793          	addi	a5,a5,1
   10120:	fef42423          	sw	a5,-24(s0)
   10124:	fe842703          	lw	a4,-24(s0)
   10128:	000f47b7          	lui	a5,0xf4
   1012c:	23f78793          	addi	a5,a5,575 # f423f <__global_pointer$+0xe274b>
   10130:	fee7d4e3          	bge	a5,a4,10118 <main+0xc4>
   10134:	fec42783          	lw	a5,-20(s0)
   10138:	00178793          	addi	a5,a5,1
   1013c:	fef42623          	sw	a5,-20(s0)
   10140:	fec42703          	lw	a4,-20(s0)
   10144:	00400793          	li	a5,4
   10148:	fce7d4e3          	bge	a5,a4,10110 <main+0xbc>
   1014c:	00100793          	li	a5,1
   10150:	fcf42623          	sw	a5,-52(s0)
   10154:	00100793          	li	a5,1
   10158:	fcf42423          	sw	a5,-56(s0)
   1015c:	fc042223          	sw	zero,-60(s0)
   10160:	fac42783          	lw	a5,-84(s0)
   10164:	00078863          	beqz	a5,10174 <main+0x120>
   10168:	00100793          	li	a5,1
   1016c:	fcf42023          	sw	a5,-64(s0)
   10170:	0080006f          	j	10178 <main+0x124>
   10174:	fc042023          	sw	zero,-64(s0)
   10178:	fbc42783          	lw	a5,-68(s0)
   1017c:	fb842703          	lw	a4,-72(s0)
   10180:	fb442683          	lw	a3,-76(s0)
   10184:	fb042603          	lw	a2,-80(s0)
   10188:	00ff6f33          	or	t5,t5,a5
   1018c:	00ef6f33          	or	t5,t5,a4
   10190:	00df6f33          	or	t5,t5,a3
   10194:	00cf6f33          	or	t5,t5,a2
   10198:	fe042223          	sw	zero,-28(s0)
   1019c:	0340006f          	j	101d0 <main+0x17c>
   101a0:	fe042023          	sw	zero,-32(s0)
   101a4:	0100006f          	j	101b4 <main+0x160>
   101a8:	fe042783          	lw	a5,-32(s0)
   101ac:	00178793          	addi	a5,a5,1
   101b0:	fef42023          	sw	a5,-32(s0)
   101b4:	fe042703          	lw	a4,-32(s0)
   101b8:	000f47b7          	lui	a5,0xf4
   101bc:	23f78793          	addi	a5,a5,575 # f423f <__global_pointer$+0xe274b>
   101c0:	fee7d4e3          	bge	a5,a4,101a8 <main+0x154>
   101c4:	fe442783          	lw	a5,-28(s0)
   101c8:	00178793          	addi	a5,a5,1
   101cc:	fef42223          	sw	a5,-28(s0)
   101d0:	fe442703          	lw	a4,-28(s0)
   101d4:	00100793          	li	a5,1
   101d8:	fce7d4e3          	bge	a5,a4,101a0 <main+0x14c>
   101dc:	fc042623          	sw	zero,-52(s0)
   101e0:	fc042423          	sw	zero,-56(s0)
   101e4:	00100793          	li	a5,1
   101e8:	fcf42223          	sw	a5,-60(s0)
   101ec:	fac42783          	lw	a5,-84(s0)
   101f0:	00078663          	beqz	a5,101fc <main+0x1a8>
   101f4:	fc042023          	sw	zero,-64(s0)
   101f8:	0080006f          	j	10200 <main+0x1ac>
   101fc:	fc042023          	sw	zero,-64(s0)
   10200:	fbc42783          	lw	a5,-68(s0)
   10204:	fb842703          	lw	a4,-72(s0)
   10208:	fb442683          	lw	a3,-76(s0)
   1020c:	fb042603          	lw	a2,-80(s0)
   10210:	00ff6f33          	or	t5,t5,a5
   10214:	00ef6f33          	or	t5,t5,a4
   10218:	00df6f33          	or	t5,t5,a3
   1021c:	00cf6f33          	or	t5,t5,a2
   10220:	fc042e23          	sw	zero,-36(s0)
   10224:	0340006f          	j	10258 <main+0x204>
   10228:	fc042c23          	sw	zero,-40(s0)
   1022c:	0100006f          	j	1023c <main+0x1e8>
   10230:	fd842783          	lw	a5,-40(s0)
   10234:	00178793          	addi	a5,a5,1
   10238:	fcf42c23          	sw	a5,-40(s0)
   1023c:	fd842703          	lw	a4,-40(s0)
   10240:	000f47b7          	lui	a5,0xf4
   10244:	23f78793          	addi	a5,a5,575 # f423f <__global_pointer$+0xe274b>
   10248:	fee7d4e3          	bge	a5,a4,10230 <main+0x1dc>
   1024c:	fdc42783          	lw	a5,-36(s0)
   10250:	00178793          	addi	a5,a5,1
   10254:	fcf42e23          	sw	a5,-36(s0)
   10258:	fdc42703          	lw	a4,-36(s0)
   1025c:	00400793          	li	a5,4
   10260:	fce7d4e3          	bge	a5,a4,10228 <main+0x1d4>
   10264:	fc042623          	sw	zero,-52(s0)
   10268:	00100793          	li	a5,1
   1026c:	fcf42423          	sw	a5,-56(s0)
   10270:	fc042223          	sw	zero,-60(s0)
   10274:	fac42783          	lw	a5,-84(s0)
   10278:	00078863          	beqz	a5,10288 <main+0x234>
   1027c:	00100793          	li	a5,1
   10280:	fcf42023          	sw	a5,-64(s0)
   10284:	0080006f          	j	1028c <main+0x238>
   10288:	fc042023          	sw	zero,-64(s0)
   1028c:	fbc42783          	lw	a5,-68(s0)
   10290:	fb842703          	lw	a4,-72(s0)
   10294:	fb442683          	lw	a3,-76(s0)
   10298:	fb042603          	lw	a2,-80(s0)
   1029c:	00ff6f33          	or	t5,t5,a5
   102a0:	00ef6f33          	or	t5,t5,a4
   102a4:	00df6f33          	or	t5,t5,a3
   102a8:	00cf6f33          	or	t5,t5,a2
   102ac:	fc042a23          	sw	zero,-44(s0)
   102b0:	0340006f          	j	102e4 <main+0x290>
   102b4:	fc042823          	sw	zero,-48(s0)
   102b8:	0100006f          	j	102c8 <main+0x274>
   102bc:	fd042783          	lw	a5,-48(s0)
   102c0:	00178793          	addi	a5,a5,1
   102c4:	fcf42823          	sw	a5,-48(s0)
   102c8:	fd042703          	lw	a4,-48(s0)
   102cc:	000f47b7          	lui	a5,0xf4
   102d0:	23f78793          	addi	a5,a5,575 # f423f <__global_pointer$+0xe274b>
   102d4:	fee7d4e3          	bge	a5,a4,102bc <main+0x268>
   102d8:	fd442783          	lw	a5,-44(s0)
   102dc:	00178793          	addi	a5,a5,1
   102e0:	fcf42a23          	sw	a5,-44(s0)
   102e4:	fd442703          	lw	a4,-44(s0)
   102e8:	00100793          	li	a5,1
   102ec:	fce7d4e3          	bge	a5,a4,102b4 <main+0x260>
   102f0:	d71ff06f          	j	10060 <main+0xc>

```
# Instructions used in the Assembly code:

```
Number of different instructions: 11
List of unique instructions:
lui
bge
li
or
beqz
andi
sw
lw
addi
slli
j


```
# Acknowledgement

1. Kunal Ghosh, VSD Corp. Pvt. Ltd.
2. Skywater Foundry
3. Chatgpt
4. Shant Rakshit, Colleague, IIITB.
5. Emil Jayanth Lal, Colleague, IIITB.
   
