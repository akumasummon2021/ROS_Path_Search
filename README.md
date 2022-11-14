# ROS_Path_Search

pls following the steps to create a ROS workspace:

$ mkdir workspace/src

$ cd workspace/src

$ catkin_init_workspace

$ cd ..

$ catkin_make

$ source devel/setup.bash

$ cd src

$ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp

$ catkin_make

----------------------------------
then pls copy the source code files into the path: workspace/src/beginner_tutorials/src
copy the src/beginner_tutorials/cmakelist.txt in the git to the workspace/src/beginner_tutorials/

$ cd workspace

$ catkin_make

-----------------------------------
open a wsl shell/ubuntu, and run:

$ roscore

open a new wsl shell:

$ cd workspace

$ source ./devel/setup.bash

then can run the nodes:

$ rosrun beginner_tutorials talker_BFS

$ rosrun beginner_tutorials talker_DFS

$ rosrun beginner_tutorials talker_Dijkstra

the BFS/DFS/Dijkstra using the Code from the challenage 1 and 2
