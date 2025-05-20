#include "ros/ros.h"
#include "std_msgs/String.h"

// コールバック関数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // ノード初期化
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  // サブスクライバ作成
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  // コールバックを繰り返し呼ぶ
  ros::spin();

  return 0;
}
