#include "OpenmvMsgs.h"


/* 当移动到desk */
/* 搜寻对应的target -> 获取坐标 -> 执行运动组 */


/* 定义 R G B ->  0 1 2 ,方便switch调用 */
const int R = 0;
const int G = 1;
const int B = 2;

/* color_msg */
int* sequence = new int; 

int* color_msg::setSequence(const int& color_a,
							const int& color_b,
							const int& color_c)
{
	sequence[0] = color_a;
	sequence[1] = color_b;
	sequence[2] = color_c;

	return sequence;
}

color_msg::~color_msg()
{
	delete[] sequence;
}


/* position_msg */
position_msg::position_msg()
{
	x = 0; y = 0; z = 0;
}
void position_msg::setPosition(double x,
							   double y,
							   double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double position_msg::position()
{
	return x, y, z;
}

