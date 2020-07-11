# 汇编 

### 分类
- 8089 (16bit)
- X86 (32bit)
- x64 (64bit)
    - intel
    - AT&T
- ARM

### 汇编语言2大知识点
- 1.汇编指令
- 2.寄存器

### 寄存器
- 通常，CPU会将内存中的数据存储到寄存器中，然后再对寄存器中的数据进行运算
- 假设内存中有块红色的内存空间值为3 现在
想把它值加一，并将结果存储到蓝色内存空间
    - CPU首先将红色内存空间值放到EAX寄存器中: `mov eax,红色内存空间`
    - 然后让exa寄存器与1相加 `add eax,1`
    - 然后将结果返回 `mov 蓝色内存空间,eax`
```
	int b = 10;
004417D8 C7 45 F8 0A 00 00 00 mov         dword ptr [ebp-8],0Ah  
	b += 10;
004417DF 8B 45 F8             mov         eax,dword ptr [ebp-8]  
004417E2 83 C0 0A             add         eax,0Ah  
004417E5 89 45 F8             mov         dword ptr [ebp-8],eax  
```
#### 常用寄存器
- 通用寄存器  64bit  (向下兼容  兼容32位 RAX 一半当作EAX  兼容16bit EAX 将自己变成2个AX) 
    - RAX  一般做函数返回值
    - RBX
    - RCX
    - RDX

    - RSP 栈指针
    - RBP 堆指针
- 32bit
    - EAX\EBX\ECX\EDX
- 16 bit
    - AX\BX\CX\DX
AX兼容8bit
AH H hight
AL L low
- 一般规律
    - R开头寄存器64bit 占8字节
    - E开头寄存器32bit 占4字节

#### 内联汇编
```cpp
__asm {
    mov eax,10H
    mov ebx,20H
}
```

### Base
- `move dest,src`  // ~= dest = src   (mov eax,dword ptr[1122H]去地址的存储空间 内容的转移)
- `[ 地址值 ]`  // 中括号里面的东西都是地址值
- word是2字节  dword是4字节(double word)  qword是8字节(quad word)
- `call 函数地址`
- `lea dest, [地址值]`  load effect address 地址值的转移 
- `ret` 函数返回 

#### base base
- `xor op1,op2` 将op1和op2异或的结果赋值给op1，类似op1=op1 ^ op2
- `add op1,op2` op1 = op1 + op2
- `sub op1,op2` op1 = op1 - op2
- `inc op`  increase 自增 op = op + 1
- `dec op` 自减
- `jmp 内存地址` jump 跳转到这个内存地址  (j 开头大多是带条件跳转 一般配合test或者cop等指令使用)
```
int a = 3;
mov dword ptr [ebp-?],3
int b = a + 3;
mov eax,a
add eax,3
mov dword ptr [ebp-?],eax


lea eax,[1122H]  // 直接将地址值 赋值给eax
mov eax,dword ptr [1122H] // 放这个地址 去dword 4个字节 
```

### 大小端模式
低字节的东西 放到地址比较低的地方  (大部分都是小端模式)

```cpp
    int a = 18;
00055524 C7 45 EC 12 00 00 00 mov         dword ptr [ebp-14h],12h  
	int b = 32;
0005552B C7 45 E0 20 00 00 00 mov         dword ptr [ebp-20h],20h  

	if (a == b)   // cmp  compare 比较
00055532 8B 45 EC             mov         eax,dword ptr [ebp-14h]  
00055535 3B 45 E0             cmp         eax,dword ptr [ebp-20h]  
00055538 75 0F                jne         00055549  // jne: jump no erqual
	{
		printf("a = b");
0005553A 68 DC 9B 05 00       push        59BDCh  
0005553F E8 D6 BE FF FF       call        0005141A  
00055544 83 C4 04             add         esp,4  
	}else
00055547 EB 0D                jmp         00055556  
	{
		printf("a != b");
00055549 68 E4 9B 05 00       push        59BE4h      //00055549
0005554E E8 C7 BE FF FF       call        0005141A  
00055553 83 C4 04             add         esp,4  
	}
        return 0;
00055556 33 C0                xor         eax,eax     // 00055556
}
```

#### 参考: 
- Intel白皮书
- 汇编金手指


### JCC (Jump Condition Code)
| 命令 | 解释 | 示例 |
|---- | ----| ----|
| JE,JZ (equal, zero) | 结果为零则跳转(相等时跳转) | ZF=1|
| JNE,JNZ (not equal,not zerp) | 结果不为零则跳转(不相等时跳转) |ZF=0 |
| JS(sign  有符号\无符号) | 结果为负则跳转 | SF=1 |
| JNS(not sign 无符号\无负号) |结果为负则跳转 | SF=0|
| JP,JPE (pariy odd) | 结果中有一个数为偶数则跳转 | PF=1 |
| JNP,JPO(parity odd) | 结果中1的个数为偶数则跳转 | PF=0 |
| JO (overflow) | 结果溢出则跳转 | OF=1 |
| JNO (not overflow) | 结果没有溢出则跳转 | OF=0 |
| JB,JNAE (below not above equal <) | 小于则跳转(无符号数) | CF=1 |
| JNB,JAE (not below above equal >=) | 大于等于则跳转(无符号数) | CF=1 |
| JBE,JNA (<=) | 小于等于则跳转(无符号数) | CF=1 or ZF=1 |
| JNBE,JA (>) | 大于则跳转(有符号数) | CF=0 and ZF=0 |
| JL,JNGE (<) | 小于则跳转(有符号数) | SD != OF |
| JLE,JNG (<=) | 小于等于则跳转有符号数)| ZF=1 or SF != OF |
| JNLE,JG (>) | 大于则跳转(有符号数)| SF=0 and SF=OF |


### 指针 引用汇编分析
```cpp
	int age = 3;
00AD4FC2 C7 45 F4 03 00 00 00 mov         dword ptr [ebp-0Ch],3  
	int* p = &age;
00AD4FC9 8D 45 F4             lea         eax,[ebp-0Ch]  
00AD4FCC 89 45 E8             mov         dword ptr [ebp-18h],eax  
	*p = 6;
00AD4FCF 8B 45 E8             mov         eax,dword ptr [ebp-18h]  
00AD4FD2 C7 00 06 00 00 00    mov         dword ptr [eax],6
```
##### 小试牛刀
```cpp
int a = 19;
int*p = &a;
*p += 20;
```
更具以上cpp写出其汇编代码
```cpp
mov dword ptr[ebp-10],19  // ebp-10 是假设

lea eax,[ebp-10]
mov dword ptr[ebp-20],eax  // int*p = &a

mov eax,dword ptr[ebp-20]   // 获取到p
mov ecx,dword ptr[eax]      // 获取*p的值
add ecx,20                  // ecx = 19 + 20
mov edx,dword ptr[ebp-20]   // 获取到p
mov dword ptr[edx],ecx      // *p = ecx
```