# RISCV_SMART_TRAFFIC_LIGHT
This repository summarizes the progress made in the ASIC class with the RISC-V Project.

# AIM:
The project is **Smart Traffic Light** which will operate the traffic light's and whenever a vehicle will try to break the traffic light's, a buzzer will turn on and let the authorities know that the traffic lights have been broken. This project will be using a custom RISC-V processor especially taped out for this particular application.

# WORKING:
The program continuously cycles through a traffic light sequence: red, red/yellow, green, yellow. A global variable, laserSensorState, is used to simulate a laser sensor's state (on/off) and is turned off when the light is green. A buzzer is simulated with the buzzerState variable, which is activated when the sensor detects a vehicle running a red or yellow light. LED states and the buzzer are controlled within the setLEDState and controlBuzzer functions. The program prints LED and buzzer states, simulating the behavior of a traffic light system with vehicle violation detection.

# BLOCK DIAGRAM:
<img width="490" alt="image" src="https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/57cf8a24-52f5-4a19-adc8-553c6bd2d490">

# Truth Table:

| RED LED (I/P) | YELLOW LED (I/P) | GREEN LED (I/P) | BUZZER (I/P) | LASER (O/P) |
| --------------|----------------- | --------------- | ------------ | ----------  |
|       0       |        0         |        0        |      0       |      1      |
|       1       |        0         |        0        |      0       |      1      |
|       1       |        0         |        0        |      1       |      0      |
|       1       |        1         |        0        |      0       |      1      |
|       1       |        1         |        0        |      1       |      0      |
|       0       |        0         |        1        |      X       |      1      |

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
   10054:	fb010113          	addi	sp,sp,-80
   10058:	04812623          	sw	s0,76(sp)
   1005c:	05010413          	addi	s0,sp,80
   10060:	fe042623          	sw	zero,-20(s0)
   10064:	fe042423          	sw	zero,-24(s0)
   10068:	fe042223          	sw	zero,-28(s0)
   1006c:	fe042023          	sw	zero,-32(s0)
   10070:	001f7793          	andi	a5,t5,1
   10074:	fcf42623          	sw	a5,-52(s0)
   10078:	fe100793          	li	a5,-31
   1007c:	fcf42423          	sw	a5,-56(s0)
   10080:	fec42783          	lw	a5,-20(s0)
   10084:	00179793          	slli	a5,a5,0x1
   10088:	fcf42223          	sw	a5,-60(s0)
   1008c:	fe842783          	lw	a5,-24(s0)
   10090:	00279793          	slli	a5,a5,0x2
   10094:	fcf42023          	sw	a5,-64(s0)
   10098:	fe442783          	lw	a5,-28(s0)
   1009c:	00379793          	slli	a5,a5,0x3
   100a0:	faf42e23          	sw	a5,-68(s0)
   100a4:	fe042783          	lw	a5,-32(s0)
   100a8:	00479793          	slli	a5,a5,0x4
   100ac:	faf42c23          	sw	a5,-72(s0)
   100b0:	fc442783          	lw	a5,-60(s0)
   100b4:	fc042703          	lw	a4,-64(s0)
   100b8:	fbc42683          	lw	a3,-68(s0)
   100bc:	fb842603          	lw	a2,-72(s0)
   100c0:	fc842583          	lw	a1,-56(s0)
   100c4:	00bf7f33          	and	t5,t5,a1
   100c8:	00ff6f33          	or	t5,t5,a5
   100cc:	00ef6f33          	or	t5,t5,a4
   100d0:	00df6f33          	or	t5,t5,a3
   100d4:	00cf6f33          	or	t5,t5,a2
   100d8:	00100793          	li	a5,1
   100dc:	fef42623          	sw	a5,-20(s0)
   100e0:	fe042423          	sw	zero,-24(s0)
   100e4:	fe042223          	sw	zero,-28(s0)
   100e8:	fcc42783          	lw	a5,-52(s0)
   100ec:	00079863          	bnez	a5,100fc <main+0xa8>
   100f0:	00100793          	li	a5,1
   100f4:	fef42023          	sw	a5,-32(s0)
   100f8:	0080006f          	j	10100 <main+0xac>
   100fc:	fe042023          	sw	zero,-32(s0)
   10100:	fec42783          	lw	a5,-20(s0)
   10104:	00179793          	slli	a5,a5,0x1
   10108:	fcf42223          	sw	a5,-60(s0)
   1010c:	fe842783          	lw	a5,-24(s0)
   10110:	00279793          	slli	a5,a5,0x2
   10114:	fcf42023          	sw	a5,-64(s0)
   10118:	fe442783          	lw	a5,-28(s0)
   1011c:	00379793          	slli	a5,a5,0x3
   10120:	faf42e23          	sw	a5,-68(s0)
   10124:	fe042783          	lw	a5,-32(s0)
   10128:	00479793          	slli	a5,a5,0x4
   1012c:	faf42c23          	sw	a5,-72(s0)
   10130:	fc442783          	lw	a5,-60(s0)
   10134:	fc042703          	lw	a4,-64(s0)
   10138:	fbc42683          	lw	a3,-68(s0)
   1013c:	fb842603          	lw	a2,-72(s0)
   10140:	fc842583          	lw	a1,-56(s0)
   10144:	00bf7f33          	and	t5,t5,a1
   10148:	00ff6f33          	or	t5,t5,a5
   1014c:	00ef6f33          	or	t5,t5,a4
   10150:	00df6f33          	or	t5,t5,a3
   10154:	00cf6f33          	or	t5,t5,a2
   10158:	fc042e23          	sw	zero,-36(s0)
   1015c:	0100006f          	j	1016c <main+0x118>
   10160:	fdc42783          	lw	a5,-36(s0)
   10164:	00178793          	addi	a5,a5,1
   10168:	fcf42e23          	sw	a5,-36(s0)
   1016c:	fdc42703          	lw	a4,-36(s0)
   10170:	06300793          	li	a5,99
   10174:	fee7d6e3          	bge	a5,a4,10160 <main+0x10c>
   10178:	00100793          	li	a5,1
   1017c:	fef42623          	sw	a5,-20(s0)
   10180:	00100793          	li	a5,1
   10184:	fef42423          	sw	a5,-24(s0)
   10188:	fe042223          	sw	zero,-28(s0)
   1018c:	fcc42783          	lw	a5,-52(s0)
   10190:	00079863          	bnez	a5,101a0 <main+0x14c>
   10194:	00100793          	li	a5,1
   10198:	fef42023          	sw	a5,-32(s0)
   1019c:	0080006f          	j	101a4 <main+0x150>
   101a0:	fe042023          	sw	zero,-32(s0)
   101a4:	fec42783          	lw	a5,-20(s0)
   101a8:	00179793          	slli	a5,a5,0x1
   101ac:	fcf42223          	sw	a5,-60(s0)
   101b0:	fe842783          	lw	a5,-24(s0)
   101b4:	00279793          	slli	a5,a5,0x2
   101b8:	fcf42023          	sw	a5,-64(s0)
   101bc:	fe442783          	lw	a5,-28(s0)
   101c0:	00379793          	slli	a5,a5,0x3
   101c4:	faf42e23          	sw	a5,-68(s0)
   101c8:	fe042783          	lw	a5,-32(s0)
   101cc:	00479793          	slli	a5,a5,0x4
   101d0:	faf42c23          	sw	a5,-72(s0)
   101d4:	fc442783          	lw	a5,-60(s0)
   101d8:	fc042703          	lw	a4,-64(s0)
   101dc:	fbc42683          	lw	a3,-68(s0)
   101e0:	fb842603          	lw	a2,-72(s0)
   101e4:	fc842583          	lw	a1,-56(s0)
   101e8:	00bf7f33          	and	t5,t5,a1
   101ec:	00ff6f33          	or	t5,t5,a5
   101f0:	00ef6f33          	or	t5,t5,a4
   101f4:	00df6f33          	or	t5,t5,a3
   101f8:	00cf6f33          	or	t5,t5,a2
   101fc:	fc042c23          	sw	zero,-40(s0)
   10200:	0200006f          	j	10220 <main+0x1cc>
   10204:	fe042623          	sw	zero,-20(s0)
   10208:	fe042423          	sw	zero,-24(s0)
   1020c:	00100793          	li	a5,1
   10210:	fef42223          	sw	a5,-28(s0)
   10214:	fd842783          	lw	a5,-40(s0)
   10218:	00178793          	addi	a5,a5,1
   1021c:	fcf42c23          	sw	a5,-40(s0)
   10220:	fd842703          	lw	a4,-40(s0)
   10224:	06300793          	li	a5,99
   10228:	fce7dee3          	bge	a5,a4,10204 <main+0x1b0>
   1022c:	fcc42783          	lw	a5,-52(s0)
   10230:	00079663          	bnez	a5,1023c <main+0x1e8>
   10234:	fe042023          	sw	zero,-32(s0)
   10238:	0080006f          	j	10240 <main+0x1ec>
   1023c:	fe042023          	sw	zero,-32(s0)
   10240:	fec42783          	lw	a5,-20(s0)
   10244:	00179793          	slli	a5,a5,0x1
   10248:	fcf42223          	sw	a5,-60(s0)
   1024c:	fe842783          	lw	a5,-24(s0)
   10250:	00279793          	slli	a5,a5,0x2
   10254:	fcf42023          	sw	a5,-64(s0)
   10258:	fe442783          	lw	a5,-28(s0)
   1025c:	00379793          	slli	a5,a5,0x3
   10260:	faf42e23          	sw	a5,-68(s0)
   10264:	fe042783          	lw	a5,-32(s0)
   10268:	00479793          	slli	a5,a5,0x4
   1026c:	faf42c23          	sw	a5,-72(s0)
   10270:	fc442783          	lw	a5,-60(s0)
   10274:	fc042703          	lw	a4,-64(s0)
   10278:	fbc42683          	lw	a3,-68(s0)
   1027c:	fb842603          	lw	a2,-72(s0)
   10280:	fc842583          	lw	a1,-56(s0)
   10284:	00bf7f33          	and	t5,t5,a1
   10288:	00ff6f33          	or	t5,t5,a5
   1028c:	00ef6f33          	or	t5,t5,a4
   10290:	00df6f33          	or	t5,t5,a3
   10294:	00cf6f33          	or	t5,t5,a2
   10298:	fc042a23          	sw	zero,-44(s0)
   1029c:	0100006f          	j	102ac <main+0x258>
   102a0:	fd442783          	lw	a5,-44(s0)
   102a4:	00178793          	addi	a5,a5,1
   102a8:	fcf42a23          	sw	a5,-44(s0)
   102ac:	fd442703          	lw	a4,-44(s0)
   102b0:	06300793          	li	a5,99
   102b4:	fee7d6e3          	bge	a5,a4,102a0 <main+0x24c>
   102b8:	fe042623          	sw	zero,-20(s0)
   102bc:	00100793          	li	a5,1
   102c0:	fef42423          	sw	a5,-24(s0)
   102c4:	fe042223          	sw	zero,-28(s0)
   102c8:	fcc42783          	lw	a5,-52(s0)
   102cc:	00079863          	bnez	a5,102dc <main+0x288>
   102d0:	00100793          	li	a5,1
   102d4:	fef42023          	sw	a5,-32(s0)
   102d8:	0080006f          	j	102e0 <main+0x28c>
   102dc:	fe042023          	sw	zero,-32(s0)
   102e0:	fec42783          	lw	a5,-20(s0)
   102e4:	00179793          	slli	a5,a5,0x1
   102e8:	fcf42223          	sw	a5,-60(s0)
   102ec:	fe842783          	lw	a5,-24(s0)
   102f0:	00279793          	slli	a5,a5,0x2
   102f4:	fcf42023          	sw	a5,-64(s0)
   102f8:	fe442783          	lw	a5,-28(s0)
   102fc:	00379793          	slli	a5,a5,0x3
   10300:	faf42e23          	sw	a5,-68(s0)
   10304:	fe042783          	lw	a5,-32(s0)
   10308:	00479793          	slli	a5,a5,0x4
   1030c:	faf42c23          	sw	a5,-72(s0)
   10310:	fc442783          	lw	a5,-60(s0)
   10314:	fc042703          	lw	a4,-64(s0)
   10318:	fbc42683          	lw	a3,-68(s0)
   1031c:	fb842603          	lw	a2,-72(s0)
   10320:	fc842583          	lw	a1,-56(s0)
   10324:	00bf7f33          	and	t5,t5,a1
   10328:	00ff6f33          	or	t5,t5,a5
   1032c:	00ef6f33          	or	t5,t5,a4
   10330:	00df6f33          	or	t5,t5,a3
   10334:	00cf6f33          	or	t5,t5,a2
   10338:	fc042823          	sw	zero,-48(s0)
   1033c:	0100006f          	j	1034c <main+0x2f8>
   10340:	fd042783          	lw	a5,-48(s0)
   10344:	00178793          	addi	a5,a5,1
   10348:	fcf42823          	sw	a5,-48(s0)
   1034c:	fd042703          	lw	a4,-48(s0)
   10350:	06300793          	li	a5,99
   10354:	fee7d6e3          	bge	a5,a4,10340 <main+0x2ec>
   10358:	00000793          	li	a5,0
   1035c:	00078513          	mv	a0,a5
   10360:	04c12403          	lw	s0,76(sp)
   10364:	05010113          	addi	sp,sp,80
   10368:	00008067          	ret

