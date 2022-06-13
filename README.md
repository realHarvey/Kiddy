# Kiddy
一只四自由度的机械臂，我就叫它 kiddy 吧     
a 4-dof robotic arm, I call him 'kiddy', is this name funny?

  
===============================================================
  
以下是matlab代码目录：
the MULU of my matlab code:
    

1.建立在RTS中的D-H模型 the D-H model built in Robotic Toolbox       
2.正运动学解   forward kinematics         
3.逆运动学解   inverse kinematics      
4.轨迹规划  trajectory planning       
5.动力学解  dynamics      
6.一些注意事项  tips       
  
     
===============================================================    
         
修改日志：    

  
--2022/4/23   
      简化D-H模型的参数
           
--2022/5/2    
      将rotation matrix的subelements表示法 改成 n o a表示法 。
 末端执行器沿着操作端的z-axis接近被操作物体，此时这个轴被称为接近轴a-axis （approach）；末端执行器接近物体的方向称为方向轴，简称o-axis（orientation）；垂直于a和o的为垂直轴n-axis。
       
--2022/5/3        
      在使用中我遇到一个问题：我们使用或得到的rad往往并不是四个单独的rad，而是一个rad组。为了方便后续使用，把正运动函数中输入的变量 由四个单独的rads 改为 一个合并的rad，该 rad = [rad1,rad2,rad3,rad4]        
           
 <img width="997" alt="无标题" src="https://user-images.githubusercontent.com/78713753/170242655-f039e6d6-533d-49e1-9a92-79daf0ce4821.png">

 --2022/5/25    
      添加Kiddy的三维模型（IGS格式，常规的CAD都可以打开，但是不能删除，Fusion是特例）
      
--2022/6/1    
      添加图像处理、动作处理、正逆运动学的部分代码雏形
 
