#include <sstream>
#include <fstream>

#include "ros/ros.h"
#include "std_msgs/String.h"

void writeToFile(const std_msgs::String::ConstPtr& msg) {
	

	//Acknowledge in console
	ROS_INFO("blackbox heard: %s", msg->data.c_str());

	/*TODO write msg->data.c_str() to file*/
	//creates log and opens log.dat
	std::ofstream ofs ("/home/parallels/log.dat", std::ios::app);
	ofs << msg->data.c_str() <<"\n";

	ofs.close();

}

int main(int argc, char** argv) {

	std::ofstream ofs ("/home/parallels/log.dat", std::ofstream::out);
	ofs << "log.dat\n";
	ofs << "BLACKBOX FILE FOR GUADALOOP HYPERLOOP POD\n\n";
	ofs.close();

	//initialize blackbox node
	ros::init(argc, argv, "blackbox");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("babble", 1000, writeToFile);

	ROS_INFO("blackbox initialized");

	ros::spin();
	return 0;
}