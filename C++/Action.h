#pragma once
#include <iostream>
#include "OpenmvMsgs.h"

position_msg target_search(int target,
	int desk)
{
	color_msg color_target; // 二维码_抓取顺序
	color_target.setSequence(G, B, R);
	color_msg color_desk; // 原料区_摆放顺序
	color_desk.setSequence(R, G, B);

	position_msg R_desk; // 原料区_色块坐标_设置
	R_desk.setPosition(100, -100, 50);
	position_msg G_desk;
	G_desk.setPosition(100, 0, 50);
	position_msg B_desk;
	B_desk.setPosition(100, 100, 50);

	int times_catch = 1;
	for (times_catch; times_catch <= 3; times_catch++) {
		int _target_seq = 0;
		for (_target_seq; _target_seq < 3; _target_seq++) {
			int _desk_seq = 0;
			for (_desk_seq; _desk_seq < 3; _desk_seq++) {

				if (color_target.sequence[_target_seq] == color_desk.sequence[_desk_seq]) {
					// 获取位置
					return R_desk, G_desk, B_desk;
				}
			}
		}
	}
}
