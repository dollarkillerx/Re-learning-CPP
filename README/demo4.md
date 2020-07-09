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