#pragma once  // ��ֹ����ļ����ظ�����  (������  ���ϵı�������֧��)

//int sum(int v1, int v2);
//int delta(int v1, int v2);

// #define __cplusplus CPP����Ĭ���� __cplusplus��

#ifndef __MATH_H  // ��ֹ�ظ����� ������ñ�Ƿ�
	// ����ĺ� һ�����»���  __�ļ�����.H ȫ����д
#define __MATH_H // ����һ�����÷���ʱ �趨���ñ�Ƿ�


#ifdef __cplusplus  // ���������__cplusplus �ͻ�ѵ��еĴ���������
extern "C" {
#endif

	int sum(int v1, int v2);
	int delta(int v1, int v2);

#ifdef __cplusplus
}
#endif

#endif
