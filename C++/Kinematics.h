#pragma once
#include <iostream>
#include <cmath>

/* 连杆常量声明 */
extern const int d1;
extern const int a2;
extern const int a3;


/* 正运动函数声明 */
double* fkine(double* q);

/* 逆运动函数声明 */
double* ikine(double T[4][4]);

/* 返回值都是地址，取值用地址偏移就行了 */
