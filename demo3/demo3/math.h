#pragma once  // 防止这个文件被重复包含  (局限性  较老的编译器不支持)

//int sum(int v1, int v2);
//int delta(int v1, int v2);

// #define __cplusplus CPP环境默认有 __cplusplus宏

#ifndef __MATH_H  // 防止重复引用 检测引用标记符
	// 特殊的宏 一般用下划线  __文件名称.H 全部大写
#define __MATH_H // 当第一次引用发生时 设定引用标记符


#ifdef __cplusplus  // 如果定义了__cplusplus 就会把当中的代码参与编译
extern "C" {
#endif

	int sum(int v1, int v2);
	int delta(int v1, int v2);

#ifdef __cplusplus
}
#endif

#endif