```
# Instructions used in the Assembly code:

```
instuction_counter.py
Number of different instructions: 13
List of unique instructions:
bnez
sw
ret
li
slli
lw
mv
andi
bge
or
j
and
addi

```
# SPIKE Testing
We will be using "Spike" which is a RISC-V simulator. An open-source instruction-set simulator (ISS) for the RISC-V architecture. The C-code will be first using RISC-64 tool chain and then simulated for different scenario's according to the application using SPIKE simulator.

Case-1
======
- The project is about a smart traffic light system which will ring the buzzer whenever a vehicle will break the traffic light. Case-1 is when the laser(input) will give 1 as input, which means vehicle is breaking the traffic light.

![laser1](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/bfd27dcb-f4b8-44af-9564-7233fa3bbd40)


- When red light is ON and the vehicle breaks the light, the buzzer is getting turned ON.
- When red & yellow light is ON and the vehicle breaks the light, the buzzer is getting turned ON.
- When yellow light is ON and the vehicle breaks the light, the buzzer is getting turned ON.
- When green light is ON the buzzer will be OFF.

Case-2
======
Case-1 is when the laser(input) will give 1 as input, which means vehicle is breaking the traffic light.

![laser_0](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/ff99bc09-4821-4da8-ac3a-4940df6395da)

- When red light is ON and no the vehicle breaks the light, the buzzer is OFF.
- When red & yellow light is NO and no vehicle breaks the light, the buzzer is OFF.
- When yellow light is ON and NO vehicle breaks the light, the buzzer is OFF.
- When green light is ON the buzzer will be OFF.

# Functionality Simulation

In Smart Traffic Light project, the input is LASER sensor which is always turned ON and monitoring if the vehicles are breaking the signal or not. The different cases for which laser will keep monitoring the the vehicles are,

1. RED LIGHT = ON
2. RED LIGHT = ON, YELLOW LIGHT = ON
3. YELLOW LIGHT = ON
4. GREEN LIGHT = ON (Laser will be ON the buzzer won't start)

![32regiter](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/e5133015-a404-4438-b957-4794bb8d2957)


- LASER (I/P) = 1
  ================

![GTK_lase1](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/5959b171-3b78-4cff-8a5f-f58cde300dec)

- LASER (I/P) = 0
  ================

![GTK_laser0](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/6c2eadd5-9f52-41fc-83af-d25945558452)

# Synthesis

Synthesis is the crucial process of translating a high-level RTL (Register-Transfer Level) design into a gate-level netlist that adheres to the designer's specifications. In simpler terms, it's the transformation of a conceptual design into a concrete chip design consisting of logic gates.

The synthesis process unfolds through several stages:

   - Initial transformation of RTL into a representation composed of basic logic gates.
   - Matching these basic gates to specific technology-dependent logic gates found in available libraries.
   - Refining and enhancing the mapped netlist while ensuring that it complies with the designer's constraints.

# Gate Level Simulation

Gate-Level Simulation (GLS) involves simulating a design by using a test bench with a netlist generated from the synthesis process as the Design Under Test (DUT). Since the netlist retains the same logical functionality as the original RTL code, the same test bench can be applied for verification purposes. This step serves the dual purpose of confirming the logical accuracy of the design after synthesis and ensuring that the design meets its specified timing requirements.

To achieve this, we can utilize the following commands in Yosys to convert RTL code to a netlist:

```
read_liberty -lib sky130_fd_sc_hd__tt_025C_1v80_256.lib 
read_verilog processor.v 
synth -top wrapper
dfflibmap -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib 
abc -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib
write_verilog synth_processor_test.v

