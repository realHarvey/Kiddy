#pragma once
#include <iostream>

/* 声明颜色变量 */
extern const int R;
extern const int G;
extern const int B;


class color_msg {  //颜色类
public:
	int* sequence = new int;
	int* setSequence(const int& color_a,
					 const int& color_b,
					 const int& color_c);

	~color_msg();
};

class position_msg { //坐标类
public:
	position_msg();

	void setPosition(double x,
				 	 double y,
					 double z);//扫描之后，写入坐标

	double position(); //读取坐标信息用于运算
private:
	double x; double y; double z;
};

class openmv_msgs : public color_msg, public position_msg {
public:
	/* 这里我是想把所有的消息都封装起来，但要兼顾模块化
	   所以我想着派生一个openmv_msg来继承color和position 
	   但是技术力不够，效率不高，我先去沉淀一段时间 */
};
