clear;clc;close all;
% 模型初始化

angle = pi/180; % 将degs转为rads
d1 = 86; a2 = 135; a3 = 89; % 三根连杆的长度

%           theta     d      a     alpha
L(1) = Link([ 0       d1     0      0 ],   'modified');
L(1).qlim = [-180*angle,180*angle]; % 关节极限

L(2) = Link([ 0       0      0   pi/2 ], 'modified'); 
L(2).qlim = [-180*angle,180*angle]; L(2).offset = 90*angle;
% 注意：定义好关节类型后，相应的变量必须为0，初值必须由offset定义

L(3) = Link([ 0       0      a2     0 ],   'modified'); 
L(3).qlim = [0*angle,270*angle]; L(3).offset = -135*angle;

L(4) = Link([ 0       0      a3     0 ],  'modified');
L(4).qlim = [-135*angle,45*angle]; L(4).offset = 45*angle;

kiddy = SerialLink(L,'name','Kid'); %连接各连杆
kiddy.display() % 显示机械臂的D-H参数
kiddy.dyn % 动力学参数(目前我们所用的舵机以及开环的步进都没有办法实现力和力矩的规划，动力学部分请期待我以后的作品吧)

% 验证正逆运动学function的正确性
q0 = [pi/6,pi/4,pi/6,pi/6];
T = kiddy_fkine(q0);
rads = kiddy_ikine(T);
rad2deg(rads);
T1 = kiddy_fkine([ 0.5236 ,  0.7854  ,  0.5236  ,   0.5236]);
T2 = kiddy_fkine([ 0.5236 ,  1.1991  , -0.5236  ,   1.1571]);
T3 = kiddy_fkine([-2.6180 ,  1.9425  ,  0.5236  ,  -0.6335]);
T4 = kiddy_fkine([-2.6180 ,  2.3562  , -0.5236  ,  -0.0000]);

% 蒙特卡洛法对手臂的工作空间进行可视化
num = 50000;
P = zeros(num, 3); % 创建一个 num行3列 的矩阵

for i = 1:num
    q1 = L(1).qlim(1) + rand * ( L(1).qlim(2) - L(1).qlim(1) ); % ti时点的第一个关节角 = 关节最小角 + 随机数(0,1) * 关节弯曲极限
    q2 = L(2).qlim(1) + rand * ( L(2).qlim(2) - L(2).qlim(1) );
    q3 = L(3).qlim(1) + rand * ( L(3).qlim(2) - L(3).qlim(1) );
    q4 = L(4).qlim(1) + rand * ( L(4).qlim(2) - L(4).qlim(1) );
    
    q = [q1 q2 q3 q4]; % ti时点的全部关节角
    T = kiddy_fkine(q); % ti时点的位置矩阵
    P(i, :) = transl(T); % 通过50000次循环，把每次求得的position记录到P阵里
end

plot3(P(:,1),P(:,2),P(:,3),'b.','markersize',1) % 开始榨干P阵
hold on
grid on
