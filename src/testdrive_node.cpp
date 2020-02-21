#include "../include/testdrive.h"
#include "testdrive_library.cpp"

int main(int argc, char** argv)
{
  init(argc, argv, "testdrive", init_options::NoSigintHandler);
  NodeHandle n;
  ROS_INFO_STREAM("Test Drive Node Is Up");
  Subscriber joySub = n.subscribe<sensor_msgs::Joy>("joy", 1, joyCallback);
  throttlePub = n.advertise<std_msgs::Int16>("throttle", 1);
  rotationPub = n.advertise<std_msgs::Int16>("rotation", 1);

  signal(SIGINT, SigintHandler);
  Rate rate(30); // 30Hz

  // Vehicle startup sequence
  //vehicleStartup();

  throttleMsg.data = 0;

  while (ok())
  {
    throttlePub.publish(throttleMsg);
    rotationPub.publish(rotationMsg);

    rate.sleep();
    spinOnce();
  }
  return 0;
}
