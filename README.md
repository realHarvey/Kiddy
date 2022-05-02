# Robot-Arm-4dof
一只四自由度的机械臂，我就叫它 kiddy 吧     
a 4-dof robotic arm, I call him 'kiddy', is this name funny?

  
  
以下是matlab代码目录：
the MULU of my matlab code:
    

1.建立在RTS中的D-H模型 the D-H model built in Robotic Toolbox       
2.正运动学解   forward kinematics         
3.逆运动学解   inverse kinematics      
4.轨迹规划  trajectory planning       
5.动力学解  dynamics      
6.一些注意事项  some notice       
  
     
修改日志：    
懒得翻译了，要看自己查去
  
--2022/4/23   
      简化D-H模型的参数
           
--2022/5/2    
      将rotation matrix的subelements表示法 改成 n o a表示法 。
 末端执行器沿着操作端的z-axis接近被操作物体，此时这个轴被称为接近轴a-axis （approach）；末端执行器接近物体的方向称为方向轴，简称o-axis（orientation）；垂直于a和o的为垂直轴n-axis。
 
 
 
 
 
 
