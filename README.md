# borys_testdrive
ROS Melodic \
rosserial \
joy

# controller
source devel/setup.bash \
rosrun joy joy_node

# arduino
source devel/setup.bash \
sudo chmod a+rw /dev/ttyACM0 \
rosrun rosserial_python serial_node.py /dev/ttyACM0

# ROS node
source devel/setup.bash \
rosrun borys_testdrive testdrive_node
