#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcaster");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform_RK1;
  tf::Transform transform_RK2;
  tf::Transform transform_RK3;
  tf::Transform transform_RK4;
  ros::Rate rate(10.0);
  while (node.ok()){
    transform_RK1.setOrigin( tf::Vector3(0.85, 0.05, 0.1));
    // (x,y,z,w)
    // placing the tag near world and cam to tag
    //transform_RK1.setRotation( tf::Quaternion(0.999, -0.007, 0.004, 0.041));
    transform_RK1.setRotation( tf::Quaternion(0, 0, 0, 1));
  //  transform_RK1.setRotation( tf::Quaternion(0.999, -0.007, -0.001, -0.039));
//    transform_RK4.setOrigin( tf::Vector3(0.065, -0.189, 1.363));

    transform_RK2.setOrigin( tf::Vector3(-0.7, -0.305, 0.38));
    transform_RK2.setRotation( tf::Quaternion(0, 0, 0, 1));


    transform_RK3.setOrigin( tf::Vector3(0.035, -0.9, 0.22));
    transform_RK3.setRotation( tf::Quaternion(0, 0, 0, 1));

//    transform_RK4.setOrigin( tf::Vector3(-0.220, 0.014, 1.250));
//    transform_RK4.setOrigin( tf::Vector3(-0.10, 0.014, 0.97));    
   transform_RK4.setOrigin( tf::Vector3(-0.157, 0.081, 1.244));
    // transform_RK4.setOrigin( tf::Vector3(-0.962, 0.157, -0.016));
    transform_RK4.setRotation( tf::Quaternion(0.514, 0.740, 0.320, 0.293));
//    transform_RK4.setRotation( tf::Quaternion(0.742, 0.671, 0.006, -0.009));        
  
    br.sendTransform(tf::StampedTransform(transform_RK1, ros::Time::now(), "world", "usb_cam2"));
    br.sendTransform(tf::StampedTransform(transform_RK2, ros::Time::now(), "world", "usb_cam4"));
    br.sendTransform(tf::StampedTransform(transform_RK3, ros::Time::now(), "world", "usb_cam3"));
    br.sendTransform(tf::StampedTransform(transform_RK4, ros::Time::now(), "world", "usb_cam1"));
    rate.sleep();
  }
  return 0;
};