```



  - Begin by transforming the RTL code into an equivalent gate-level netlist.
  - Then, conduct the simulation with the generated netlist to verify its logical correctness and meet timing constraints.

These commands facilitate the process of confirming that the synthesized design behaves as intended and satisfies the required timing constraints.

Folllowing are the commands to run the GLS simulation:

```
iverilog -o test synth_processor_test.v testbench.v sky130_sram_1kbyte_1rw1r_32x256_8.v sky130_fd_sc_hd.v primitives.v
```

When examining the gtkwave output for the netlist, it should ideally correspond to the output waveforms for the RTL design file. This alignment occurs because both the netlist and the original design code share the same set of input and output signals. Therefore, you can conveniently utilize the same testbench for simulation and directly compare the waveforms.

In essence, this allows you to ensure that the synthesized netlist faithfully reproduces the behavior of the RTL design, and any discrepancies between the waveforms can signal potential issues or differences between the two representations.

# LASER (i/p) = 1

![GLS_laser1](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/2a856c7b-846f-483f-a2d9-3e6a5ce3304a)


# LASER (i/p) = 0
---

![GLS_laser0](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/18520e25-d37e-481e-84ba-1143a56a777b)

# OPENLANE:

OpenLane is used as an open-source digital ASIC design pipeline that offers an automated and all-inclusive integrated circuit design solution. Its fully automated design cycle, which automates processes like synthesis, placement, routing, and optimization, is its main advantage. This helps to drastically cut down on the time and effort needed for complex ASIC design. The instrument is used in both research and teaching contexts and is made to be widely accessible, reducing obstacles for engineers and researchers. OpenLane is a useful platform for experimenting because of its flexibility for customization and integration with other open-source EDA tools. 

---
![Openlane_ASICflow](https://github.com/akul-star/Advanced-Physical-Design/assets/75561390/4a23a0b6-776c-42e0-ae25-eab6d2638929)

**Invoking OpenLANE**

```
cd OpenLane
make mount
```

Inside the openlane container:
```
./flow.tcl -interactive
package require openlane 0.9
prep -design picorv32a
```
![openlane_invoke](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/9ff5664e-7016-4ff2-982f-162bb77ed0e2)

Synthesis:
===========

In the RTL to GDS2 flow, synthesis is a crucial step where RTL (Register Transfer Level) code is transformed into a gate-level netlist. This process involves mapping RTL constructs to standard cell libraries, optimizing the design for area, power, and timing, handling clock domains, and applying timing constraints. Static Timing Analysis (STA) is then performed to ensure that the design meets timing requirements. Once synthesis is complete, the synthesized design serves as the foundation for subsequent steps in the flow, including physical design, placement, routing, and ultimately the generation of GDS2 files for fabrication. This synthesis stage plays a pivotal role in achieving a balance between design functionality and performance while preparing the design for manufacturing.

    A. **Liberty View (Liberty Format):**
        Purpose: Liberty view is used primarily for static timing analysis (STA) during the synthesis process. It provides information about the timing characteristics of standard cells from the cell library, such as setup times, hold                        times, rise/fall times, and capacitance values.
        Contents: It includes timing constraints, delay information, and other timing-related data for the cells in the standard cell library.
        Format: Typically written in a standard format called Liberty (.lib) format, which can be read by synthesis tools and STA tools.

    B. **HDL Behavioral View:**
        Purpose: The HDL (Hardware Description Language) Behavioral View represents the high-level description of the digital design in RTL (Register Transfer Level) or a higher abstraction level. It's the original RTL code created by                        designers.
        Contents: It contains behavioral descriptions of the logic functions, data paths, control structures, and the intended functionality of the design.
        Format: The format depends on the hardware description language used, such as VHDL or Verilog.

    C. **SPICE View (Simulation View):**
        Purpose: SPICE (Simulation Program with Integrated Circuit Emphasis) View is used for detailed transistor-level simulation. It provides a transistor-level representation of the design and is essential for accurate circuit-level                       simulations.
        Contents: SPICE View includes transistor-level models, parasitic elements, and detailed information about how the gates and interconnections in the design are implemented at the transistor level.
        Format: Typically written in a SPICE-compatible format (e.g., SPICE netlists) that can be used by circuit simulators for accurate transistor-level simulations.

To synthesize the code run the following command:
```
run_synthesis
```
![run_synth](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/cbb88756-621d-4081-8b03-722245f44da4)

**Synthesis Report:**

![run_synth_rpt](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/e8cbcbc9-a715-4a3c-acaa-ddbc6185efbc)

**Static Timing Analysis:**

![sta_log](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/b7609cf9-dbed-40b5-ba67-12133c738eec)

Floorpalnning
============



Floor Planning: Floor planning in the RTL to GDS2 (GDSII) flow is the initial step of physical design. It involves allocating space and defining the approximate locations of major components and functional blocks on the semiconductor chip. The goal is to create a layout that meets area, power, and performance targets while ensuring that signal routing between these blocks is feasible. Floor planning sets the foundation for subsequent steps like placement and routing and plays a crucial role in achieving a successful chip design.

A. Chip Floor Planning: Purpose: Chip floor planning is the high-level organization of the entire semiconductor chip. It defines the placement of major components and functional blocks on the chip's silicon die. Scope: It encompasses decisions related to core logic placement, I/O ring location, clock distribution, and other global aspects of the chip's physical design. Goals: The primary goals of chip floor planning are to optimize chip area, minimize power consumption, and ensure that the chip meets its performance requirements. It provides a high-level view of how different parts of the chip will interact.

B. Macro Floorplanning: Purpose: Macro floorplanning focuses on the placement and organization of large functional blocks or macros within the chip. These macros can include CPU cores, memory blocks, or other complex IP blocks. Scope: It deals with the internal layout and arrangement of these macros and how they interface with each other and the rest of the chip. Goals: The main objectives of macro floorplanning are efficient use of space, ensuring proper connectivity between macros, and optimizing for performance and power within the macro boundaries.

C. Power Planning: Purpose: Power planning is a critical aspect of chip design that focuses on managing and distributing power throughout the chip. It ensures that each component receives the required power supply and that power delivery is efficient to minimize voltage drop and power dissipation. Scope: Power planning involves decisions about the placement of power grid elements (such as power rails and decoupling capacitors) and the routing of power distribution networks. Goals: The key goals of power planning are to maintain voltage stability, reduce power noise, and meet power delivery requirements, all while minimizing the impact on chip area and performance. Effective power planning is essential for reliable chip operation and to avoid voltage drop-related issues.

Command to run Floorplanning:
```
run_floorplan
```

![run_floorplan](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/1ac8a91f-5fca-4491-ab68-f14c74994f3c)

A **.def** file will have been created in the **results/floorplan** directory following the floorplan run. By looking at the **floorplan.tcl**, we can review floorplan files. 
To see the layout of the floor, once in the results/floorplan directory, execute the following command to activate magic:

```
magic -T /home/nsaisampath/.volare/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def &
```
![magic_floorplan](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/baf3dccb-ceee-4a8b-b313-9bb4d8bd1e86)

Placement
=========


**Cell Placement:** Cell placement is a crucial step in the physical design of integrated circuits (ICs) within the RTL to GDS2 (GDSII) flow. It involves determining the specific locations on a semiconductor chip's silicon die where individual standard cells, macros, and other functional blocks will be positioned. 

   A. **Chip Floor Planning:**
        Purpose: Chip floor planning is the high-level organization of the entire semiconductor chip. It defines the placement of major components and functional blocks on the chip's silicon die.
        Scope: It encompasses decisions related to core logic placement, I/O ring location, clock distribution, and other global aspects of the chip's physical design.
        Goals: The primary goals of chip floor planning are to optimize chip area, minimize power consumption, and ensure that the chip meets its performance requirements. It provides a high-level view of how different parts of the chip will interact.

   B. **Macro Floorplanning:**
        Purpose: Macro floorplanning focuses on the placement and organization of large functional blocks or macros within the chip. These macros can include CPU cores, memory blocks, or other complex IP blocks.
        Scope: It deals with the internal layout and arrangement of these macros and how they interface with each other and the rest of the chip.
        Goals: The main objectives of macro floorplanning are efficient use of space, ensuring proper connectivity between macros, and optimizing for performance and power within the macro boundaries.

   C. **Power Planning:**
        Purpose: Power planning is a critical aspect of chip design that focuses on managing and distributing power throughout the chip. It ensures that each component receives the required power supply and that power delivery is efficient to minimize voltage drop and power dissipation.
        Scope: Power planning involves decisions about the placement of power grid elements (such as power rails and decoupling capacitors) and the routing of power distribution networks.
        Goals: The key goals of power planning are to maintain voltage stability, reduce power noise, and meet power delivery requirements, all while minimizing the impact on chip area and performance. Effective power planning is essential for reliable chip operation and to avoid voltage drop-related issues.

- Run the following command to run the placement:
```
run_placement
```
- To view the placement on Magic from **results/placement**:
```
 magic -T ~/.volare/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def &
