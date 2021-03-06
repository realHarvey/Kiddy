% 逆运动解算
function ikm = kiddy_ikine(T)

syms theta1 theta2 theta3 theta4
d1 = 86; a2 = 135; a3 = 89;
% 输入代换：
% nx = T(1,1); ox = T(1,2); ax = T(1,3); px = T(1,4);
% ny = T(2,1); oy = T(2,2); ay = T(2,3); py = T(2,4);
% nz = T(3,1); oz = T(3,2); az = T(3,3); pz = T(3,4);
%其中有些量是用不上的，可以简化：
nz = T(3,1); oz = T(3,2); px = T(1,4); py = T(2,4); pz = T(3,4);

% 第一组解
%theta1
theta1_1 = atan2(py,px);
%theta3 -power(,2)
p = px*cos(theta1_1)+py*sin(theta1_1);
q = pz - d1; %简化运算
c3 = (p*p + q*q - a3*a3 - a2*a2)/(2*a2*a3);
theta3_1 = atan2(sqrt(1 - c3*c3),c3);
theta3_2 = atan2(-sqrt(1 - c3*c3),c3);
%theta2
m = a2 + a3*cos(theta3_1);n = a3*sin(theta3_1);
s2 = (-p*n + q*m)/(n*n + m*m);
c2 = (p*m + q*n)/(m*m + n*n);
theta2_1 = atan2(s2,c2);
m = a2 + a3*cos(theta3_2);n = a3*sin(theta3_2);
s2 = (-p*n + q*m)/(n*n + m*m);
c2 = (p*m + q*n)/(m*m + n*n);
theta2_2 = atan2(s2,c2);
%theta4
theta4_1 = atan2(nz,oz) - theta2_1 - theta3_1;
theta4_2 = atan2(nz,oz) - theta2_2 - theta3_2;

% 另一组解
%theta1
theta1_2 = atan2(-py,-px);
%theta3
p = px*cos(theta1_2)+py*sin(theta1_2);
q = pz - d1; %简化运算
c3 = (p*p + q*q - a3*a3 - a2*a2)/(2*a2*a3);
theta3_3 = atan2(sqrt(1 - c3*c3),c3);
theta3_4 = atan2(-sqrt(1 - c3*c3),c3);
%theta2
m = a2 + a3*cos(theta3_3);n = a3*sin(theta3_3);
s2 = (-p*n + q*m)/(n*n + m*m);
c2 = (p*m + q*n)/(m*m + n*n);
theta2_3 = atan2(s2,c2);
m = a2 + a3*cos(theta3_4);n = a3*sin(theta3_4);
s2 = (-p*n + q*m)/(n*n + m*m);
c2 = (p*m + q*n)/(m*m + n*n);
theta2_4 = atan2(s2,c2);
%theta4
theta4_3 = atan2(nz,oz) - theta2_3 - theta3_3;
theta4_4 = atan2(nz,oz) - theta2_4 - theta3_4;

%如果想把两组解融合（即把theta1_1和theta1_2,theta2_1 theta2_2 theta2_3 theta2_4.....写到一起去），要注意重复定义问题
%比如18、19行的值 和40、41行是不同的，合并起来的时候要特别注意
%不过我还是建议把两组解分开写，看起来可能会更直观一些

%把这几组解组合在一起
ikm = [theta1_1,theta2_1,theta3_1,theta4_1;
       theta1_1,theta2_2,theta3_2,theta4_2;
       theta1_2,theta2_3,theta3_3,theta4_3;
       theta1_2,theta2_4,theta3_4,theta4_4];

end
