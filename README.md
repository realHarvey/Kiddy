# Robot-Arm-4dof
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
懒得翻译了，要看自己查去
  
--2022/4/23   
      简化D-H模型的参数
           
--2022/5/2    
      将rotation matrix的subelements表示法 改成 n o a表示法 。
 末端执行器沿着操作端的z-axis接近被操作物体，此时这个轴被称为接近轴a-axis （approach）；末端执行器接近物体的方向称为方向轴，简称o-axis（orientation）；垂直于a和o的为垂直轴n-axis。
       
--2022/5/3        
      在使用中我遇到一个问题：我们使用或得到的rad往往并不是四个单独的rad，而是一个rad组。为了方便后续使用，把正运动函数中输入的变量 由四个单独的rads 改为 一个合并的rad，该 rad = [rad1,rad2,rad3,rad4]
      
      
--2022/5/24          
      创建"ROS基本框架"，添加 制作Kiddy的规划大致方案 && 有关ROS的知识结构图
      制作方案是下面这张图：                 
      图的左边是基于单片机的方案一-->好处: 实时性比较高; 缺点: 底层算法和代码全靠自己解和敲；拓展性差，基本上也只能做这些功能了。                   
      图的右边是基于树莓派的方案二-->好处: 内置了很多底层的算法，可以直接调用；拓展性高，未来可以升级很多的功能; 缺点: 需要有大量的知识储备，学习周期长; 实时性比较低，需要屏蔽掉一个核专门用来做实时计算 。    
        我目前正在学习ROS的机器人编程，所以上面方案一的轨迹规划等我暑假的时候继续更。动力学部分可能得等我考完研再说了，现在没有时间，手头上也没有支持动力反馈的电机。
           
 <img width="997" alt="无标题" src="https://user-images.githubusercontent.com/78713753/170242655-f039e6d6-533d-49e1-9a92-79daf0ce4821.png">

 
 
