#include "../include/testdrive.h"

void SigintHandler(int sig)
{
  ROS_INFO_STREAM("Test Drive Node Is Shutting Down");
  // Stopping everything
  throttleMsg.data = 0;
  rotationMsg.data = 0;
  throttlePub.publish(throttleMsg);
  rotationPub.publish(rotationMsg);
  shutdown();
}

void vehicleStartup()
{
  ROS_INFO_STREAM("Initiating startup sequence");
  for(int i = 0; i < 20; i++)
  {
    throttleMsg.data = throttleMsg.data + 1;
    throttlePub.publish(throttleMsg);
    Duration(0.2).sleep();
  }
  ROS_INFO_STREAM("Vehicle reached set speed");
}

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  // 0 - lewa galka, lewo/prawo
  // 1 - lewa galka, gora/dol
  // 3 - prawa galka, lewo/prawo
  // 4 - prawa galka, gora/dol
  
  rotationMsg.data = (float)(joy->axes[0]) * 256;
  rotationPub.publish(rotationMsg);

  throttleMsg.data = (float)(joy->axes[1]) * 256;
  throttlePub.publish(throttleMsg);
}
