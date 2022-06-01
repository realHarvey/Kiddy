/* Forward Kinematic */
#include "Kinematics.h"

/* 连杆常量定义 */
const int d1 = 86;
const int a2 = 135;
const int a3 = 89;

/* 正运动函数定义 */
double* fkine(double* q)
{
	double q1 = q[0]; double q2 = q[1];
	double q3 = q[2]; double q4 = q[3];

	/* 正运动计算 */
	double nx = cos(q2 + q3 + q4) * cos(q1);
	double ox = -sin(q2 + q3 + q4) * cos(q1);
	double ax = sin(q1);

	double ny = cos(q2 + q3 + q4) * sin(q1);
	double oy = -sin(q2 + q3 + q4) * sin(q1);
	double ay = -cos(q1);

	double nz = sin(q2 + q3 + q4);
	double oz = cos(q2 + q3 + q4);
	double az = 0;

	double px = cos(q1) * (a3 * cos(q2 + q3) + a2 * cos(q2));
	double py = sin(q1) * (a3 * cos(q2 + q3) + a2 * cos(q2));
	double pz = d1 + a3 * sin(q2 + q3) + a2 * sin(q2);

	/* 赋值给输出矩阵 */
	static double Tfkine[4][4] = { 0 };

	Tfkine[0][0] = nx; Tfkine[0][1] = ox; Tfkine[0][2] = ax; Tfkine[0][3] = px;

	Tfkine[1][0] = ny; Tfkine[1][1] = oy; Tfkine[1][2] = ay; Tfkine[1][3] = py;

	Tfkine[2][0] = nz; Tfkine[2][1] = oz; Tfkine[2][2] = az; Tfkine[2][3] = pz;

	Tfkine[3][0] = 0;  Tfkine[3][1] = 0;  Tfkine[3][2] = 0;	 Tfkine[3][3] = 1;

	/* 返回首个子数组的首地址 */
	return Tfkine[0];

}
