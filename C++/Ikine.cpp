/* Inverse Kinematic */
#include "Kinematics.h"

/* 别看了，这东西我自己看一遍都费劲 */
/* 不加注释的原因是不好加，绝对不是我懒 */
/* 虽然有重复的代码，但不要封装，这样跑起来快 */
double* ikine(double T[4][4])
{
	/* 关节角的声明与初始化 */
	double q1 = 0;	double q1_2 = 0;
	double q2 = 0;	double q2_2 = 0;
	double q3 = 0;	double q3_2 = 0;
	double q4 = 0;	double q4_2 = 0;
	/* 从位姿矩阵中取出有用的信息
	   到时候把姿态矩阵为单位阵，因为姿态是固定的
	   形参也要改一下，直接改成只储存坐标的数组 */
	double nz = T[2][0]; double oz = T[2][1];
	double px = T[0][3]; double py = T[1][3];
	double pz = T[2][3];

	q1 = atan2(py, px);
	q1_2 = atan2(-py, -px);
	/* 选择joint1的最小旋转角度q1 */
	if (fabs(q1) < fabs(q1_2)) {
		double k = px * cos(q1) + py * sin(q1);
		double t = pz - d1;
		double c3 = (k * k + t * t - a3 * a3 - a2 * a2) / (2 * a2 * a3);
		/* q3的最优解 */
		q3 = atan2(sqrt(1 - c3 * c3), c3);
		double m = a2 + a3 * cos(q3);
		double n = a3 * sin(q3);
		double s2 = (-k * n + t * m) / (n * n + m * m);
		double c2 = (k * m + t * n) / (m * m + n * n);
		q2 = atan2(s2, c2);

		q3_2 = atan2(-sqrt(1 - c3 * c3), c3);
		m = a2 + a3 * cos(q3_2);
		n = a3 * sin(q3_2);
		s2 = (-k * n + t * m) / (n * n + m * m);
		c2 = (k * m + t * n) / (m * m + n * n);
		q2_2 = atan2(s2, c2);

		if (fabs(q2) < fabs(q2_2)) {
			q4 = atan2(nz, oz) - q2 - q3; // 第1组关节角
		}
		else {
			q2 = q2_2;
			q3 = q3_2;
			q4 = atan2(nz, oz) - q2 - q3; // 第2组关节
		}
		

	}
	else {
		q1 = q1_2;

		double k = px * cos(q1) + py * sin(q1);
		double t = pz - d1;
		double c3 = (k * k + t * t - a3 * a3 - a2 * a2) / (2 * a2 * a3);

		q3 = atan2(sqrt(1 - c3 * c3), c3);
		q3_2 = atan2(-sqrt(1 - c3 * c3), c3);
		/* 这里没有进行第一步的优化，因为我还有一个问题没有解决(详见末尾注释)
		   目前我也不知道哪种更适合进一步的优化 */
		if (fabs(q3) < fabs(q3_2)) {
			double m = a2 + a3 * cos(q3);
			double n = a3 * sin(q3);
			double s2 = (-k * n + t * m) / (n * n + m * m);
			double c2 = (k * m + t * n) / (m * m + n * n);

			q2 = atan2(s2, c2);
			q4 = atan2(nz, oz) - q2 - q3; // 第3组关节角
		}
		else {
			q3 = q3_2;

			double m = a2 + a3 * cos(q3);
			double n = a3 * sin(q3);
			double s2 = (-k * n + t * m) / (n * n + m * m);
			double c2 = (k * m + t * n) / (m * m + n * n);

			q2 = atan2(s2, c2);
			q4 = atan2(nz, oz) - q2 - q3; // 第4组关节角
		}
	}
	
	static double q_group[] = { q1,q2,q3,q4 };
	/* 返回地址 */
	return q_group;
}

/* 现在有一个问题等待解决：
	我希望依据关节受力大小来选择最优解，显然顺序为q1->q4
	但在有的时候这并不是最优解
	比如关节2的旋转量从60°优化到45°
	但此时关节3需要多转120°
	我需要一个好的算法 */

