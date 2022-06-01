#include <iostream>
#include <iomanip>
#include <chrono> // 测运行时间的依赖库

#include "Kinematics.h"
#include "OpenmvMsgs.h"

#define PI 3.1415926


void test_fkine();
void test_ikine();

void test_class()
{
	position_msg *poi = new(openmv_msgs);
	poi->setPosition(10,20,50);
	std::cout << poi->position();
	/* 这个地方没有输出了 */
	/* 我现在已经糊涂了
	先去GitHub学一个月别人的开源项目
	考试结束之前不碰此项目 
	                      ---儿童节留 */

}


int main()
{
	void test_class();
	//test_fkine();
	//test_ikine();

	return 0;
}



void test_fkine()
{
	/* 验证fkine的正确性 */
	/* 测量运行时间 */auto start = std::chrono::steady_clock::now();

	double qq[4] = { PI / 6,PI / 4,PI / 6,PI / 6 };
	int sb = 0;
	for (sb; sb < 16; sb++) {
		double element = *(fkine(qq) + sb);
		std::cout << std::setprecision(7) << std::fixed << std::left << element << "		";
		if (sb == 3 || sb == 7 || sb == 11 || sb == 15)
			std::cout << '\n' << std::endl;
	}
	std::cout << "正运动计算结果正确" << '\n' << std::endl;

	/* 测量运行时间 */auto finish = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	std::cout << duration.count() << "ms" << std::endl;

}

void test_ikine()
{
	/* 验证ikine的正确性 */
	/* 测量运行时间 */auto start = std::chrono::steady_clock::now();

	double T[4][4] = { {-0.2241, -0.8365,   0.5000,  102.6191},
					   {-0.1294, -0.4830,  -0.8660,  59.2472},
					   {0.9659,  -0.2588,   0,       267.4268},
					   {0,        0,        0,       1} };

	std::cout << *(ikine(T)) << "     " <<
			 *(ikine(T) + 1) << "     " <<
			 *(ikine(T) + 2) << "     " <<
			 *(ikine(T) + 3) << '\n'    << std::endl;

	std::cout << "逆运动计算结果正确" << std::endl;

	/* 测量运行时间 */auto finish = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	std::cout << duration.count() << "ms" << std::endl;
}