```

![magic_placement](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/0df3edd3-5218-452e-9769-e476371c4685)

Clock Tree Synthesis:
=====================

**Clock Tree Sysnthesis:** CTS stands for "Clock Tree Synthesis." It is a crucial step in the physical design of integrated circuits, particularly digital designs, within the RTL to GDS2 (GDSII) flow. The primary goal of CTS is to create an efficient and optimized network of clock distribution paths throughout the chip.

The purpose of building a clock tree is enable the clock input to reach every element and to ensure a zero clock skew. H-tree is a common methodology followed in CTS. Following command is used to run CTS.

```
run_cts
```
- Timing Report

![cts_time_report](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/cf1a2f43-cf9f-4a9a-bfe4-e55a4c3deb83)

- Area Report

![cts_area_report](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/295ff02b-3c3d-44e2-b7e2-6b7e81f68d10)

- Skew Report

![cts_skew_report](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/e56fefc9-d235-495c-bd31-8e69c60d9926)

- Power Report

![cts_Power_report](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/dc2bcc48-d555-4d92-a672-072ce7ec963b)

Routing:
========

**Routing:** Routing, in the context of semiconductor chip design within the RTL to GDS2 (GDSII) flow, refers to the process of establishing physical connections between different components, such as standard cells, macros, and input/output pads, on the silicon die. These connections are created using metal layers, which serve as interconnects to facilitate data transmission and signal propagation. Grid routers are a type of routing algorithm used in semiconductor chip design within the context of the RTL to GDS2 (GDSII) flow. These routers are designed to navigate and establish connections between components on a chip layout using a grid-based approach. Grid routers are especially suitable for digital integrated circuits with a regular and structured layout, where the chip design is aligned with a grid pattern.

      A. Global Routing:  
Global routing is the initial phase of routing in chip design. It determines high-level routing paths for nets between macroblocks or functional units on the chip, focusing on channel assignments and chip-level optimization. The outcome is a routing framework or guides for subsequent detailed routing.

      B. Detailed Routing:
Detailed routing follows global routing and defines precise paths for individual wires within nets. It works at a lower, detailed level, considering cell positions, design rules, and minimizing wirelength. The result is the completed layout of physical interconnections, adhering to global routing guidelines.

Run the following command to run the routing:

```
run_routing
```

The layout can be viewed using MAGIC in **results/routing**:

```
 magic -T ~/.volare/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def &
```

![run_routing](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/616ede6e-6750-41c0-9aa4-c455222c1615)

Area of Design:

![run_routing_2](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/d21e43a5-bcdc-4d38-b50d-f0a9c077a0e9)


Post Routing Reports:

1. Timing:
![routing_timing_report](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/9aaa8a48-98c7-4ead-9f3d-3609a046c8ab)

2. Area:
![routing_area](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/fe4b9a8a-c019-4a02-a04e-e60e7a6ba51a)

3. Power:
![routing_power_report](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/a1bb506c-c81e-4694-b70a-361dd2a8f07a)

4. Design Rule Check (DRC)

![DRC_violations](https://github.com/akul-star/RISCV_SMART_TRAFFIC_LIGHT/assets/75561390/5d779e1a-9128-45e1-9c7b-fdfaad1fb29f)

VIDEO Explaination:
=================

https://drive.google.com/drive/folders/1t8aPpA8Nbcv6xlC-ckFEee0UGjgSLPUv?usp=sharing

# Acknowledgement

1. Kunal Ghosh, VSD Corp. Pvt. Ltd.
2. Skywater Foundry
3. Chatgpt
4. Shant Rakshit, Colleague, IIITB.
5. Emil Jayanth Lal, Colleague, IIITB.
   
