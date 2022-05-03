% 正运动计算
function TFkine = kiddy_fkine(theta)

theta1 = theta(1); theta2 = theta(2); theta3 = theta(3); theta4 = theta(4);
d1 = 86; a2 = 135; a3 = 89; 

% c1 = cos(theta1);    s1 = sin(theta1);
% c2 = cos(theta2);    s2 = sin(theta2);
% c3 = cos(theta3);    s3 = sin(theta3);
% c4 = cos(theta4);    s4 = sin(theta4);
% 
% T01 = [c1   -s1     0    0;s1    c1     0    0;0     0      1    d1;0     0      0    1];
% T12 = [c2   -s2     0    0;0     0      -1    0;s2    c2     0    0;0     0      0    1];
% T23 = [c3   -s3     0    a2;s3    c3     0    0;0     0      1    0;0     0      0    1];
% T34 = [c4   -s4     0    a3;s4    c4     0    0;0     0      1    0;0     0      0    1];
% t_fkine = T01 *T12 *T23 *T34;

%优化方案，避免了一些重复运算
nx = cos(theta2 + theta3 + theta4)*cos(theta1);
ox = -sin(theta2 + theta3 + theta4)*cos(theta1);
ax =  sin(theta1);
ny = cos(theta2 + theta3 + theta4)*sin(theta1);
oy = -sin(theta2 + theta3 + theta4)*sin(theta1);
ay = -cos(theta1);
nz = sin(theta2 + theta3 + theta4);
oz = cos(theta2 + theta3 + theta4);
az = 0;
px = cos(theta1)*(a3*cos(theta2 + theta3) + a2*cos(theta2));
py = sin(theta1)*(a3*cos(theta2 + theta3) + a2*cos(theta2));
pz = d1 + a3*sin(theta2 + theta3) + a2*sin(theta2);

TFkine = [nx ox ax px;
          ny oy ay py;
          nz oz az pz;
           0  0  0  1];

end
