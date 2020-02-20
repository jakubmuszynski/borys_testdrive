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
