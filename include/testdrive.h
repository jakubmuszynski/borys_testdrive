#ifndef testdrive_h
#define testdrive_h

#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "std_msgs/UInt16.h"
#include <iostream>
#include <stdio.h>
#include <signal.h>

using namespace std;
using namespace ros;

std_msgs::UInt16 throttleMsg;
std_msgs::UInt16 rotationMsg;

Publisher throttlePub, rotationPub;

void SigintHandler(int sig);
void vehicleStartup();

#endif
